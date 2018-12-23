
#include "DataWriterClient.h"


DataWriterClient::DataWriterClient(string serverIP, uint16_t serverPort) : serverIP(move(serverIP)),
                                                                                  serverPort(serverPort) {}

bool DataWriterClient::open() {

    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(serverIP.c_str());

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(serverPort);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    /* Now ask for a message from the user, this message
       * will be read by server
    */

    return true;
}




bool DataWriterClient::closeClient() {
    close(this->sockfd);
    return true;
}





bool DataWriterClient::send(string message) {

    ssize_t n;

    /* Send message to the server */
    n = write(sockfd, message.c_str(), message.length());

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    //TODO remove
    printf("%s\n", message.c_str());

    return true;
}







