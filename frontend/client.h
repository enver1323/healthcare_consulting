#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

void *rcvMsgs(void *threadId);
void *sendMsgs(void *threadId);
static int sock = 0;

int initSocket()
{
	struct sockaddr_in address;
	int valread;
	struct sockaddr_in serv_addr;
	char *hello = "Hello from client";
	char buffer[1024] = {0}, cchat[1024];
	char *bye = "bye";
	pthread_t threads[2];
	printf("CREATING CLIENT SOCKET .....\n");
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n Socket creation error \n");
		return -1;
	}

	printf("DEFINING CLIENT SOCKET FAMILY, ADDRESS & PORT .....\n");
	memset(&serv_addr, '0', sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}
	printf("CLIENT CONNECTING ON PORT 8080 TO COMMUNICATE WITH SERVER.....\n");

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		printf("\nConnection Failed \n");
		return -1;
	}
	send(sock , hello , strlen(hello) , 0 );
	printf("Hello message sent\n");
	valread = read( sock , buffer, 1024);
	printf("%s\n",buffer );
	printf(" Ready for Chat....\n");
	// thread for receiving messages
	pthread_create(&threads[0], NULL, rcvMsgs, (void*)0);
	// thread for sending messages
	pthread_create(&threads[1], NULL, sendMsgs, (void*)1);
	while(1) {
		// waiting for thread to execute
	}
	return 0;
}

void *rcvMsgs(void *threadId){
	char buffer[1024] = {0};
	while(1) {
		memset(buffer, 0, sizeof(buffer));
		int valread = read( sock , buffer, 1024);
		printf("\n%s\n",buffer );
	}
	pthread_exit(NULL);
	return 0;
}

void *sendMsgs(void *threadId){
	char cchat[1024];
	while(1) {
		memset(cchat, 0, sizeof(cchat));
		//printf("CLIENT : ");
		fgets (cchat, sizeof(cchat), stdin);
		send(sock , cchat , strlen(cchat) , 0 );
		if(strncmp(cchat, "bye", strlen("bye"))==0)
			break;
	}
	pthread_exit(NULL);
	return 0;
}
