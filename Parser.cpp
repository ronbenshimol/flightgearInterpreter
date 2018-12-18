

#include "Parser.h"



#define OPEN_DATA_SERVER "openDataServer"



//Parser::Parser() {
//
//    map<string, Expression *> mapToAssign;
//
//    //mapToAssign.insert(pair<string, Command>(OPEN_DATA_SERVER, openDataServerCommand()))
//
//
//    mapToAssign.insert(pair<string, Expression *>(demo, );
//
//    //TODO insert here any additional command to map
//
//    this->stringToCommandMap = mapToAssign;
//
//    // TODO delete
//}

/**
 * gets a string vector from lexer
 * creates the appropriate expressions/commands and executes.
 */
void Parser::executeStringVector(vector<string> stringVec) {

    //index that points on the next string to interpret
    int index = 0;

    //interpret loop
    while (index < stringVec.size()){

        Command *c = stringToCommandMap.at(stringVec.at(index));
        if (c != NULL){
            // index is promoted by 1 + any additional required parameter used by execute
            index += c->execute(stringVec, index);

        }
    }

}


void Parser::parse(vector<string> lexed) {
    queue<string> tokensQueue;
    for(string s: lexed)
        tokensQueue.push(s);
    this->expQueue = parseLineToExpressionQueue(tokensQueue);

}

queue<Expression *> *Parser::parseLineToExpressionQueue(queue<string> tokensQueue) {
    //TODO do

    queue<Expression *> *queueOnBuild = new queue<Expression *>;
    //TODO free
    if(tokensQueue.empty() || tokensQueue.front() == "\n")
        return queueOnBuild;

    string first = tokensQueue.front();
    tokensQueue.pop();

    string nextExpStr = getNextExpStr(tokensQueue);

    //TODO read all next expressions in line

    return queueOnBuild;
}

//TODO check if next is an operator! if it is, get the next string as well. mind that '('
//TODO is not considered an operator currenty!
string Parser::getNextExpStr(queue<string> tokensQueue) {


    string expStr = "";

    expStr += tokensQueue.front();

    tokensQueue.pop();

    //if ((tokensQueue.front()))

}

//my main:


//
//#include <iostream>
//
//#include "DataReaderServer.h"
//#include "Lexer.h"
//#include "Parser.h"
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//
//    Lexer lex;
//    Parser parser;
//
//    vector<string> lexed = lex.lexString("demo =0 + 2-3/2 2");
//    parser.parse(lexed);
//
//    //-5 /\t8 * 12 22"
//
//    //parser.executeStringVector(lexed);
//
//    return 0;
//}














