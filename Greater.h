//
// Created by shaked on 12/21/18.
//

#ifndef FLIGHTGEARINTERPRETER_GREATER_H
#define FLIGHTGEARINTERPRETER_GREATER_H


#include "BooleanExpression.h"

/**
 * exp1 > exp2
 */
class Greater : public BooleanExpression {
public:
    double calculate() override {
        if (this->leftExpression->calculate() > this->rightExpression->calculate())
            return 1;
        return 0;
    }
};


#endif //FLIGHTGEARINTERPRETER_GREATER_H
