#ifndef FLIGHTGEARINTERPRETER_DATASERVER_H
#define FLIGHTGEARINTERPRETER_DATASERVER_H

#include <iostream>
#include <string>
#include "Utils.h"
#include "SymbolsTable.h"

class DataServer {

private:
    /* Here will be the instance stored. */
    static DataServer *instance;

    /* Private constructor to prevent instancing. */
    DataServer(int serverPort);
    void updateSymbolsValues(std::string dataStr);

    int serverPort;
    int socketId;
    bool endServerFlag;

public:
    /* Static access method. */
    static DataServer *getInstance();
    static DataServer *getInstance(int serverPort);
    static void destroyInstance();

    void openServer();
    void receiveOnce();
    void startReceive();
    void stopReceive();
    void closeServer();
    ~DataServer();

};


#endif //FLIGHTGEARINTERPRETER_DATASERVER_H
