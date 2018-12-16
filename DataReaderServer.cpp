#include "DataReaderServer.h"

void DataReaderServer::openServer(){

    std::cout << "starting server.." << std::endl;

    int serverPort = 5400;

    int sockedFd; // main socket fileDescriptor
    int newsockfd; // new socket fileDescriptor
    int clilen;

    char buffer[1001];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    //creating socket object
    sockedFd = socket(AF_INET, SOCK_STREAM, 0);
    //if creation faild
    if (sockedFd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    //Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET; // tcp server
    serv_addr.sin_addr.s_addr = INADDR_ANY; //server ip (0.0.0.0 for all incoming connections)
    serv_addr.sin_port = htons(serverPort); //init server port

    //bind the host address using bind() call
    if (bind(sockedFd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        //if binding faild
        perror("ERROR on binding");
        exit(1);
    }

    std::cout << "listening..." << std::endl;

    //start listening for the clients using the main socket
    listen(sockedFd,5);
    clilen = sizeof(cli_addr);

    //accept actual connection from the client
    newsockfd = accept(sockedFd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    std::cout << "connected to client!" << std::endl;

    //if connections with the client faild
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }


    while(true){

        //if connection is established then start communicating
        bzero(buffer,1001);
        n = read(newsockfd,buffer,1000);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        std::cout << "Here is the message:   " << buffer << std::endl;

    }


}