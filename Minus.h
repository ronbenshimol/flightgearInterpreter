#ifndef FLIGHTGEARINTERPRETER_MINUS_H
#define FLIGHTGEARINTERPRETER_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression {

    double calculate(){
        return leftExpression->calculate() - rightExpression->calculate();
    }

public:
    Minus(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression,
                                                                                      rightExpression) {}
};


#endif //FLIGHTGEARINTERPRETER_MINUS_H
