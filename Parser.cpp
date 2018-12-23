


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

    vector<string> allLinesExpStrings;



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

    vector<string> vecOnBuild;

    if (tokensStack.empty())
        return vecOnBuild;


    // loop on the different tokens
    string cur = "";
    string next = "";
    while (!tokensStack.empty()) {

        string expStr = "";
        bool finishedIndependent = false;

        while (!finishedIndependent) {

            cur = tokensStack.top();

            expStr.append(cur);
            expStr.append(" ");
            tokensStack.pop();

            if(tokensStack.empty())
                break;
            next = tokensStack.top();

            // check if cur was *not* an operator that another token is expected afterwards
            bool isAnotherExpected = Utils::isAnotherTokenExpectedOperator(expStr.at(expStr.length() - 2));
            bool isPrevExpected;
            // if exp is not a saved word
            string checkSavedWord = expStr.substr(0, expStr.length() - 1);
            if (!isProgramSavedWord(checkSavedWord)){
                isPrevExpected = next.length() == 1 && Utils::isPreviousTokenExpectedOperator(next.at(0));
            }else{
                isPrevExpected = false;
            }

            if (isPrevExpected )
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

    return minusDemandsAssurer(finalVec);
}



// TODO create a class
bool Parser::isProgramSavedWord(string s) {
    return s == "demo";
}


vector<string> Parser::minusDemandsAssurer(vector<string> expVector) {

    vector<string> assuredVec;

    for(auto s: expVector){
        string toAdd = "";
        auto it = s.begin();

        for(; it != s.end() ; it++){
            if(*(it-1) == '-' && ((it-1) == s.begin() || Utils::isAnyOperator(*(it-3))) ){
                //delete the cur space by not adding him!
                continue;
            }
            toAdd.push_back(*it);
        }
        assuredVec.push_back(toAdd);
    }

    return assuredVec;
}



Expression* Parser::stringToMathExpression(stack<string> &tokens){

    if(tokens.empty()){
        throw "unknown problem";
    }

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
    } else if(token == "/"){
        Expression* rightExp  = stringToMathExpression(tokens);
        Expression* leftExp  = stringToMathExpression(tokens);
        return new Div(leftExp,rightExp);
    } else if(token.length() > 1 && token.at(0) == '-'){
        string tokenWithoutNeg = token.substr(1 ,token.length() - 1);
        tokens.push(tokenWithoutNeg);
        Expression* unaryExp  = stringToMathExpression(tokens);
        return new Neg(unaryExp);
    } else if (SymbolsTable::getInstance()->isSymbolExist(token)){
        return new Var(token);
    } else{
        //num
        double value;
        try {
            value = stod(token);
        }catch(...){
            throw "problem in shunting yard tree";
        }
        return new Num(value);
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






