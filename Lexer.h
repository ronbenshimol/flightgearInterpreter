#ifndef FLIGHTGEARINTERPRETER_LEXER_H
#define FLIGHTGEARINTERPRETER_LEXER_H


#include <vector>
#include <string>
#include "Utils.h"

using namespace std;


class Lexer {


    vector<string> virtual splitBy(string &s, const char &c, char c2);

    vector<string> splitTouchingExpressions(string s);

public:

    vector<string> virtual lexString(string line);



};





#endif //FLIGHTGEARINTERPRETER_LEXER_H
