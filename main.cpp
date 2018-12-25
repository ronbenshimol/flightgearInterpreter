#include <iostream>

#include "DataReaderServer.h"
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
    //fileContent = "bind \"/con/shnizel\"\nvar";


    vector<string> lexed = lexer.lexString(fileContent);
    parser.parse(lexed);



//    OpenDataServer openDataServerCommand(new Num(5400),new Num(10));
//
//    openDataServerCommand.execute();
//
//    for (int i = 0; i < 100; ++i) {
//
//        cout << "**************************** " << i << endl;
//        sleep(0.2);
//
//    }
//







    //lexer  -  parser checks



//    vector<string> lexed = lex.lexString("while alt!=1000{ \n"
//                                         "brakes=alt \n"
//                                         "}\n");

    //vector<string> lexed = lex.lexString("openDataServer =-3 + my * 2-3/2 2\n");
    //vector<string> lexed = lex.lexString("demo -3+- x - 5 * -7\n open 200 3\n");

//    vector<string> lexed = lex.lexString("while -7=-3{\n");
//    parser.parse(lexed);




//    // shunting checks
//
//    std::string infix = "( -3 / 4 + ( 11 - ( 3 * -2 ) ) / 2 )";//our infix expression
//    //std::string infix = "2 / ( 1 - 5 )";//our infix expression
//    //std::string infix = "-5 * 7";//our infix expression
//    auto postfixStack = ShuntingYard::convertToPostfix(infix);
//    auto exp = parser.stringToMathExpression(postfixStack);
//    double res = exp->calculate();
//
//    string s = "dudu";




//    // commands flow checks
//
//    vector<Command*> forWhile;
//    DemoCommand *demo0 = new DemoCommand("0");
//    DemoCommand *demo1 = new DemoCommand("1");
//    forWhile.push_back(demo0);
//    forWhile.push_back(demo1);
//
//    BooleanExpression *boolToWhile = new Greater(new Num(4), new Num(3));
//
//    Command *c1 = new IfCommand(forWhile, boolToWhile);
//    c1->execute();



//    // math expressions tests
//
//    Expression *e = new Plus(new Neg(new Num(3)), new Div( new Num(10), new Num(5))); // -3 + (10 / 5) = -1
//    double res = e->calculate();
//
//
//    Expression *e2 = new Plus(new Multi(new Neg(new Num(3)), new Minus(new Num(20) , new Num(10))),
//                    new Div( new Num(10), new Num(5))); // (-3 * (20 - 10)) + (10 / 5) = -3*10 + 2 = -30+2 = -28
//    double res2 = e2->calculate();

    // TODO check print of a variable!
    // test print command
//    string s = "print this line";
//    s.push_back('"');
//    s = '"' + s;

//    Command *print = new PrintStringCommand(s);
//    print->execute();


//    // test sleep command - works!
//
//    string s = "print this line";
//    s.push_back('"');
//    s = '"' + s;
//
//    Command *print = new PrintStringCommand(s);
//    print->execute();
//
//
//    Expression *exp = new Multi(new Num(1000), new Num(5));
//    Command *sleep = new SleepCommand(exp);
//    sleep->execute();
//
//    string s2 = "print this line2";
//    s2.push_back('"');
//    s2 = '"' + s2;
//
//    Command *print2 = new PrintStringCommand(s);
//    print2->execute();


    return 0;
}














