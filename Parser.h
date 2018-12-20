//
// Created by shaked on 12/16/18.
//

#ifndef FLIGHTGEARINTERPRETER_PARSER_H
#define FLIGHTGEARINTERPRETER_PARSER_H

#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>

#include "Expression.h"
#include "Utils.h"
#include "Plus.h"
#include "Minus.h"
#include "Multi.h"
#include "SymbolsTable.h"



using namespace std;

class Parser {

    map<string, Expression *> stringToExpressionMap;

    stack<Expression *> *expQueue;

    vector<string> toIndependentExpStrings(stack<string> tokensStack);

    Expression* stringToMathExpression(stack<string> &tokens);

    bool isProgramSavedWord(string s);

    vector<string> minusDemandsAssurer(vector<string> expVector);

public:
    //Parser();

    void parse(vector<string> lexed);




    //void virtual executeStringVector(vector<string> stringVec);


};


#endif //FLIGHTGEARINTERPRETER_PARSER_H
