#include "SymbolsTable.h"

std::vector<std::string> SymbolsTable::paths(
        {
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
                "/controls/engines/current-engine/throttle",
                "/engines/engine/rpm"

        });


/* Null, because instance will be initialized on demand. */
SymbolsTable *SymbolsTable::instance = 0;

SymbolsTable *SymbolsTable::getInstance()
{

    //singleton instance:
    if (instance == NULL)
    {
        instance = new SymbolsTable();
    }
    return instance;
}

void SymbolsTable::destroyInstance(){
    //delete singleton instance
    if(instance != 0)
    {
        delete instance;
        instance = 0;
    }
}

SymbolsTable::SymbolsTable(){

    //init the default symbols of the simulator
    for (int i = 0; i < SymbolsTable::paths.size(); ++i) {

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
     mtx1.lock();
    if(isSymbolExist(symbol)){
        symbolsMap.at(symbol)->value = value;
    } else{
        symbolsMap[symbol] = new SymbolData(value, path);
    }
    mtx1.unlock();
}

void SymbolsTable::setSymbol(std::string symbol, double value){
    mtx2.lock();
    if(isSymbolExist(symbol)){
        symbolsMap.at(symbol)->value = value;
    } else{
        symbolsMap[symbol] = new SymbolData(value,"");
    }
    mtx2.unlock();
}

double SymbolsTable::getSymbolValue(std::string symbol){
    return symbolsMap.at(symbol)->value;
}

string SymbolsTable::getSymbolPath(std::string symbol){
    return symbolsMap.at(symbol)->path;
}

void SymbolsTable::bindNewSymbolToExistSymbol(std::string newSymbol, std::string existSymbol){
    mtx3.lock();
    if(isSymbolExist(existSymbol)){
        symbolsMap[newSymbol] = symbolsMap[existSymbol];
    }
    else{
        //create and bind new symbol to path
        setSymbol(newSymbol,0,existSymbol);
    }
    mtx3.unlock();
}

void SymbolsTable::printSymbols(){
    for(auto elem : symbolsMap) {
        std::cout << elem.first << ": " << elem.second->value << "  ";
    }
    std::cout << std::endl;
}

bool  SymbolsTable::isSymbolExist(std::string symbol){
    return !(symbolsMap.find(symbol) == symbolsMap.end());
}

DataWriterClient *SymbolsTable::getClient() const {
    return client;
}

void SymbolsTable::setClient(DataWriterClient *client) {
    SymbolsTable::client = client;
}

SymbolsTable::~SymbolsTable(){

    this->client->closeClient();
    delete this->client;


    vector<SymbolData*> elementsToDestroy;
    for(auto elem : symbolsMap) {

        bool isElementExist = false;

        for (int i = 0; i < elementsToDestroy.size(); ++i) {

            if(elem.second == elementsToDestroy[i]){
                isElementExist = true;
                break;
            }

        }

        if(!isElementExist){
            elementsToDestroy.push_back(elem.second);
        }

    }

    for (int i = 0; i < elementsToDestroy.size(); ++i) {

        delete elementsToDestroy[i];

    }

    symbolsMap.clear();

}