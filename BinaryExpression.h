#ifndef FLIGHTGEARINTERPRETER_BINARYEXPRESSION_H
#define FLIGHTGEARINTERPRETER_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : Expression {

protected:
    Expression* leftExpression;
    Expression* rightExpression;

};

#endif //FLIGHTGEARINTERPRETER_BINARYEXPRESSION_H
