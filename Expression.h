//
// Created by shaked on 12/18/18.
//

#ifndef FLIGHTGEARINTERPRETER_EXPRESSION_H
#define FLIGHTGEARINTERPRETER_EXPRESSION_H


class Expression {


public:

    virtual Expression *calculate() = 0;

};


#endif //FLIGHTGEARINTERPRETER_EXPRESSION_H
