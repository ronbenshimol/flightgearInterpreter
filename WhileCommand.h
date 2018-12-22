//
// Created by shaked on 12/22/18.
//

#ifndef FLIGHTGEARINTERPRETER_WHILECOMMAND_H
#define FLIGHTGEARINTERPRETER_WHILECOMMAND_H


#include "ConditionParser.h"

class WhileCommand : public ConditionParser {

public:

    WhileCommand(vector<Command *> commands, BooleanExpression *condition) : ConditionParser(move(commands),
                                                                                                    condition) {}

    double execute() override {
        while (this->isConditionalSatisfied()){
            for(auto c: this->commands){
                c->execute();
            }
        }
        return 0;
    }

};


#endif //FLIGHTGEARINTERPRETER_WHILECOMMAND_H
