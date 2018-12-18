//
// Created by shaked on 12/16/18.
//

#ifndef FLIGHTGEARINTERPRETER_LEXER_H
#define FLIGHTGEARINTERPRETER_LEXER_H


#include <vector>
#include <string>

using namespace std;


class Lexer {


    vector<string> virtual splitBy(string &s, const char &c);



public:

    vector<string> virtual lexString(string line);

    bool isMathOperator(char c);
    bool isAnyOperator(char c);
    vector<string> splitTouchingExpressions(string s);
};





#endif //FLIGHTGEARINTERPRETER_LEXER_H
