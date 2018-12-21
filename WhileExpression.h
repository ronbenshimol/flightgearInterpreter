//
// Created by shaked on 12/21/18.
//

#ifndef FLIGHTGEARINTERPRETER_WHILEEXPRESSION_H
#define FLIGHTGEARINTERPRETER_WHILEEXPRESSION_H


#include "ConditionalExpression.h"

class WhileExpression : public ConditionalExpression {

public:
    WhileExpression(const vector<Expression *> &expressions,
            Expression *condition) : ConditionalExpression(expressions, condition) {}

    double calculate() override {
        while(this->isConditionalSatisfied()){
            for(Expression *e: this->expressions)
                e->calculate();
        }
        //TODO seems legit?
        return 0;
    }

};


#endif //FLIGHTGEARINTERPRETER_WHILEEXPRESSION_H
