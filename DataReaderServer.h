#ifndef FLIGHTGEARINTERPRETER_DATAREADERSERVER_H
#define FLIGHTGEARINTERPRETER_DATAREADERSERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>

//server port 5400
class DataReaderServer {

private:
    int serverPort;
    int numOfReadsPs;
    std::vector<int> opennedSockets;

    void updateSymbolsValues(std::string dataStr);


public:
    DataReaderServer(int serverPort, int numOfReadsPs);
    void openServer();
    void closeServer();
};


#endif //FLIGHTGEARINTERPRETER_DATAREADERSERVER_H
