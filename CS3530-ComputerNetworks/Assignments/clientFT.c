#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include<ctype.h>

int main(int argc, char **argv) {

	if (argc != 3) {
		perror("<Server Address> <Server Port>");
		exit(-1);
	}

	char *servIP = argv[1];

	// Set port number as given by user or as default 12345
	// in_port_t servPort = (argc == 3) ? atoi(argv[2]) : 12345;

	// Set port number as user specifies
	in_port_t servPort = atoi(argv[2]);

	//Create a socket
	int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd < 0) {
		perror("socket() failed");
		exit(-1);
	}

	// Set the server address
	struct sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	int err = inet_pton(AF_INET, servIP, &servAddr.sin_addr.s_addr);
	if (err <= 0) {
		perror("inet_pton() failed");
		exit(-1);
	}

	// htons - host to network short.
	// stores in 16 bit
	// little endian to big endian conversion
	servAddr.sin_port = htons(servPort);

	// Connect to server
	if (connect(sockfd, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
		perror("connect() failed");
		exit(-1);
	}

	FILE *f;
	int Words_inFile;

	char c;

	char buffer[255];

    bzero(buffer, 255);
	f = fopen("file1.txt","r");

	while( (c = getc(f)) != EOF )
	{
	   fscanf(f, "%s", buffer);
	   if( isspace(c) || c == '\t')
       {
           Words_inFile++;
       }
	}

	// sending the server the count of words in the file
	// write(sockfd, &Words_inFile, sizeof(int));

	write(sockfd, &Words_inFile, sizeof(int));


	// take the file pointer back to the start of file
	rewind(f);

	char ch;

	while(ch != EOF )
    {
        fscanf(f, "%s", buffer);
        write(sockfd, buffer, 255);

        send(sockfd, buffer, strlen(buffer) , 0);

        ch = fgetc(f);
    }

	printf("File Sent ! -- from client\n");


	close(sockfd);
	exit(0);
}
