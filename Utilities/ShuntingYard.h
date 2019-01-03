#ifndef FLIGHTGEARINTERPRETER_SHUNTINGYARD_H
#define FLIGHTGEARINTERPRETER_SHUNTINGYARD_H

#include <iostream>
#include <iterator>
#include <stack>
#include <sstream>
#include <vector>
#include <string.h>

using namespace std;
/**
 * given a string in infix, converts to postfix
 */
class ShuntingYard {

public:
    static stack<string> convertToPostfix(string infix);

private:
    static bool TryParse(const std::string &symbol);
    static int Priority(const std::string &c);
    static bool isOperator(const std::string &c);

};


#endif //FLIGHTGEARINTERPRETER_SHUNTINGYARD_H
