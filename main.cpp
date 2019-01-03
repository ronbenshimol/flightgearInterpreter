
#include <iostream>
#include <fstream>

#include "interpreter/Lexer.h"
#include "interpreter/Parser.h"

/**
 * reads all file content to string
 * @param fileName
 * @return string with content
 */
string fromFile(string fileName){

    std::ifstream t(fileName);
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    return str;

}

/**
 * runs the program.
 * @param argc num of program arguments
 * @param argv char ** of program arguments
 * @return status
 */
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














