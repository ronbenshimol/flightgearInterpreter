


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

    stack<string> tokensStack = Utils::fromVectorToStack(lexed);
    //tokens stack is now in the correct order.

    // vector of parameters to be parsed to expressions
    vector<string> independentExpStrings = toIndependentExpStrings(tokensStack);

    string s = "cool";
    //TODO finish...

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

    if (tokensStack.empty() || tokensStack.top() == "\n")
        return vecOnBuild;

    // loop on the different tokens
    string cur = "";
    string next = "";
    while (tokensStack.top() != "\n") {

        string expStr = "";
        bool finishedIndependent = false;

        while (!finishedIndependent) {

            cur = tokensStack.top();

            expStr.append(cur);
            expStr.append(" ");
            tokensStack.pop();
            next = tokensStack.top();

            // check if cur was *not* an operator that another token is expected afterwards
            bool isAnotherExpected = Utils::isAnotherTokenExpectedOperator(expStr.at(expStr.length() - 2));
            bool isPrevExpected = next.length() == 1 && Utils::isPreviousTokenExpectedOperator(next.at(0));
            if (isPrevExpected)
                continue;
            if (!(isAnotherExpected)){
                finishedIndependent = true;
            }

        }
        vecOnBuild.push_back(expStr);
    }

    vector<string> finalVec;
    for(auto s: vecOnBuild)
        finalVec.push_back(s.substr(0, s.length() - 1));

    return finalVec;
}


Expression* Parser::stringToMathExpression(stack<string> &tokens){

    string token = tokens.top();
    tokens.pop();

    if(token == "+"){
        Expression* rightExp  = stringToMathExpression(tokens);
        Expression* leftExp  = stringToMathExpression(tokens);

        return new Plus(leftExp,rightExp);
    } else if(token == "-"){
        Expression* rightExp  = stringToMathExpression(tokens);
        Expression* leftExp  = stringToMathExpression(tokens);

        return new Minus(leftExp,rightExp);
    } else if(token == "*"){
        Expression* rightExp  = stringToMathExpression(tokens);
        Expression* leftExp  = stringToMathExpression(tokens);

        return new Multi(leftExp,rightExp);
    }

    //TODO: take care of Neg (-)

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






