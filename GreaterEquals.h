//
// Created by shaked on 12/21/18.
//

#ifndef FLIGHTGEARINTERPRETER_GREATEREQUALS_H
#define FLIGHTGEARINTERPRETER_GREATEREQUALS_H


#include "BooleanExpression.h"

/**
 * >=
 */
class GreaterEquals : public BooleanExpression {

public:
    double calculate() override {
        if (this->leftExpression->calculate() >= this->rightExpression->calculate())
            return 1;
        return 0;
    }

};


#endif //FLIGHTGEARINTERPRETER_GREATEREQUALS_H
