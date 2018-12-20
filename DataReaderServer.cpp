#include "DataReaderServer.h"
#include "Utils.h"
#include "SymbolsTable.h"
#include <list>

#include <unistd.h>


//std::thread serverThread([](int port, int numOfReadsPS){
//
//    DataReaderServer server(port,numOfReadsPS);
//    server.openServer();
//
//},5400,10);
//
//
//SymbolsTable::getInstance()-> bindSymbolToPath("rudder","/controls/flight/rudder");
//SymbolsTable::getInstance()-> bindSymbolToPath("throttle","/controls/engines/engine/throttle");
//
//serverThread.join();




DataReaderServer::DataReaderServer(int serverPort, int numOfReadsPs){

    this->serverPort = serverPort;
    this->numOfReadsPs = numOfReadsPs;

}

void DataReaderServer::openServer(){

    std::cout << "starting server.." << std::endl;

    //int serverPort = 5400;

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

    opennedSockets.push_back(socketFd);

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

    std::cout << "listening..." << std::endl;

    //start listening for the clients using the main socket
    listen(socketFd,5);
    clilen = sizeof(cli_addr);

    //accept actual connection from the client
    newsockfd = accept(socketFd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    opennedSockets.push_back(newsockfd);

    std::cout << "connected to client!" << std::endl;

    //if connections with the client faild
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }


    std::string dataStr;

    while(1)
    {
        char buf[1024];
        int numBytesRead = recv(newsockfd, buf, sizeof(buf), 0);
        if (numBytesRead > 0)
        {
            for (int i=0; i<numBytesRead; i++)
            {
                char c = buf[i];
                if (c == '\n')
                {
                    if (dataStr.length() > 0)
                    {
                        //std::cout << "new data received: " << dataStr << std::endl;

                        //separate values by csv format from string
                        std::vector<std::string> values = Utils::explode(dataStr,',');

                        updateSymbolsValues(values);

                        dataStr = "";
                    }
                }
                else dataStr += c;
            }
        }
        else
        {
            std::cout << "Socket closed or socket error!" << std::endl;
            break;
        }
    }

}

void DataReaderServer::updateSymbolsValues(std::vector<std::string> valuesVec){

    for (int i = 0; i < valuesVec.size(); ++i) {

        SymbolsTable::getInstance() -> updateLocalValueByPath(paths[i], std::atof(valuesVec[i].c_str()));

        SymbolsTable::getInstance() ->printSymbols();
    }

}

void DataReaderServer::closeServer(){

    //TODO: check if working

    //opennedSockets.
    for (int c : opennedSockets) {
        close(c);
    }
}


