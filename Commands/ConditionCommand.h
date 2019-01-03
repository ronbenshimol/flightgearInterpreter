#ifndef FLIGHTGEARINTERPRETER_CONDITIONPARSER_H
#define FLIGHTGEARINTERPRETER_CONDITIONPARSER_H


#include <vector>
#include "Command.h"
#include "../Expressions/BooleanExpression.h"


using namespace std;

/**
 * wraps commands that are being executed with a condition
 */
class ConditionCommand : public Command {

protected:

    vector<Command *> commands;
    BooleanExpression *condition;

    ConditionCommand(vector<Command *> commands, BooleanExpression *condition) : commands(move(commands)),
                                                                                       condition(condition) {}
    bool virtual isConditionalSatisfied(){
        return condition->calculate() == 1;
    }

public:
    ~ConditionCommand() override {
        for(auto c: commands)
            delete(c);
        delete(condition);
    }


};


#endif //FLIGHTGEARINTERPRETER_CONDITIONPARSER_H
