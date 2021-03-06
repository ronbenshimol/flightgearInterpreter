//
// Created by shaked on 12/23/18.
//

#ifndef FLIGHTGEARINTERPRETER_ASSIGNMENTCOMMAND_H
#define FLIGHTGEARINTERPRETER_ASSIGNMENTCOMMAND_H


#include <string>
#include "Command.h"
#include "../Expressions/Expression.h"
#include "../interpreter/SymbolsTable.h"

using namespace std;

/**
 * assignment command
 */
class AssignmentCommand : public Command {

    string symbol;
    Expression *exp;

public:

    AssignmentCommand(string symbol, Expression *exp) : symbol(move(symbol)), exp(exp) {}

    /**
     * notifies client that value has changed
     * @return 0
     */
    double execute() override {

        double value = exp->calculate(); // calc the right side to assign
        string path = SymbolsTable::getInstance()->getSymbolPath(symbol);
        if(path != ""){
                DataWriterClient* client = SymbolsTable::getInstance()->getClient();
                string message = "set " + path + " " + to_string(value) + "\r\n";
                client->send(message);
        }
        else{
                SymbolsTable::getInstance()->setSymbol(symbol, value);
        }

        return 0;
    }

    ~AssignmentCommand() override {
            delete exp;
    }


};


#endif //FLIGHTGEARINTERPRETER_ASSIGNMENTCOMMAND_H
