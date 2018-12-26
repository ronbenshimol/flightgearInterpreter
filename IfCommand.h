#ifndef FLIGHTGEARINTERPRETER_IFCOMMAND_H
#define FLIGHTGEARINTERPRETER_IFCOMMAND_H


#include "ConditionCommand.h"

using namespace std;
/**
 * defines if conditional command execution
 */
class IfCommand : public ConditionCommand {

public:

    IfCommand(vector<Command *> commands, BooleanExpression *condition) : ConditionCommand(move(commands), condition) {}

    double execute() override {
        if (this->isConditionalSatisfied()){
            for(auto c: this->commands){
                c->execute();
            }
        }
        return 0;
    }



};


#endif //FLIGHTGEARINTERPRETER_IFCOMMAND_H
