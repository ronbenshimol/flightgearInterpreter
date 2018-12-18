//
// Created by shaked on 12/16/18.
//

#ifndef FLIGHTGEARINTERPRETER_PARSER_H
#define FLIGHTGEARINTERPRETER_PARSER_H

#include <vector>
#include <string>
#include <map>
#include "Command.h"
#include "DemoCommand.h"
#include "Expression.h"

#include <queue>

using namespace std;

class Parser {

    map<string, Command *> stringToCommandMap;
    queue<Expression *> *expQueue;

    queue<Expression *> *parseLineToExpressionQueue(queue<string> tokensQueue);

    string getNextExpStr(queue<string> tokensQueue);


public:
    //Parser();
    void virtual executeStringVector(vector<string> stringVec);

    void parse(vector<string> lexed);

};


#endif //FLIGHTGEARINTERPRETER_PARSER_H
