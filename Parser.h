//
// Created by shaked on 12/16/18.
//

#ifndef FLIGHTGEARINTERPRETER_PARSER_H
#define FLIGHTGEARINTERPRETER_PARSER_H

#include <vector>
#include <string>
#include <map>
#include "Expression.h"
#include "Utils.h"

#include <queue>
#include <stack>


using namespace std;

class Parser {

    map<string, Expression *> stringToExpressionMap;

    stack<Expression *> *expQueue;

    vector<string> toIndependentExpStrings(stack<string> tokensStack);

    string getNextExpStr(queue<string> tokensQueue);


public:
    //Parser();

    void parse(vector<string> lexed);




    //void virtual executeStringVector(vector<string> stringVec);


};


#endif //FLIGHTGEARINTERPRETER_PARSER_H
