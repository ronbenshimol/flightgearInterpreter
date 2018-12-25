#ifndef FLIGHTGEARINTERPRETER_TCPSERVER_H
#define FLIGHTGEARINTERPRETER_TCPSERVER_H

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


class TcpServer {


public:

    //return new socketId
    static int acceptConnection(int serverPort);
    static std::string readLine(int socketId);
    static void closeSocket(int socketId);


};


#endif //FLIGHTGEARINTERPRETER_TCPSERVER_H
