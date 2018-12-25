#ifndef FLIGHTGEARINTERPRETER_SYMBOLSTABLE_H
#define FLIGHTGEARINTERPRETER_SYMBOLSTABLE_H

#include <mutex>
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include "DataWriterClient.h"

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
    DataWriterClient *client;
    std::mutex mtx; //lock for symbols sets


public:
    /* Static access method. */
    static SymbolsTable *getInstance();
    static void destroyInstance();

    //static std::string paths[23];
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
