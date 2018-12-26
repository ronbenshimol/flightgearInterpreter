#ifndef FLIGHTGEARINTERPRETER_PLUS_H
#define FLIGHTGEARINTERPRETER_PLUS_H


#include "BinaryExpression.h"

/**
 * defines + expression
 */
class Plus : public BinaryExpression {

public:

    Plus(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression, rightExpression) {}

    double calculate(){
        return leftExpression->calculate() + rightExpression->calculate();
    }





};


#endif //FLIGHTGEARINTERPRETER_PLUS_H
