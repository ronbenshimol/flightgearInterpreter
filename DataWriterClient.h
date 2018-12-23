#ifndef FLIGHTGEARINTERPRETER_DATAWRITERCLIENT_H
#define FLIGHTGEARINTERPRETER_DATAWRITERCLIENT_H

#include <string>

using namespace std;

class DataWriterClient {

    int sockfd;

public:

    DataWriterClient(std::string serverIp, uint16_t serverPort);

    bool open();

    bool send(string message);

    bool close();

};


#endif //FLIGHTGEARINTERPRETER_DATAWRITERCLIENT_H
