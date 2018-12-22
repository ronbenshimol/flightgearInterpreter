//
// Created by shaked on 12/22/18.
//

#ifndef FLIGHTGEARINTERPRETER_CONDITIONPARSER_H
#define FLIGHTGEARINTERPRETER_CONDITIONPARSER_H


#include <vector>
#include "Command.h"
#include "BooleanExpression.h"


using namespace std;


class ConditionParser : public Command {

protected:

    vector<Command *> commands;
    BooleanExpression *condition;

    ConditionParser(vector<Command *> commands, BooleanExpression *condition) : commands(move(commands)),
                                                                                       condition(condition) {}
    bool virtual isConditionalSatisfied(){
        return condition->calculate() == 1;
    }




};


#endif //FLIGHTGEARINTERPRETER_CONDITIONPARSER_H
