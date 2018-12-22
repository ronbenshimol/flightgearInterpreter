//
// Created by ron on 20/12/18.
//

#ifndef FLIGHTGEARINTERPRETER_DIV_H
#define FLIGHTGEARINTERPRETER_DIV_H

#include "BinaryExpression.h"

class Div : public BinaryExpression {

public:
    Div(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression, rightExpression) {}

    double calculate(){
        return leftExpression->calculate() / rightExpression->calculate();
    }

};


#endif //FLIGHTGEARINTERPRETER_DIV_H
