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
    static bool isFirstBooleanOperator(char c);
    static bool isSecondBooleanOperator(char c);
    static bool isStringToken(string s);
    static string contentOfStringToken(string s);
    static string eraseSpaces(string s);


    static stack<string> fromVectorToStack(vector<string> vec);

};



#endif //FLIGHTGEARINTERPRETER_UTILS_H
