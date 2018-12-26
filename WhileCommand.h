#ifndef FLIGHTGEARINTERPRETER_WHILECOMMAND_H
#define FLIGHTGEARINTERPRETER_WHILECOMMAND_H


#include "ConditionCommand.h"

/*
 * defines command for while execution, gets condition and list of commands to execute
 */
class WhileCommand : public ConditionCommand {

public:

    WhileCommand(vector<Command *> commands, BooleanExpression *condition) : ConditionCommand(move(commands),
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
