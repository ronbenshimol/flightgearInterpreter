#ifndef FLIGHTGEARINTERPRETER_PLUS_H
#define FLIGHTGEARINTERPRETER_PLUS_H


#include "BinaryExpression.h"

class Plus : public BinaryExpression {

    double calculate(){
        return leftExpression->calculate() + rightExpression->calculate();
    }

public:
    Plus(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression, rightExpression) {}


};


#endif //FLIGHTGEARINTERPRETER_PLUS_H
