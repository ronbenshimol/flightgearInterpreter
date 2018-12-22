//
// Created by shaked on 12/21/18.
//

#ifndef FLIGHTGEARINTERPRETER_CONDITIONALEXPRESSION_H
#define FLIGHTGEARINTERPRETER_CONDITIONALEXPRESSION_H


#include "NaryExpression.h"

class ConditionalExpression : public NaryExpression {

protected:
    Expression *condition;

    ConditionalExpression(vector<Expression *> expressions, Expression *condition) : NaryExpression(move(expressions)),
                                                                                            condition(condition) {}
    bool virtual isConditionalSatisfied(){
        return condition->calculate() == 1;
    }


};

#endif //FLIGHTGEARINTERPRETER_CONDITIONALEXPRESSION_H
