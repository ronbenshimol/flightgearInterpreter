#ifndef FLIGHTGEARINTERPRETER_UTILS_H
#define FLIGHTGEARINTERPRETER_UTILS_H

#include <vector>
#include <string>
#include <stack>
#include <list>

using namespace std;

class Utils {

public:
    static const std::vector<std::string> explode(std::string &s, const char &c);

    static bool isMathOperator(char c);
    static bool isAnyOperator(char c);
    static bool isAnotherTokenExpectedOperator(char c);
    static bool isPreviousTokenExpectedOperator(char c);


    static stack<string> fromVectorToStack(vector<string> vec);

};



#endif //FLIGHTGEARINTERPRETER_UTILS_H
