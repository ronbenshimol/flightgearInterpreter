#ifndef FLIGHTGEARINTERPRETER_DATAWRITERCLIENT_H
#define FLIGHTGEARINTERPRETER_DATAWRITERCLIENT_H



#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string>
#include <string.h>


using namespace std;

/**
 * defines a client
 */
class DataWriterClient {


    int sockfd;
    string serverIP;
    uint16_t serverPort;


public:

    DataWriterClient(std::string serverIp, uint16_t serverPort);

    bool open();

    bool send(string message);

    bool closeClient();

};


#endif //FLIGHTGEARINTERPRETER_DATAWRITERCLIENT_H
