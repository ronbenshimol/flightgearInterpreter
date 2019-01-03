#include <list>
#include "Lexer.h"


/**
 * segregates line by whitespaces
 * @param line
 * @return
 */
vector<string> Lexer::lexString(string line) {

    vector<string> splitedVec = splitBy(line, ' ', '\t');
    vector<string> splitedTouched;

    for(string s: splitedVec){
        vector<string> toAdd = splitTouchingExpressions(s);
        for(string add: toAdd){
            splitedTouched.push_back(add);
        }

    }

    //return splitedTouched;

    vector<string> noNewLineStrings;

    for(auto s: splitedTouched){
        if(s != "\n")
            noNewLineStrings.push_back(s);
    }
    return noNewLineStrings;

}

vector<string> Lexer::splitTouchingExpressions(string s) {
    string buff{""};
    vector<string> v;

    for (char n : s)
    {
        if (!Utils::isAnyOperator(n))
            buff += n;
        else if (Utils::isAnyOperator(n))
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




/**
 * splits by any whitespace (\n needs unknown treatment)
 *
 * @param s
 * @param c
 * @return
 */
vector<string> Lexer::splitBy(string &s, const char &c , char c2)
{
    string buff{""};
    vector<string> v;
    //remove EOL
    //s = s.substr(0,s.length()-2);

    for (auto n : s)
    {
        if (n != c && n != c2)
            buff += n;
        else if ((n == c || n==c2) && buff != "")
        {
            v.push_back(buff);
            buff = "";
        }
    }
    if (buff != "")
        v.push_back(buff);

    return v;
}

