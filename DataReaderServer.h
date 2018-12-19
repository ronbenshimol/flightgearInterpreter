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
    const std::string paths[23] = {
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

    void updateSymbolsValues(std::vector<std::string> valuesVec);


public:
    DataReaderServer(int serverPort, int numOfReadsPs);
    void openServer();
    void closeServer();
};


#endif //FLIGHTGEARINTERPRETER_DATAREADERSERVER_H
