//
// Created by ron on 21/12/18.
//

#ifndef FLIGHTGEARINTERPRETER_OPENDATASERVER_H
#define FLIGHTGEARINTERPRETER_OPENDATASERVER_H

#include <thread>

#include "BinaryExpression.h"
#include "DataReaderServer.h"
#include "SymbolsTable.h"

class OpenDataServer : public BinaryExpression {

public:

    OpenDataServer(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression,
                                                                                               rightExpression) {}

    double calculate(){

        double ip = leftExpression->calculate() - rightExpression->calculate();


        std::thread serverThread([](int port, int numOfReadsPS){

            DataReaderServer server(port,numOfReadsPS);
            server.openServer();

        },5400,10);

        return leftExpression->calculate() - rightExpression->calculate();
    }

};


#endif //FLIGHTGEARINTERPRETER_OPENDATASERVER_H
