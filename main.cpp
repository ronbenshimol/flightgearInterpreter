#include <iostream>

#include "DataReaderServer.h"
#include "Lexer.h"
#include "Parser.h"
#include "SymbolsTable.h"
#include <thread>
#include "ShuntingYard.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

//    std::thread serverThread([](int port, int numOfReadsPS){
//
//        DataReaderServer server(port,numOfReadsPS);
//        server.openServer();
//
//        },5400,10);
//
//
//    SymbolsTable::getInstance()-> bindSymbolToPath("rudder","/controls/flight/rudder");
//    SymbolsTable::getInstance()-> bindSymbolToPath("throttle","/controls/engines/engine/throttle");
//
//    serverThread.join();


    //std::string infix = "3 ^ 4 + ( 11 - ( 3 * 2 ) ) / 2";//our infix expression
    //std::string infix = "2 / ( 1 - 5 )";//our infix expression
    std::string infix = "-5 * 7";//our infix expression

    auto postfixStack = ShuntingYard::convertToPostfix(infix);


    while(!postfixStack.empty())
    {
        cout<<postfixStack.top() << ">";
        postfixStack.pop();
    }
    Lexer lex;
    Parser parser;

    //vector<string> lexed = lex.lexString("demo =0 + 2-3/2 2\n");
    vector<string> lexed = lex.lexString("demo -3 * 7\n");
    parser.parse(lexed);

    //-5 /\t8 * 12 22"

    //parser.executeStringVector(lexed);

    return 0;
}