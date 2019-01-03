#ifndef FLIGHTGEARINTERPRETER_PRINTEXPRESSIONCOMMAND_H
#define FLIGHTGEARINTERPRETER_PRINTEXPRESSIONCOMMAND_H

#include <iostream>

#include "Command.h"
#include "../Expressions/Expression.h"

using namespace std;

/**
 * defines print expression command
 */
class PrintExpressionCommand : public Command {

    Expression *exp;

public:

    PrintExpressionCommand(Expression *exp) : exp(exp) {}

    double execute() override {
        cout << exp->calculate() << endl;
        return 0;
    }

    ~PrintExpressionCommand() override {
        delete(exp);
    }
};


#endif //FLIGHTGEARINTERPRETER_PRINTEXPRESSIONCOMMAND_H
