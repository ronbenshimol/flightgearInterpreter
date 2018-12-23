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
#include <algorithm>


#include "Expression.h"
#include "Utils.h"
#include "Plus.h"
#include "Minus.h"
#include "Multi.h"
#include "Div.h"
#include "Neg.h"
#include "Num.h"
#include "Var.h"
#include "SymbolsTable.h"



#define OPEN_DATA_SERVER "openDataServer"
#define CONNECT "connect"
#define ASSIGNMENT "="
#define BIND "bind"
#define VAR "var"
#define WHILE "while"
#define IF "if"
#define PRINT "print"
#define SLEEP "sleep"
#define LESSER "<"
#define LESSER_EQUALS "<="
#define GREATER ">"
#define GREATER_EQUALS ">="
#define EQUALS "=="
#define NOT_EQUALS "!="
#define EXIT "exit"



using namespace std;

class Parser {

    map<string, Expression *> stringToExpressionMap;

    stack<Expression *> *expQueue;

    vector<string> toIndependentExpStrings(stack<string> tokensStack);

    bool isProgramSavedWord(string s);

    vector<string> minusDemandsAssurer(vector<string> expVector);

    vector<string> removeCommas(vector<string> vec);

public:
    //Parser();

    void parse(vector<string> lexed);

    //TODO make private after tests
    Expression* stringToMathExpression(stack<string> &tokens);



};


#endif //FLIGHTGEARINTERPRETER_PARSER_H
