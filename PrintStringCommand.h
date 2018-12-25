#ifndef FLIGHTGEARINTERPRETER_PRINTCOMMAND_H
#define FLIGHTGEARINTERPRETER_PRINTCOMMAND_H


#include <string>
#include <iostream>
#include "Command.h"
#include "Utils.h"
#include "SymbolsTable.h"

using namespace std;

class PrintStringCommand : public Command {

    string strToPrint;

public:
// TODO change to Expression and String?
    /**
     * handles string
     *
     * @param symbol
     */
    PrintStringCommand(string strToPrint) : strToPrint(move(strToPrint)) {}

    double execute() override {
        cout << strToPrint << endl;
        return 0;
    }
};


#endif //FLIGHTGEARINTERPRETER_PRINTCOMMAND_H
