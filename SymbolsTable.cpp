#include "SymbolsTable.h"

/* Null, because instance will be initialized on demand. */
SymbolsTable *SymbolsTable::instance = 0;

SymbolsTable *SymbolsTable::getInstance()
{
    //TODO: delete instance at the end


    //singleton instance:
    if (instance == 0)
    {
        instance = new SymbolsTable();

    }

    return instance;
}

void SymbolsTable::setSymbol(std::string symbol, double value){
    symbolsMap[symbol] = value;
}

double SymbolsTable::getValue(std::string symbol){
    return symbolsMap[symbol];
}

void SymbolsTable::updateLocalValueByPath(std::string path, double value){

    std::string symbolToUpdate = pathToSymbolMap[path];
    if(!symbolToUpdate.empty())
        setSymbol(symbolToUpdate, value);

}
