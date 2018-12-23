


#include "DataWriterClient.h"


#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>


DataWriterClient::DataWriterClient(std::string serverIp, uint16_t serverPort){

//    struct sockaddr_in serv_addr;
//    struct hostent *server;
//
//
//    /* Create a socket point */
//    sockfd = socket(AF_INET, SOCK_STREAM, 0);
//
//    if (sockfd < 0) {
//        perror("ERROR opening socket");
//        exit(1);
//    }
//
//    server = gethostbyname(serverIp.c_str());
//
//    if (server == NULL) {
//        fprintf(stderr,"ERROR, no such host\n");
//        exit(0);
//    }
//
//    bzero((char *) &serv_addr, sizeof(serv_addr));
//    serv_addr.sin_family = AF_INET;
//    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
//    serv_addr.sin_port = htons(serverPort);
//
//    /* Now connect to the server */
//    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
//        perror("ERROR connecting");
//        exit(1);
//    }
//
//    /* Now ask for a message from the user, this message
//       * will be read by server
//    */
//


}


bool DataWriterClient::send(string message) {

//    int n;
//
//
//    /* Send message to the server */
//    n = write(sockfd, message., message.length());
//
//    if (n < 0) {
//        perror("ERROR writing to socket");
//        exit(1);
//    }
//
//    /* Now read server response */
//    bzero(buffer,256);
//    n = read(sockfd, buffer, 255);
//
//    if (n < 0) {
//        perror("ERROR reading from socket");
//        exit(1);
//    }
//
//    printf("%s\n",buffer);


    return false;
}
