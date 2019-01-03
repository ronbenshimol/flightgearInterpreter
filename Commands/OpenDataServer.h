#ifndef FLIGHTGEARINTERPRETER_OPENDATASERVER_H
#define FLIGHTGEARINTERPRETER_OPENDATASERVER_H

#include "../Expressions/BinaryExpression.h"
#include "../TCPconnection/DataServer.h"
#include "../interpreter/SymbolsTable.h"
#include "Command.h"
#include <thread>

/**
 * command to open a data server connection
 */
class OpenDataServer : public Command {

    Expression *portExpression;
    Expression *readePsExpression;
    std::thread serverThread;

public:

    OpenDataServer(Expression *portExp, Expression *readsPs){

        this->portExpression = portExp;
        this->readePsExpression = readsPs;

    }

    double execute(){

        int port = (int)portExpression->calculate();
        int numOfReads = (int)readePsExpression->calculate();

        DataServer::getInstance(port);
        DataServer::getInstance()->openServer();
        DataServer::getInstance()->receiveOnce();

        //starting receiving data from the simulator in thread
        serverThread = std::thread([](){
            DataServer::getInstance()->startReceive();
        });



        return 0;

    }

public:

    ~OpenDataServer() override {

        delete portExpression;
        delete readePsExpression;

        //turn on the flag of stop recieving data in the server
        DataServer::getInstance()->stopReceive();

        //wait for the thread to end
        serverThread.join();

        //destroy the instance of the server
        DataServer::destroyInstance();
    }

};


#endif //FLIGHTGEARINTERPRETER_OPENDATASERVER_H
