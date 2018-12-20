#ifndef FLIGHTGEARINTERPRETER_MINUS_H
#define FLIGHTGEARINTERPRETER_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression {



public:

    double calculate(){
        return leftExpression->calculate() - rightExpression->calculate();
    }
    Minus(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression,
                                                                                      rightExpression) {}
};


#endif //FLIGHTGEARINTERPRETER_MINUS_H
