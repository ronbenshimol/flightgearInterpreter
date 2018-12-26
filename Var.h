#ifndef FLIGHTGEARINTERPRETER_VAR_H
#define FLIGHTGEARINTERPRETER_VAR_H

#include <string>
#include "Expression.h"
#include "SymbolsTable.h"

/*
 * var expression, holds the name of the var and return the value on execute
 */
class Var: public Expression {

    std::string name;

public:

    Var(std::string name){
        this->name = name;
    }

    double calculate() override {
        return SymbolsTable::getInstance()->getSymbolValue(name);
    }


};

#endif //FLIGHTGEARINTERPRETER_VAR_H
