//
// Created by shaked on 12/21/18.
//

#ifndef FLIGHTGEARINTERPRETER_LESSEREQUALS_H
#define FLIGHTGEARINTERPRETER_LESSEREQUALS_H


#include "BooleanExpression.h"

/**
 * <=
 */
class LesserEquals : public BooleanExpression {
public:
    double calculate() override {
        return (leftExpression->calculate() <= rightExpression->calculate())? 1 : 0 ;
    }
};


#endif //FLIGHTGEARINTERPRETER_LESSEREQUALS_H
