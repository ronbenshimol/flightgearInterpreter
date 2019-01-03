#ifndef FLIGHTGEARINTERPRETER_BINARYEXPRESSION_H
#define FLIGHTGEARINTERPRETER_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {

protected:
    Expression* leftExpression;
    Expression* rightExpression;

    BinaryExpression(Expression *leftExpression, Expression *rightExpression) : leftExpression(leftExpression),
                                                                                rightExpression(rightExpression) {}

public:
    ~BinaryExpression() override {
        delete(leftExpression);
        delete(rightExpression);
    }
};

#endif //FLIGHTGEARINTERPRETER_BINARYEXPRESSION_H
