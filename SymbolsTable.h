#ifndef FLIGHTGEARINTERPRETER_SYMBOLSTABLE_H
#define FLIGHTGEARINTERPRETER_SYMBOLSTABLE_H

#include <string>
#include <map>

class SymbolsTable {

private:
    /* Here will be the instance stored. */
    static SymbolsTable *instance;

    /* Private constructor to prevent instancing. */
    SymbolsTable();

    std::map<std::string, std::string> pathToSymbolMap;
    std::map<std::string, double> symbolsMap;

public:
    /* Static access method. */
    static SymbolsTable *getInstance();

    void setSymbol(std::string symbol, double value);
    double getValue(std::string symbol);
    void updateLocalValueByPath(std::string path, double value);



};


#endif //FLIGHTGEARINTERPRETER_SYMBOLSTABLE_H
