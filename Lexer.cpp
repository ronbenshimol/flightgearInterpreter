//
// Created by shaked on 12/16/18.
//

#include <list>
#include "Lexer.h"


/**
 * segregates line by whitespaces
 * @param line
 * @return
 */
vector<string> Lexer::lexString(string line) {

    vector<string> splitedVec = splitBy(line, ' ');
    vector<string> splitedTouched;

    for(string s: splitedVec){
        vector<string> toAdd = splitTouchingExpressions(s);
        for(string add: toAdd){
            splitedTouched.push_back(add);
        }

    }

    return splitedTouched;
}

vector<string> Lexer::splitTouchingExpressions(string s) {
    string buff{""};
    vector<string> v;

    for (char n : s)
    {
        if (!isAnyOperator(n))
            buff += n;
        else if (isAnyOperator(n))
        {
            v.push_back(buff);
            buff = "";
            string temp = "";
            temp.push_back(n);
            v.push_back(temp);
        }
    }
    if (buff != "")
        v.push_back(buff);

    vector<string> ret;
    for(string str: v){
        if(!str.empty())
            ret.push_back(str);
    }

    return ret;
}

bool Lexer::isMathOperator(char c) {
    return (c == '+' || c == '-' || c =='/' || c == '*' || c == '%');
}

bool Lexer::isAnyOperator(char c) {
    return isMathOperator(c) || c == '=' || c == '(' || c == ')';
}


/**
 * splits by any whitespace (\n needs unknown treatment)
 *
 * @param s
 * @param c
 * @return
 */
vector<string> Lexer::splitBy(string &s, const char &c)
{
    string buff{""};
    vector<string> v;
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

