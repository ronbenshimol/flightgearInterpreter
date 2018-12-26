#ifndef FLIGHTGEARINTERPRETER_SYMBOLSTABLE_H
#define FLIGHTGEARINTERPRETER_SYMBOLSTABLE_H

#include <mutex>
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include "DataWriterClient.h"

/**
 * a struct that holds the data that a symbol may reference to
 */
struct SymbolData
{
    double value;
    std::string path;

    SymbolData(double value, std::string path = NULL){
        this->value = value;
        this->path = path;
    }
};

/**
 * in charge of the symbol table and keeping track of symbol's values.
 * singleton
 */
class SymbolsTable {

private:
    /* Here will be the instance stored. */
    static SymbolsTable *instance;

    /* Private constructor to prevent instancing. */
    SymbolsTable();

    std::map<std::string, SymbolData*> symbolsMap;
    DataWriterClient *client;
    std::mutex mtx1; //lock for symbols sets
    std::mutex mtx2; //lock for symbols sets
    std::mutex mtx3; //lock for symbols sets


public:
    /* Static access method. */
    static SymbolsTable *getInstance();
    static void destroyInstance();

    static std::vector<std::string> paths;

    void setSymbol(std::string symbol, double value, std::string path);
    void setSymbol(std::string symbol, double value);
    double getSymbolValue(std::string symbol);
    string getSymbolPath(std::string symbol);
    void bindNewSymbolToExistSymbol(std::string newSymbol, std::string existSymbol);
    void printSymbols();
    bool isSymbolExist(std::string symbol);
    DataWriterClient *getClient() const;
    void setClient(DataWriterClient *client);

    ~SymbolsTable();
};


#endif //FLIGHTGEARINTERPRETER_SYMBOLSTABLE_H
