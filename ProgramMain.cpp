//
// Created by shaked on 12/23/18.
//

#include <string>
#include <fstream>
#include <sstream>
#include "Lexer.h"
#include "Parser.h"

using namespace std;

void runScope(string scope){

    Lexer lexer;
    Parser parser;

    vector<string> lexed = lexer.lexString(scope);
    parser.parse(lexed);

}


void fromFile(string fileName){

    std::ifstream in(fileName);
    std::stringstream buffer;
    buffer << in.rdbuf();
    in.close();

}

int My_main(int argc, char **argv) {

    return 0;
}


