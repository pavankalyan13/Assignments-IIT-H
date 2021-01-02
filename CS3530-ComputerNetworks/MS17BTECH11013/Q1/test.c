#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {

	if (argc != 4) {
		perror("<Server Address> <Server Port> <Echo Word>");
		exit(-1);
	}

	// char *servIP = argv[1];

	// we get hostName instead of IP Address
	char *hostName = argv[1];
	char *echoString = argv[3];
    char *servIP;


		// char *portName = argv[2];		// Get PortName or Port Number
	struct addrinfo hints;			// Give initial hints to resolver
	struct addrinfo *result, *rp;		// Result will be stored here

	// Prepare the hints for resolver
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;		// IPv4 or v6
	hints.ai_socktype = SOCK_STREAM;	// Hardcoded TCP as dummy
	hints.ai_protocol = IPPROTO_TCP;	// Hardcoded TCP as dummy
	hints.ai_flags = AI_CANONNAME;		// I want canonical name!!

	// Only stream sockets
	// Only TCP protocol
	// Get address(es) associated with the specified name/service
	// Modify servAddr contents to reference linked list of addresses
	int s = getaddrinfo(hostName, NULL, &hints, &result);
	if (s != 0) {
		perror("getaddrinfo() failed");
		exit(s);
	}

	// Display returned addresses3.1 Mapping Names to Numbers
	// We don't use portName because no need of resolving service
	for (rp = result; rp != NULL; rp = rp->ai_next) {

		// struct sockaddr *address;
		struct sockaddr_in *saIn4;
		struct sockaddr_in6 *saIn6;
		char addrString[INET6_ADDRSTRLEN];
		memset(addrString, 0, sizeof(addrString));

		switch (rp->ai_family) {
		case AF_INET:
			saIn4 = (struct sockaddr_in *) rp->ai_addr;
			inet_ntop(rp->ai_family, &saIn4->sin_addr.s_addr, addrString, sizeof(addrString));
			break;

		case AF_INET6:
			saIn6 = (struct sockaddr_in6 *) rp->ai_addr;
			inet_ntop(rp->ai_family, &saIn6->sin6_addr.s6_addr, addrString, sizeof(addrString));
			break;

		default:
			printf("unknown protocol\n");
			break;
		}

		// printf("IP Address: %s\n", addrString);

		strcpy(servIP,addrString);
	}


	printf("\n The IP addr of the hostName is %s\n", servIP);

	// Set port number as given by user or as default 12345
	// in_port_t servPort = (argc == 3) ? atoi(argv[2]) : 12345;

	// Set port number as user specifies
	in_port_t servPort = atoi(argv[2]);

	//Creat a socket
	int sockfd = socket(AF_UNSPEC, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd < 0) {
		perror("socket() failed");
		exit(-1);
	}

	// Set the server address
	struct sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_UNSPEC;
	int err = inet_pton(AF_UNSPEC, servIP, &servAddr.sin_addr.s_addr);
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

	size_t echoStringLen = strlen(echoString);

	// Send string to server
	ssize_t sentLen = send(sockfd, echoString, echoStringLen, 0);
	if (sentLen < 0) {
		perror("send() failed");
		exit(-1);
	} else if (sentLen != echoStringLen) {
		perror("send(): sent unexpected number of bytes");
		exit(-1);
	}

	// Receive string from server
	unsigned int totalRecvLen = 0;

	fputs("Received: ", stdout);
	while (totalRecvLen < echoStringLen) {
		char buffer[BUFSIZE];
		memset(buffer, 0, BUFSIZE);
		ssize_t recvLen = recv(sockfd, buffer, BUFSIZE - 1, 0);
		if (recvLen < 0) {
			perror("recv() failed");
			exit(-1);
		} else if (recvLen == 0) {
			perror("recv() connection closed prematurely");
			exit(-1);
		}

		totalRecvLen += recvLen;
		buffer[recvLen] = '\n';
		fputs(buffer, stdout);
	}

	close(sockfd);
	exit(0);
}
