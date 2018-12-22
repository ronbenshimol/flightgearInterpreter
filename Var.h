#ifndef FLIGHTGEARINTERPRETER_VAR_H
#define FLIGHTGEARINTERPRETER_VAR_H

#include <string>
#include "Expression.h"
#include "SymbolsTable.h"

class Var: Expression {

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
