#include <stdio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

// only one command is passed

int main(int argc, char *argv[])
{
    // if first argument (command) is NULL. prompt the user to enter a command
	if(argv[1] == NULL)
	{
		printf("Enter a command \n");

	}

	// an array of string to store the command with options
	// eg. ls is the command -lt is the options
	char *command[argc];


    for (int i = 0; i < argc; i++)
    {
        command[i] = argv[i+1];
    }

    command[argc-1] = NULL;

    // the name of the shared memory is named as MyMem
    int FD = shm_open("MyMem", O_CREAT | O_RDWR, 0666);  // create shared memory object

	// FD should contain the data of type struct timeval
	// ftruncate will truncate the memory size to the size specified as the second argument.
	ftruncate(FD,sizeof(struct timeval));

	char *ptr;  // shared memory pointer

	// to record the timetaken to execution of a command
    double timeTaken;

    // pointer to the shared memory so as to read and write using this.
    ptr = (char *)mmap(0, sizeof(struct timeval), PROT_READ | PROT_WRITE, MAP_SHARED, FD, 0);

    // to record the time before the execution of command
    struct timeval start;

    // to record the time after execution of command.
    struct timeval end;

	// process identifier variable
    pid_t pid;

    // fork a child
    pid = fork();

    if( pid < 0 )  // Error in creating a child process
    {
        printf("FORK FAILED...!");
        exit(EXIT_FAILURE);

    }else if( pid == 0)  // child process
    {
        // record the time and store it in the start
        gettimeofday(&start, NULL);

        // write it to the shared memory the current time
        sprintf(ptr, "%ld %ld", start.tv_sec, start.tv_usec);

        // execute the command along with options
        execvp(command[0], command);

    }
    else   // pid > 0 // parent proces
    {
        // wait for the child process to finish/terminate execution.
        wait(NULL);

        // record to time just after finish of the child process.
        gettimeofday(&end, NULL);

        // read from the shared pointer and write it the start variable
        sscanf(ptr, "%ld %ld", &(start.tv_sec), &(start.tv_usec));

        // to calculate the time taken.
        timeTaken = (end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec)/1000000.0;
        printf("Elapsed time: %lf seconds\n",timeTaken);
    }

    // unmap the start and end if any.
     munmap(&start, sizeof(start));
     munmap(&end, sizeof(end));

     // unlink the 'MyMem' shared memory object
     // if it returns -1 error in unlinking
    if ( shm_unlink("MyMem") == -1 )
    {
        printf("Error in unlinking the shared memory: ");
    }

    return 0;
}
