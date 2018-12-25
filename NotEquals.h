#ifndef FLIGHTGEARINTERPRETER_NOTEQUALS_H
#define FLIGHTGEARINTERPRETER_NOTEQUALS_H

#include "BooleanExpression.h"

/**
 * !=
 */
class NotEquals : public BooleanExpression {

public:

    NotEquals(Expression *leftExpression, Expression *rightExpression) : BooleanExpression(leftExpression,
                                                                                           rightExpression) {}

    double calculate() override {
        return (leftExpression->calculate() != rightExpression->calculate())? 1 : 0 ;
    }

};


#endif //FLIGHTGEARINTERPRETER_NOTEQUALS_H
