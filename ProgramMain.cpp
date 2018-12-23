//
// Created by shaked on 12/23/18.
//

#include <string>
#include <fstream>
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
    ifstream in;
    //in.open()

}

int My_main(int argc, char **argv) {


}


