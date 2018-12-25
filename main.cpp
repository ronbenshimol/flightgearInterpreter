#include <iostream>

#include "Lexer.h"
#include "Parser.h"
#include "SymbolsTable.h"
#include <thread>
#include <fstream>
#include "ShuntingYard.h"
#include "Neg.h"
#include "Num.h"
#include "Div.h"
#include "Command.h"
#include "WhileCommand.h"
#include "Equals.h"
#include "IfCommand.h"
#include "Greater.h"
#include "PrintStringCommand.h"
#include "SleepCommand.h"


void runScope(string scope){

    Lexer lexer;
    Parser parser;

    vector<string> lexed = lexer.lexString(scope);
    parser.parse(lexed);

}

string fromFile(string fileName){

    std::ifstream t(fileName);
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    return str;

}

int main(int argc, char **argv) {

    Lexer lexer;
    Parser parser;

    if (argc < 2)
        throw "usage: scriptName fileToInterpret";
    string fileName = argv[1];
    string fileContent;

    fileContent = fromFile(fileName);

    vector<string> lexed = lexer.lexString(fileContent);
    parser.parse(lexed);

    return 0;
}














