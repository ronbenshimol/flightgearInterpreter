//
// Created by shaked on 12/20/18.
//

#ifndef FLIGHTGEARINTERPRETER_MULTI_H
#define FLIGHTGEARINTERPRETER_MULTI_H


#include "BinaryExpression.h"

class Multi : public BinaryExpression {



public:
    double calculate(){
        return leftExpression->calculate() * rightExpression->calculate();
    }

    Multi(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression,
                                                                                      rightExpression) {}
};


#endif //FLIGHTGEARINTERPRETER_MULTI_H
