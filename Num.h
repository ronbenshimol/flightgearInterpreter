#ifndef FLIGHTGEARINTERPRETER_NUM_H
#define FLIGHTGEARINTERPRETER_NUM_H


#include "Expression.h"

class Num : public Expression {

    double value;

public:

    Num(double value) : value(value) {}

    double calculate() override {
        return value;
    }

};


#endif //FLIGHTGEARINTERPRETER_NUM_H
