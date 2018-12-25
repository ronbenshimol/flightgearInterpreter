#ifndef FLIGHTGEARINTERPRETER_GREATEREQUALS_H
#define FLIGHTGEARINTERPRETER_GREATEREQUALS_H


#include "BooleanExpression.h"

/**
 * >=
 */
class GreaterEquals : public BooleanExpression {

public:

    GreaterEquals(Expression *leftExpression, Expression *rightExpression) : BooleanExpression(leftExpression,
                                                                                               rightExpression) {}

    double calculate() override {
        if (this->leftExpression->calculate() >= this->rightExpression->calculate())
            return 1;
        return 0;
    }

};


#endif //FLIGHTGEARINTERPRETER_GREATEREQUALS_H
