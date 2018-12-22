//
// Created by ron on 21/12/18.
//

#ifndef FLIGHTGEARINTERPRETER_OPENDATASERVER_H
#define FLIGHTGEARINTERPRETER_OPENDATASERVER_H

#include <thread>

#include "BinaryExpression.h"
#include "DataReaderServer.h"
#include "SymbolsTable.h"
#include "Command.h"

class OpenDataServer : public Command {

    Expression *leftExpression;
    Expression *rightExpression;

public:

    OpenDataServer(Expression *leftExpression, Expression *rightExpression){

        this->leftExpression = leftExpression;
        this->rightExpression = rightExpression;

    }

    double execute(){

        int port = (int)leftExpression->calculate();
        int numOfReads = (int)rightExpression->calculate();

        std::thread serverThread([](int port, int numOfReadsPS){

            DataReaderServer server(port,numOfReadsPS);
            server.openServer();

        },port,numOfReads);

        return 0;
    }

};


#endif //FLIGHTGEARINTERPRETER_OPENDATASERVER_H
