//
// Created by shaked on 12/21/18.
//

#ifndef FLIGHTGEARINTERPRETER_NARYEXPRESSION_H
#define FLIGHTGEARINTERPRETER_NARYEXPRESSION_H

#include <vector>
#include "Expression.h"

using namespace std;

class NaryExpression : public Expression {

protected:
    vector<Expression *> expressions;
public:
    NaryExpression(vector<Expression *> expressions) : expressions(move(expressions)) {}

};


#endif //FLIGHTGEARINTERPRETER_NARYEXPRESSION_H
