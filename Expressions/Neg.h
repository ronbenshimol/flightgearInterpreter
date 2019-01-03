#ifndef FLIGHTGEARINTERPRETER_NEG_H
#define FLIGHTGEARINTERPRETER_NEG_H


#include "UnaryExpression.h"

/**
 * defines unary - expression
 */
class Neg : public UnaryExpression {

public:

    Neg(Expression *innerExpression) : UnaryExpression(innerExpression) {}

    double calculate(){
        return -1 * innerExpression->calculate();
    }

};


#endif //FLIGHTGEARINTERPRETER_NEG_H
