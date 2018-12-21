//
// Created by shaked on 12/21/18.
//

#ifndef FLIGHTGEARINTERPRETER_NOTEQUALS_H
#define FLIGHTGEARINTERPRETER_NOTEQUALS_H

#include "BooleanExpression.h"

/**
 * !=
 */
class NotEquals : public BooleanExpression {
public:
    double calculate() override {
        return (leftExpression->calculate() != rightExpression->calculate())? 1 : 0 ;
    }

};


#endif //FLIGHTGEARINTERPRETER_NOTEQUALS_H
