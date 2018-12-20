//
// Created by shaked on 12/20/18.
//

#ifndef FLIGHTGEARINTERPRETER_NEG_H
#define FLIGHTGEARINTERPRETER_NEG_H


#include "UnaryExpression.h"

class Neg : public UnaryExpression {


private:
    double calculate(){
        return -1 * innerExpression->calculate();
    }

public:
    Neg(Expression *innerExpression) : UnaryExpression(innerExpression) {}
};


#endif //FLIGHTGEARINTERPRETER_NEG_H
