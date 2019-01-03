#ifndef FLIGHTGEARINTERPRETER_MULTI_H
#define FLIGHTGEARINTERPRETER_MULTI_H


#include "BinaryExpression.h"

/**
 * defines * expression
 */
class Multi : public BinaryExpression {

public:

    Multi(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression,
                                                                                      rightExpression) {}

    double calculate(){
        return leftExpression->calculate() * rightExpression->calculate();
    }


};


#endif //FLIGHTGEARINTERPRETER_MULTI_H
