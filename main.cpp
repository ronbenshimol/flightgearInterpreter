
#include <iostream>

#include "DataReaderServer.h"
#include "Lexer.h"
#include "Parser.h"

int main(int argc, char **argv) {
    std::cout << "Hello, World!" << std::endl;

    Lexer lex;
    Parser parser;

    //vector<string> lexed = lex.lexString("demo =0 + 2-3/2 2\n");
    vector<string> lexed = lex.lexString("demo -3 * 7\n");
    parser.parse(lexed);

    //-5 /\t8 * 12 22"

    //parser.executeStringVector(lexed);

    return 0;
}



int programMain(int argc, char **argv) {



}
