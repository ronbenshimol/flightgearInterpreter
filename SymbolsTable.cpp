#include "SymbolsTable.h"


std::string SymbolsTable::paths[23] = {
        "/instrumentation/airspeed-indicator/indicated-speed-kt",
        "/instrumentation/altimeter/indicated-altitude-ft",
        "/instrumentation/altimeter/pressure-alt-ft",
        "/instrumentation/attitude-indicator/indicated-pitch-deg",
        "/instrumentation/attitude-indicator/indicated-roll-deg",
        "/instrumentation/attitude-indicator/internal-pitch-deg",
        "/instrumentation/attitude-indicator/internal-roll-deg",
        "/instrumentation/encoder/indicated-altitude-ft",
        "/instrumentation/encoder/pressure-alt-ft",
        "/instrumentation/gps/indicated-altitude-ft",
        "/instrumentation/gps/indicated-ground-speed-kt",
        "/instrumentation/gps/indicated-vertical-speed",
        "/instrumentation/heading-indicator/indicated-heading-deg",
        "/instrumentation/magnetic-compass/indicated-heading-deg",
        "/instrumentation/slip-skid-ball/indicated-slip-skid",
        "/instrumentation/turn-indicator/indicated-turn-rate",
        "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
        "/controls/flight/aileron",
        "/controls/flight/elevator",
        "/controls/flight/rudder",
        "/controls/flight/flaps",
        "/controls/engines/engine/throttle",
        "/engines/engine/rpm"
};


/* Null, because instance will be initialized on demand. */
SymbolsTable *SymbolsTable::instance = 0;

SymbolsTable *SymbolsTable::getInstance()
{
    //TODO: delete instance at the end

    //singleton instance:
    if (instance == NULL)
    {
        instance = new SymbolsTable();
    }
    return instance;
}

SymbolsTable::SymbolsTable(){

    //init the default symbols of the simulator
    for (int i = 0; i < SymbolsTable::paths->length(); ++i) {

        //the symbol name as exist in the simulator paths
        std::string symbolName = SymbolsTable::paths[i];

        setSymbol(symbolName, 0, symbolName);

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

    if(isSymbolExist(symbol)){
        symbolsMap[symbol]->value = value;
    } else{
        symbolsMap[symbol] = new SymbolData(value,path);
    }
}

double SymbolsTable::getSymbolValue(std::string symbol){
    return symbolsMap[symbol]->value;
}

void SymbolsTable::bindNewSymbolToExistSymbol(std::string newSymbol, std::string existSymbol){
    if(isSymbolExist(existSymbol)){
        symbolsMap[newSymbol] = symbolsMap[existSymbol];
    }
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
