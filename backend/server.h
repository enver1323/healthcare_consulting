#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h>
#include <errno.h>
#include <unistd.h> //close
#include <arpa/inet.h> //close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros

#define TRUE 1
#define FALSE 0
#define PORT 8080

int initSocket() {
    int opt = TRUE;
    int master_socket, addrlen, new_socket, client_socket[30], max_clients = 30, activity, i, valread, sd;
    int max_sd;
    struct sockaddr_in address;
    char buffer[1025], response[1025]; //data buffer of 1K
    //set of controller descriptors
    fd_set readfds;
    //a message
    char *message = "ECHO Daemon v1.0 \r\n";
    //initialise all client_socket[] to 0 so not checked
    for (i = 0; i < max_clients; i++) {
        client_socket[i] = 0;
    }
    //create a master controller
    if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("controller creation failed");
        exit(EXIT_FAILURE);
    }
    //set master controller to allow multiple connections ,
    //this is just a good habit, it will work without this
    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *) &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    //type of controller created
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    //bind the controller to localhost port 8888
    if (bind(master_socket, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    printf("Listener on port %d \n", PORT);
    //try to specify maximum of 3 pending connections for the master controller
    if (listen(master_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    //accept the incoming connection
    addrlen = sizeof(address);
    puts("Waiting for connections ...");
    while (TRUE) {
        //clear the controller set
        FD_ZERO(&readfds);
        //add master controller to set
        FD_SET(master_socket, &readfds);
        max_sd = master_socket;
        //add child sockets to set
        for (i = 0; i < max_clients; i++) {
            //controller descriptor
            sd = client_socket[i];
            //if valid controller descriptor then add to read list
            if (sd > 0)
                FD_SET(sd, &readfds);
            //highest file descriptor number, need it for the select function
            if (sd > max_sd)
                max_sd = sd;
        }
        //wait for an activity on one of the sockets , timeout is NULL ,
        //so wait indefinitely
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
        if ((activity < 0) && (errno != EINTR))
            printf("select error");
        //If something happened on the master controller ,
        //then its an incoming connection
        if (FD_ISSET(master_socket, &readfds)) {
            if ((new_socket = accept(master_socket, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }
            //inform user of controller number - used in send and receive commands
            printf("New connection , controller fd is %d , ip is : %s , port : %d \n", new_socket,
                   inet_ntoa(address.sin_addr), ntohs(address.sin_port));
            //send new connection greeting message
            if (send(new_socket, message, strlen(message), 0) != strlen(message))
                perror("send");
            puts("Welcome message sent successfully");
            //add new controller to array of sockets
            for (i = 0; i < max_clients; i++) {
                //if position is empty
                if (client_socket[i] == 0) {
                    client_socket[i] = new_socket;
                    printf("Adding to list of sockets as %d\n", i);
                    break;
                }
            }
        }
        //else its some IO operation on some other controller
        for (i = 0; i < max_clients; i++) {
            sd = client_socket[i];
            if (FD_ISSET(sd, &readfds)) {
                //Check if it was for closing , and also read the
                //incoming message
                if ((valread = read(sd, buffer, 1024)) == 0) {
                    //Somebody disconnected , get his details and print
                    getpeername(sd, (struct sockaddr *) &address, (socklen_t *) &addrlen);
                    printf("Host disconnected , ip %s , port %d \n", inet_ntoa(address.sin_addr),
                           ntohs(address.sin_port));
                    //Close the controller and mark as 0 in list for reuse
                    close(sd);
                    client_socket[i] = 0;
                }
                    //Echo back the message that came in
                else {
                    //set the string terminating NULL byte on the end
                    //of the data read
                    buffer[valread] = '\0';
                    sprintf(response, "Client %d: %s", i, buffer);

                    for (int j = 0; j < max_clients; j++) {
                        int tempSd = client_socket[j];
                        if (!FD_ISSET(tempSd, &readfds)) {
                            send(tempSd, response, strlen(response), 0);
                        }
                    }
                    // send(sd , buffer , strlen(buffer) , 0 );
                }
            }
        }
    }
    return 0;
}
