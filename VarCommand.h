#ifndef FLIGHTGEARINTERPRETER_VARCOMMAND_H
#define FLIGHTGEARINTERPRETER_VARCOMMAND_H

#include <string>
#include "Command.h"
#include "Expression.h"
#include "SymbolsTable.h"

class VarCommand: Command{

public:

    std::string name;

    VarCommand(std::string name, std::string bindToSymbol) {
        this->name = name;
        SymbolsTable::getInstance()->bindNewSymbolToExistSymbol(name, bindToSymbol);
    }

    VarCommand(std::string name, Expression value) {
        this->name = name;
        SymbolsTable::getInstance()->setSymbol(name, value.calculate());
    }

    double execute() override {
        return SymbolsTable::getInstance()->getSymbolValue(name);
    }

};


#endif //FLIGHTGEARINTERPRETER_VARCOMMAND_H
