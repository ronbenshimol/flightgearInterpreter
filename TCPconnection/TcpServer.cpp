#include "TcpServer.h"

int TcpServer::acceptConnection(int serverPort){


    int socketFd; // main socket fileDescriptor
    int newsockfd; // new socket fileDescriptor
    int clilen;

    struct sockaddr_in serv_addr, cli_addr;

    //creating socket object
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    //if creation faild
    if (socketFd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    //Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET; // tcp server
    serv_addr.sin_addr.s_addr = INADDR_ANY; //server ip (0.0.0.0 for all incoming connections)
    serv_addr.sin_port = htons(serverPort); //init server port

    //bind the host address using bind() call
    if (bind(socketFd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        //if binding faild
        perror("ERROR on binding");
        exit(1);
    }

    //start listening for the clients using the main socket
    listen(socketFd,5);
    clilen = sizeof(cli_addr);

    //accept actual connection from the client
    newsockfd = accept(socketFd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    //if connections with the client failed
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    return newsockfd;
}

std::string TcpServer::readLine(int socketId){

    std::string dataStr;
    bool lineReaded = false;

    while(!lineReaded)
    {
        char buf[1];
        int numBytesRead = recv(socketId, buf, sizeof(buf), 0);
        if (numBytesRead > 0)
        {
                char c = buf[0];
                if (c == '\n')
                {
                    if (dataStr.length() > 0)
                    {
                        //the all line readed, end while
                        lineReaded = true;
                    }
                }
                else dataStr += c;

        }
        else
        {
            throw "Socket closed or socket error!";
        }

    }

    return dataStr;
}


void TcpServer::closeSocket(int socketId){

    close(socketId);

}
