#ifndef FLIGHTGEARINTERPRETER_SYMBOLSTABLE_H
#define FLIGHTGEARINTERPRETER_SYMBOLSTABLE_H

#include <string>
#include <map>
#include <iostream>

struct SymbolData
{
    double value;
    std::string path;

    SymbolData(double value, std::string path = NULL){
        this->value = value;
        this->path = path;
    }
};

class SymbolsTable {

private:
    /* Here will be the instance stored. */
    static SymbolsTable *instance;

    /* Private constructor to prevent instancing. */
    SymbolsTable();

    std::map<std::string, SymbolData*> symbolsMap;

public:
    /* Static access method. */
    static SymbolsTable *getInstance();

    void setSymbol(std::string symbol, double value, std::string path = NULL);
    double getSymbolValue(std::string symbol);
    void bindNewSymbolToExistSymbol(std::string newSymbol, std::string existSymbol);
    void printSymbols();
    bool  isSymbolExist(std::string symbol);

    const std::string paths[23] = {
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

};


#endif //FLIGHTGEARINTERPRETER_SYMBOLSTABLE_H
