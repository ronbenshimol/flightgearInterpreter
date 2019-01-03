#ifndef FLIGHTGEARINTERPRETER_LESSEREQUALS_H
#define FLIGHTGEARINTERPRETER_LESSEREQUALS_H


#include "BooleanExpression.h"

/**
 * <= expression
 */
class LesserEquals : public BooleanExpression {
public:

    LesserEquals(Expression *leftExpression, Expression *rightExpression) : BooleanExpression(leftExpression,
                                                                                              rightExpression) {}

    double calculate() override {
        return (leftExpression->calculate() <= rightExpression->calculate())? 1 : 0 ;
    }
};


#endif //FLIGHTGEARINTERPRETER_LESSEREQUALS_H
