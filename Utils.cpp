#include "Utils.h"

const std::vector<std::string> Utils::explode(std::string &s, const char &c){

    std::string buff{""};
    std::vector<std::string> v;
    //remove EOL
    //s = s.substr(0,s.length()-2);

    for (auto n : s)
    {
        if (n != c)
            buff += n;
        else if (n == c && buff != "")
        {
            v.push_back(buff);
            buff = "";
        }
    }
    if (buff != "")
        v.push_back(buff);

    return v;

}

bool Utils::isMathOperator(char c) {
    return (c == '+' || c == '-' || c =='/' || c == '*' );
}

//TODO ',' case in parser!!!
bool Utils::isAnyOperator(char c) {
    return isMathOperator(c) || c == '=' || c == '(' || c == ')' || c == ',' ||
    c == '\n' || c == '<' || c == '>' || c == '!' || c == '{' || c == '}' ;
}

bool Utils::isFirstBooleanOperator(char c) {
    return  c == '!' || c == '=' || c == '<' || c == '>';
}

bool Utils::isSecondBooleanOperator(char c) {
    return c == '=';
}


bool Utils::isPreviousTokenExpectedOperator(char c) {
    return isMathOperator(c) || c == '(' || c == ')';
}

bool Utils::isAnotherTokenExpectedOperator(char c) {
    return (isMathOperator(c) || c == '(');
}

stack<string> Utils::fromVectorToStack(vector<string> vec) {

    stack<string> retStack;
    stack<string> tempStack;

    //push to a stack
    for(string s: vec)
        tempStack.push(s);
    //flips all using temp stack
    while(!tempStack.empty()){
        string cur = tempStack.top();
        tempStack.pop();
        retStack.push(cur);
    }
    //tokens stack is now in the correct order.

    return retStack;

}


bool Utils::isStringToken(string s) {
    return s.front() == '"' && s.back() == '"';
}

string Utils::contentOfStringToken(string s) {
    if (!Utils::isStringToken(s))
        throw "contentOfStringToken only usable on a string token!";
    return s.substr(1,s.length() - 2);
}

