/*                     .ed"""" """$$$$be.
                   -"           ^""**$$$e.
                 ."                   '$$$c
                /                      "4$$b
               d  3                      $$$$
               $  *                   .$$$$$$
              .$  ^c           $$$$$e$$$$$$$$.
              d$L  4.         4$$$$$$$$$$$$$$b
              $$$$b ^ceeeee.  4$$ECL.F*$$$$$$$
  e$""=.      $$$$P d$$$$F $ $$$$$$$$$- $$$$$$
 z$$b. ^c     3$$$F "$$$$b   $"$$$$$$$  $$$$*"      .=""$c
4$$$$L        $$P"  "$$b   .$ $$$$$...e$$        .=  e$$$.
^*$$$$$c  %..   *c    ..    $$ 3$$$$$$$$$$eF     zP  d$$$$$
  "**$$$ec   "   %ce""    $$$  $$$$$$$$$$*    .r" =$$$$P""
        "*$b.  "c  *$e.    *** d$$$$$"L$$    .d"  e$$***"
          ^*$$c ^$c $$$      4J$$$$$% $$$ .e*".eeP"
             "$$$$$$"'$=e....$*$$**$cz$$" "..d$*"
               "*$$$  *=%4.$ L L$ P3$$$F $$$P"
                  "$   "%*ebJLzb$e$$$$$b $P"
                    %..      4$$$$$$$$$$ "
                     $$$e   z$$$$$$$$$$%
                      "*$c  "$$$$$$$P"
                       ."""*$$$$$$$$bc
                    .-"    .$***$$$"""*e.
                 .-"    .e$"     "*$c  ^*b.
          .=*""""    .e$*"          "*bc  "*$e..
        .$"        .z*"               ^*$e.   "*****e.
        $$ee$c   .d"                     "*$.        3.
        ^*$E")$..$"                         *   .ee==d%
           $.d$$$*                           *  J$$$e*
            """""    ENTER AT YOU OWN RISK!   "$$$"

*/


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
                "/controls/engines/engine/throttle",
                "/engines/engine/rpm"

        });


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
    if(isSymbolExist(symbol)){
        symbolsMap.at(symbol)->value = value;
    } else{
        symbolsMap[symbol] = new SymbolData(value, path);
    }
}

void SymbolsTable::setSymbol(std::string symbol, double value){
    if(isSymbolExist(symbol)){
        symbolsMap.at(symbol)->value = value;
    } else{
        symbolsMap[symbol] = new SymbolData(value,"");
    }

}

double SymbolsTable::getSymbolValue(std::string symbol){
    return symbolsMap.at(symbol)->value;
}

string SymbolsTable::getSymbolPath(std::string symbol){
    return symbolsMap.at(symbol)->path;
}

void SymbolsTable::bindNewSymbolToExistSymbol(std::string newSymbol, std::string existSymbol){
    if(isSymbolExist(existSymbol)){
        symbolsMap[newSymbol] = symbolsMap[existSymbol];
    }
    else{
        //create and bind new symbol to path
        setSymbol(newSymbol,0,existSymbol);
    }
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
