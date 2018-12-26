//
// Created by shaked on 12/20/18.
//

#ifndef FLIGHTGEARINTERPRETER_BOOLEANEXPRESSION_H
#define FLIGHTGEARINTERPRETER_BOOLEANEXPRESSION_H


#include "BinaryExpression.h"

/**
 * defines boolean expressions
 */
class BooleanExpression : public BinaryExpression {

protected:
    BooleanExpression(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression,
                                                                                                  rightExpression) {}
};


#endif //FLIGHTGEARINTERPRETER_BOOLEANEXPRESSION_H
