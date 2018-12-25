/*                     .ed"""" """$$$$be.
                   -"           ^""**$$$e.
                 ."                   '$$$c
                /                      "4$$b
               d  3                      $$$$
               $  *                   .$$$$$$
              .$  ^c           $$$$$e$$$$$$$$.
              d$L  4.         4$$$$$$$$$$$$$$b
              $$$$b ^ceeeee.  4$$ECL.F*$$$$$$$
  e$""=.      $$$$P d$$$$F $ $$$$$$$$$- $$$$$$
 z$$b. ^c     3$$$F "$$$$b   $"$$$$$$$  $$$$*"      .=""$c
4$$$$L        $$P"  "$$b   .$ $$$$$...e$$        .=  e$$$.
^*$$$$$c  %..   *c    ..    $$ 3$$$$$$$$$$eF     zP  d$$$$$
  "**$$$ec   "   %ce""    $$$  $$$$$$$$$$*    .r" =$$$$P""
        "*$b.  "c  *$e.    *** d$$$$$"L$$    .d"  e$$***"
          ^*$$c ^$c $$$      4J$$$$$% $$$ .e*".eeP"
             "$$$$$$"'$=e....$*$$**$cz$$" "..d$*"
               "*$$$  *=%4.$ L L$ P3$$$F $$$P"
                  "$   "%*ebJLzb$e$$$$$b $P"
                    %..      4$$$$$$$$$$ "
                     $$$e   z$$$$$$$$$$%
                      "*$c  "$$$$$$$P"
                       ."""*$$$$$$$$bc
                    .-"    .$***$$$"""*e.
                 .-"    .e$"     "*$c  ^*b.
          .=*""""    .e$*"          "*bc  "*$e..
        .$"        .z*"               ^*$e.   "*****e.
        $$ee$c   .d"                     "*$.        3.
        ^*$E")$..$"                         *   .ee==d%
           $.d$$$*                           *  J$$$e*
            """""   ENTER AT YOUR OWN RISK!   "$$$"

*/


#include "Parser.h"



#define OPEN_DATA_SERVER "openDataServer"


void Parser::parse(vector<string> lexed) {

    stack<string> tokensStack = Utils::fromVectorToStack(lexed);
    //tokens stack is now in the correct order.

    vector<string> allLinesExpStrings;

    // vector of parameters to be parsed to expressions
    vector<string> independentExpStrings = toIndependentExpStrings(tokensStack);

    commandsToExecute = recursiveParse(independentExpStrings);


    executeCommands(commandsToExecute);

}


void Parser::executeCommands(vector<Command *> commands) {
    //TODO finish

    for (auto c: commands){
        c->execute();
    }

}



vector<Command *> Parser::recursiveParse(vector<string> &tokens){

    vector<Command *> commandsForExecute;

    for(std::vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {

        string token = *it;

        if(token == WHILE || token == IF){

            string leftExpToken = *(++it);
            Expression* leftExp = stringToMathExpression(leftExpToken);

            string conditionToken = *(++it);

            string rightExpToken = *(++it);
            Expression* rightExp = stringToMathExpression(rightExpToken);

            int endOfBrackets = 0;
            string currentToken = *(++it);
            if(currentToken == "{") endOfBrackets++;

            vector <string> conditonCommands;

            //iterate until the closing bracket of the conditional command
            while (endOfBrackets != 0){

                string currentToken = *(++it);

                if(currentToken == "{"){

                    endOfBrackets++;
                    conditonCommands.push_back(currentToken);
                }
                else if(currentToken == "}"){

                    endOfBrackets--;
                    if(endOfBrackets != 0){
                        conditonCommands.push_back(currentToken);
                    }
                }
                else {
                    conditonCommands.push_back(currentToken);
                }
            }

            //create condition:
            BooleanExpression* condition = NULL;
            if(conditionToken == GREATER){
                condition= new Greater(leftExp,rightExp);
            } else if(conditionToken == GREATER_EQUALS){
                condition= new GreaterEquals(leftExp,rightExp);
            } else if(conditionToken == EQUALS){
                condition= new Equals(leftExp,rightExp);
            } else if(conditionToken == NOT_EQUALS){
                condition= new NotEquals(leftExp,rightExp);
            } else if(conditionToken == LESSER){
                condition= new Lesser(leftExp,rightExp);
            }  else if(conditionToken == LESSER_EQUALS){
                condition= new LesserEquals(leftExp,rightExp);
            }

            vector<Command *> commands = recursiveParse(conditonCommands);

            ConditionCommand * conditionCommand;

            if(token == WHILE){
                conditionCommand = new WhileCommand(commands,condition);
            } else{
                //if token == IF
                conditionCommand = new IfCommand(commands,condition);
            }

            commandsForExecute.push_back(conditionCommand);

        } else if(token == OPEN_DATA_SERVER){

            string param1 = *(++it);
            Expression* portExp = stringToMathExpression(param1);

            string param2 = *(++it);
            Expression* readsPsExp = stringToMathExpression(param2);

            OpenDataServer* openDataServerCommand = new OpenDataServer(portExp, readsPsExp);
            commandsForExecute.push_back(openDataServerCommand);

        } else if(token == CONNECT){

            string ipAddress = *(++it);

            string param2 = *(++it);
            Expression* portExp = stringToMathExpression(param2);

            ConnectCommand* connectCommand = new ConnectCommand(ipAddress,portExp);
            commandsForExecute.push_back(connectCommand);

        } else if(token == VAR){

            string symbolName = *(++it);

            // token = "=" , skip that token. if not ASSIGNMENT throw exaption
            if(*(++it) != ASSIGNMENT) throw  "invalid token";

            string param = *(++it);

            VarCommand* varCommand;

            //bind symbol
            if(param == BIND){

                string symbolToBindTo;

                string param2 = *(++it);
                //if the token is of the form "bla-bla", the token is path name
                if(Utils::isStringToken(param2)){
                    symbolToBindTo = Utils::contentOfStringToken(param2);

                } else{
                    //bind to regular symbol
                    symbolToBindTo = param2;
                }
                varCommand = new  VarCommand(symbolName,symbolToBindTo);

            } else{
                //the token is math expression
                Expression* mathExp = stringToMathExpression(param);
                varCommand = new VarCommand(symbolName, mathExp);

            }
            commandsForExecute.push_back(varCommand);

        }else if(SymbolsTable::getInstance()->isSymbolExist(token)){
            //assignment (variable = value)
            // token = "=" , skip that token. if not ASSIGNMENT throw exaption
            if(*(++it) != ASSIGNMENT) throw  "invalid token";

            string symbolName = token;

            string param = *(++it);
            Expression* valueExp = stringToMathExpression(param);

            AssignmentCommand* assignmentCommand = new AssignmentCommand(symbolName, valueExp);
            commandsForExecute.push_back(assignmentCommand);

        } else if(token == PRINT){

            //token to print
            string param = *(++it);

            Command* printCommand;

            if(Utils::isStringToken(param)){
                string strToPrint = Utils::contentOfStringToken(param);
                printCommand = new PrintStringCommand(strToPrint);
            } else{
                Expression* expToPrint = stringToMathExpression(param);
                printCommand = new PrintExpressionCommand(expToPrint);
            }
            commandsForExecute.push_back(printCommand);

        } else if(token == SLEEP){

            string param = *(++it);

            Expression* exp = stringToMathExpression(param);
            Command *sleep = new SleepCommand(exp);
            commandsForExecute.push_back(sleep);

        }





    }

    return commandsForExecute;

}

Expression* Parser::stringToMathExpression(string str){
    auto postfix = ShuntingYard::convertToPostfix(str);
    return postfixToMathExpression(postfix);
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

    return mergePartOfStringTokens(mergeBooleanIndependent(removeCommas(minusDemandsAssurer(finalVec))));
}

vector<string> Parser::mergePartOfStringTokens(vector<string> vec) {

    vector<string> ans;

    bool isInsideString = false;

    auto it = vec.begin();
    string toAdd = "";

    for (;it != vec.end() ; it++){
        toAdd += *it;

        if(it->front() == '"' && isInsideString){
            isInsideString = !isInsideString;
            toAdd = Utils::eraseSpaces(toAdd);
            ans.push_back(toAdd);
            toAdd = "";
            continue;
        }
        if (it->front() == '"' && !isInsideString){
            isInsideString = !isInsideString;
            continue;
        }

        if(isInsideString){
            continue;
        }
        ans.push_back(toAdd);
        toAdd = "";
    }
    return ans;


}

vector<string> Parser::mergeBooleanIndependent(vector<string> vec) {
    vector<string> ans;

    auto it = vec.begin();
    string toAdd = "";

    for (;it != vec.end() ; it++){
        toAdd += *it;

        if(it->length() == 1 && Utils::isFirstBooleanOperator(it->at(0)) &&
        (it+1)->length() == 1 && Utils::isSecondBooleanOperator(((it+1))->at(0))){
            continue;
        }
        ans.push_back(toAdd);
        toAdd = "";
    }
    return ans;
}

vector<string> Parser::removeCommas(vector<string> vec) {

    vector<string> ret;

    for (auto s: vec){
        string toAdd;
        if(s.front() == ','){
            toAdd = s.substr(1 , s.length() - 1);
        } else{
            toAdd = s;
        }
        ret.push_back(toAdd);

    }
    return ret;
}


// TODO create a class
bool Parser::isProgramSavedWord(string s) {

    vector<string> savedWords = {OPEN_DATA_SERVER, CONNECT, ASSIGNMENT, BIND, VAR, WHILE, IF, PRINT, SLEEP,
                                 LESSER, LESSER_EQUALS, GREATER, GREATER_EQUALS, EQUALS, NOT_EQUALS, EXIT};

    auto it = std::find(savedWords.begin(), savedWords.end(), s);

    return !(it == savedWords.end());
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



Expression* Parser::postfixToMathExpression(stack<string> &tokens){

    if(tokens.empty()){
        throw "unknown problem";
    }

    string token = tokens.top();
    tokens.pop();

    if(token == "+"){
        Expression* rightExp  = postfixToMathExpression(tokens);
        Expression* leftExp  = postfixToMathExpression(tokens);

        return new Plus(leftExp,rightExp);
    } else if(token == "-"){
        Expression* rightExp  = postfixToMathExpression(tokens);
        Expression* leftExp  = postfixToMathExpression(tokens);

        return new Minus(leftExp,rightExp);
    } else if(token == "*"){
        Expression* rightExp  = postfixToMathExpression(tokens);
        Expression* leftExp  = postfixToMathExpression(tokens);
        return new Multi(leftExp,rightExp);
    } else if(token == "/"){
        Expression* rightExp  = postfixToMathExpression(tokens);
        Expression* leftExp  = postfixToMathExpression(tokens);
        return new Div(leftExp,rightExp);
    } else if(token.length() > 1 && token.at(0) == '-'){
        string tokenWithoutNeg = token.substr(1 ,token.length() - 1);
        tokens.push(tokenWithoutNeg);
        Expression* unaryExp  = postfixToMathExpression(tokens);
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

}

Parser::~Parser(){

    for (int i = 0; i < commandsToExecute.size(); ++i) {
        delete commandsToExecute[i];
    }

}




