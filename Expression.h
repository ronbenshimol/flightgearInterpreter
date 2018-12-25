#ifndef FLIGHTGEARINTERPRETER_EXPRESSION_H
#define FLIGHTGEARINTERPRETER_EXPRESSION_H


class Expression {

public:

    virtual double calculate() = 0;
    virtual ~Expression() = default;

};


#endif //FLIGHTGEARINTERPRETER_EXPRESSION_H
