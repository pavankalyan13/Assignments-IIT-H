#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include<unistd.h>

static const int MAXPENDING = 30; // Maximum outstanding connection requests

int main(int argc, char ** argv) {

	if (argc != 2) {
		perror("<server port>");
		exit(-1);
	}

	// converts the port number from string to integer
	in_port_t servPort = atoi(argv[1]); // Local port

	// create socket for incoming connections
	int servSock;
	if ((servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		perror("socket() failed");
		exit(-1);
	}

	// Set local parameters
	struct sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(servPort);

	// Bind to the local address
	if (bind(servSock, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
		perror("bind() failed");
		exit(-1);
	}

	// Listen to the client
	if (listen(servSock, MAXPENDING) < 0) {
		perror("listen() failed");
		exit(-1);
	}

	// Server Loop
	for (;;) {
		struct sockaddr_in clntAddr;
		socklen_t clntAddrLen = sizeof(clntAddr);

		// Wait for a client to connect
		int clntSock =
				accept(servSock, (struct sockaddr *) &clntAddr, &clntAddrLen);
		if (clntSock < 0) {
			perror("accept() failed");
			exit(-1);
		}

		// this will give some notice to the command line
		char clntIpAddr[INET_ADDRSTRLEN];
		if (inet_ntop(AF_INET, &clntAddr.sin_addr.s_addr,
				clntIpAddr, sizeof(clntIpAddr)) != NULL) {
			printf("----\nHandling client %s %d\n",
					clntIpAddr, ntohs(clntAddr.sin_port));
		} else {
			puts("----\nUnable to get client IP Address");
		}

		// Receive data
		char buffer[255];
		memset(buffer, 0, 255);


		/* ssize_t recvLen = recv(clntSock, buffer, BUFSIZE - 1, 0);
		if (recvLen < 0) {
			perror("recv() failed");
			exit(-1);
		}
		buffer[recvLen] = '\n';
		fputs(buffer, stdout);

		*/

		FILE *f;

		int cnt = 0;

		f = fopen("File1INServer.txt", "a");

		int wordsInFile;

		read(clntSock, wordsInFile, sizeof(int));

		while(cnt != wordsInFile)
        {
            read(clntSock, buffer, 255);
            fprintf(f, "%s ", buffer);
            cnt++;
        }

        printf("File Received ! -- from server ");

		close(clntSock);
		// printf("End of Server Loop\n");
	}

	printf("End of Program\n");

}
