#ifndef FLIGHTGEARINTERPRETER_UNARYEXPRESSION_H
#define FLIGHTGEARINTERPRETER_UNARYEXPRESSION_H

#include "Expression.h"

class UnaryExpression : public Expression {

protected:
    Expression* innerExpression;
    UnaryExpression(Expression *innerExpression) : innerExpression(innerExpression) {} ;

public:
    ~UnaryExpression() override {
        delete(innerExpression);
    }

};


#endif //FLIGHTGEARINTERPRETER_UNARYEXPRESSION_H
