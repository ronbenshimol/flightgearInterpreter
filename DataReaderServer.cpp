#include "DataReaderServer.h"
#include "Utils.h"
#include "SymbolsTable.h"
#include <list>

DataReaderServer::DataReaderServer(int serverPort, int numOfReadsPs){

    this->serverPort = serverPort;
    this->numOfReadsPs = numOfReadsPs;

}

void DataReaderServer::open(){

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

    std::string paths[23] = {
            "/instrumentation/airspeed-indicator/indicated-speed-kt",
            "/instrumentation/altimeter/indicated-altitude-ft",
            "/instrumentation/altimeter/pressure-alt-ft",
            "/instrumentation/attitude-indicator/indicated-pitch-deg",
            "/instrumentation/attitude-indicator/indicated-roll-deg",
            "/instrumentation/attitude-indicator/internal-pitch-deg",
            "/instrumentation/attitude-indicator/internal-roll-deg",
            "/instrumentation/encoder/indicated-altitude-ft",
            "/instrumentation/encoder/pressure-alt-ft",
            "/instrumentation/gps/indicated-altitude-ft",
            "/instrumentation/gps/indicated-ground-speed-kt",
            "/instrumentation/gps/indicated-vertical-speed",
            "/instrumentation/heading-indicator/indicated-heading-deg",
            "/instrumentation/magnetic-compass/indicated-heading-deg",
            "/instrumentation/slip-skid-ball/indicated-slip-skid",
            "/instrumentation/turn-indicator/indicated-turn-rate",
            "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
            "/controls/flight/aileron",
            "/controls/flight/elevator",
            "/controls/flight/rudder",
            "/controls/flight/flaps",
            "/controls/engines/engine/throttle",
            "/engines/engine/rpm"
    };


    for (int i = 0; i < valuesVec.size(); ++i) {

        SymbolsTable::getInstance() -> setSymbol(paths[i], std::atof(valuesVec[i].c_str()));

    }

}


