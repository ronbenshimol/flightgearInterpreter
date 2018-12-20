#ifndef FLIGHTGEARINTERPRETER_MINUS_H
#define FLIGHTGEARINTERPRETER_MINUS_H

#include "BinaryExpression.h"

class Minus : BinaryExpression {

    double calculate(){
        return leftExpression->calculate() - rightExpression->calculate();
    }

};


#endif //FLIGHTGEARINTERPRETER_MINUS_H
