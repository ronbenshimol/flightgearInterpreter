//
// Created by ron on 20/12/18.
//

#ifndef FLIGHTGEARINTERPRETER_UNARYEXPRESSION_H
#define FLIGHTGEARINTERPRETER_UNARYEXPRESSION_H

#include "Expression.h"

class UnaryExpression : Expression {
protected:
    Expression* innerExpression;

};


#endif //FLIGHTGEARINTERPRETER_UNARYEXPRESSION_H
