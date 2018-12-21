//
// Created by shaked on 12/21/18.
//

#ifndef FLIGHTGEARINTERPRETER_LESSER_H
#define FLIGHTGEARINTERPRETER_LESSER_H


#include "BooleanExpression.h"
/**
 * <
 */
class Lesser : public BooleanExpression {
public:
    double calculate() override {
        return (leftExpression->calculate() < rightExpression->calculate())? 1 : 0 ;
    }
};


#endif //FLIGHTGEARINTERPRETER_LESSER_H
