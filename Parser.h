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


#include "ShuntingYard.h"
#include "Expression.h"
#include "Command.h"
#include "Utils.h"
#include "Plus.h"
#include "Minus.h"
#include "Multi.h"
#include "Div.h"
#include "Neg.h"
#include "Num.h"
#include "Var.h"
#include "SymbolsTable.h"
#include "BooleanExpression.h"
#include "Greater.h"
#include "GreaterEquals.h"
#include "Equals.h"
#include "NotEquals.h"
#include "Lesser.h"
#include "LesserEquals.h"
#include "ConditionCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "OpenDataServer.h"
#include "ConnectCommand.h"
#include "VarCommand.h"
#include "AssignmentCommand.h"
#include "PrintStringCommand.h"
#include "PrintExpressionCommand.h"
#include "SleepCommand.h"


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

    vector<string> toIndependentExpStrings(stack<string> tokensStack);

    bool isProgramSavedWord(string s);

    vector<string> minusDemandsAssurer(vector<string> expVector);

    vector<string> removeCommas(vector<string> vec);

    vector<string> mergeBooleanIndependent(vector<string> vec);

    vector<string> mergePartOfStringTokens(vector<string> vec);

    vector<Command *> recursiveParse(vector<string> &tokens);

    Expression* postfixToMathExpression(stack<string> &tokens);

    Expression* stringToMathExpression(string str);

    void executeCommands(vector<Command *> commands);

public:

    void parse(vector<string> lexed);

};


#endif //FLIGHTGEARINTERPRETER_PARSER_H
