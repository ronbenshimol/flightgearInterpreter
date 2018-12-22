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

SymbolsTable::SymbolsTable(){


    for (int i = 0; i < paths->length(); ++i) {

        //the symbol name as exist in the simulator paths
        std::string symbolName = SymbolsTable::getInstance()->paths[i];

        SymbolsTable::getInstance() -> setSymbol(symbolName, 0, symbolName);

        //TODO: temp line
        SymbolsTable::getInstance() ->printSymbols();
    }

}

/**
 *
 * @param symbol,value,path
 * @return void
 * description : gets the symbol name, the value, and the path to bind to in the simulator
 *
 */
void SymbolsTable::setSymbol(std::string symbol, double value, std::string path){
    symbolsMap[symbol] = new SymbolData(value,path);
}

double SymbolsTable::getSymbolValue(std::string symbol){
    return symbolsMap[symbol]->value;
}

void SymbolsTable::bindNewSymbolToExistSymbol(std::string newSymbol, std::string existSymbol){
    symbolsMap[newSymbol] = symbolsMap[existSymbol];
}

void SymbolsTable::printSymbols(){
    for(auto elem : symbolsMap)
    {
        std::cout << elem.first << ": " << elem.second->value << "  ";
    }

    std::cout << std::endl;
}

bool  SymbolsTable::isSymbolExist(std::string symbol){
    return !(symbolsMap.find(symbol) == symbolsMap.end());
}
