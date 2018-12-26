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

/**
 * parsing and execution flow.
 */
class Parser {

    // holds all commands waiting for execution
    vector<Command *> commandsToExecute;
    /**
     * parses tokens from lexer to independent tokens so that every token is meant to be an expression
     * @param tokensStack stack of lexer tokens
     * @return  vector of exp tokens
     */
    vector<string> toIndependentExpStrings(stack<string> tokensStack);

    /**
     * checks whether a string is a program saved word.
     * @param s the word
     * @return answer
     */
    bool isProgramSavedWord(string s);
    // ahead helper functions for to independent exp strings
    vector<string> minusDemandsAssurer(vector<string> expVector);

    vector<string> removeCommas(vector<string> vec);

    vector<string> mergeBooleanIndependent(vector<string> vec);

    vector<string> mergePartOfStringTokens(vector<string> vec);
    /**
     * in charge of creating the commands given independent exp tokens
     * @param tokens all exp tokens
     * @return vector of commands*
     */
    vector<Command *> recursiveParse(vector<string> &tokens);
    /**
     * parses postfix string to a math expression
     * @param tokens tokens
     * @return and expression
     */
    Expression* postfixToMathExpression(stack<string> &tokens);
    /**
     * parses a string to a math expression
     * @param str that is a math expression!
     * @return and expression
     */
    Expression* stringToMathExpression(string str);
    /**
     * executes all commands from a vector
     * @param commands commands to execute
     */
    void executeCommands(vector<Command *> commands);

public:
    /**
     * on charge of parse flow
     * @param lexed vector of tokens from lexer
     */
    void parse(vector<string> lexed);
    ~Parser();
};


#endif //FLIGHTGEARINTERPRETER_PARSER_H
