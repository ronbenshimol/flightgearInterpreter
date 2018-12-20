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
    return (c == '+' || c == '-' || c =='/' || c == '*' || c == '%');
}

bool Utils::isAnyOperator(char c) {
    return isMathOperator(c) || c == '=' || c == '(' || c == ')' || c == ',';
}