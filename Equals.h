#ifndef FLIGHTGEARINTERPRETER_EQUALS_H
#define FLIGHTGEARINTERPRETER_EQUALS_H


#include "BooleanExpression.h"

/**
 * == expression
 */
class Equals : public BooleanExpression {

public:

    Equals(Expression *leftExpression, Expression *rightExpression) : BooleanExpression(leftExpression,
                                                                                        rightExpression) {}

    double calculate() override {
        return (leftExpression->calculate() == rightExpression->calculate())? 1 : 0 ;
    }

};


#endif //FLIGHTGEARINTERPRETER_EQUALS_H
