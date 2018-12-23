//
// Created by shaked on 12/23/18.
//

#ifndef FLIGHTGEARINTERPRETER_ASSIGNMENTCOMMAND_H
#define FLIGHTGEARINTERPRETER_ASSIGNMENTCOMMAND_H


#include <string>
#include "Command.h"
#include "Expression.h"
#include "SymbolsTable.h"

using namespace std;

class AssignmentCommand : public Command {

    string symbol;
    Expression *exp;

public:

    AssignmentCommand(string symbol, Expression *exp) : symbol(move(symbol)), exp(exp) {}

    double execute() override {

        double value = exp->calculate();

        SymbolsTable::getInstance()->notifyClientValueChanged(symbol, value);

        return 0;
    }
};


#endif //FLIGHTGEARINTERPRETER_ASSIGNMENTCOMMAND_H
