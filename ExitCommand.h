//
// Created by shaked on 12/24/18.
//

#ifndef FLIGHTGEARINTERPRETER_EXITCOMMAND_H
#define FLIGHTGEARINTERPRETER_EXITCOMMAND_H


#include "Command.h"
#include "SymbolsTable.h"

class ExitCommand : public Command {

public:
    double execute() override {
        //TODO those
        //close client
        //close server

        SymbolsTable::getInstance()->getClient()->closeClient();

        //free memory

        exit(0);

        return 0;
    }


};


#endif //FLIGHTGEARINTERPRETER_EXITCOMMAND_H
