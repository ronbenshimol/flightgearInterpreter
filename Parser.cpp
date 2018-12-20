


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
//    this->stringToExpressionMap = mapToAssign;
//
//    // TODO delete
//}




void Parser::parse(vector<string> lexed) {
    stack<string> tokensStack;
    stack<string> tempStack;

    //push to a stack
    for(string s: lexed)
        tempStack.push(s);
    //flips all using temp stack
    while(!tempStack.empty()){
        string cur = tempStack.top();
        tempStack.pop();
        tokensStack.push(cur);
    }
    //tokens stack is now in the correct order.

    vector<string> independentExpStrings = toIndependentExpStrings(tokensStack);

}

/**
 *
 * @param tokensStack
 * @return returns a vector<string> of strings that are meant to be expressions.
 * example :
 * for tokens: open 3 + 4 5
 * return : open , 3 + 4 , 5
 */
vector<string> Parser::toIndependentExpStrings(stack<string> tokensStack) {
    //TODO do

    vector<string> vecOnBuild;
    //TODO free
    if (tokensStack.empty() || tokensStack.top() == "\n")
        return vecOnBuild;

    // loop on the different tokens
    string cur = "";

    while (tokensStack.top() != "\n") {

        string expStr = "";
        bool finishedIndependent = false;

        while (!finishedIndependent) {

            cur = tokensStack.top();
            expStr.append(cur);
            tokensStack.pop();

            //if the len is 1 (only 1 char) and this char is any operator

            // TODO check if previous was an operator that another token is expected afterwards
            if (*(expStr.end())) {
                // TODO add to exp
            }

        }
    }
    
    return vecOnBuild;
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







//
//
//
///**
// * gets a string vector from lexer
// * creates the appropriate expressions/commands and executes.
// */
//void Parser::executeStringVector(vector<string> stringVec) {
//
//    //index that points on the next string to interpret
//    int index = 0;
//
//    //interpret loop
//    while (index < stringVec.size()){
//
//        Command *c = stringToExpressionMap.at(stringVec.at(index));
//        if (c != NULL){
//            // index is promoted by 1 + any additional required parameter used by execute
//            index += c->execute(stringVec, index);
//
//        }
//    }
//
//}






