//
// Created by shaked on 12/21/18.
//

#ifndef FLIGHTGEARINTERPRETER_IFEXPRESSION_H
#define FLIGHTGEARINTERPRETER_IFEXPRESSION_H


#include "ConditionalExpression.h"

class IfExpression : public ConditionalExpression {


public:
    IfExpression(vector<Expression *> expressions, Expression *condition) : ConditionalExpression(move(expressions),
                                                                                                         condition) {}

    double calculate() override {
        if(this->isConditionalSatisfied()){
            for(Expression *e: this->expressions)
                e->calculate();
        }
        //TODO seems legit?
        return 0;
    }


};


#endif //FLIGHTGEARINTERPRETER_IFEXPRESSION_H
