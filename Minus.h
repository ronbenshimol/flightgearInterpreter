#ifndef FLIGHTGEARINTERPRETER_MINUS_H
#define FLIGHTGEARINTERPRETER_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression {

public:

    Minus(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression,
                                                                                      rightExpression) {}

    double calculate(){
        return leftExpression->calculate() - rightExpression->calculate();
    }

};


#endif //FLIGHTGEARINTERPRETER_MINUS_H
