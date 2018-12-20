#ifndef FLIGHTGEARINTERPRETER_UTILS_H
#define FLIGHTGEARINTERPRETER_UTILS_H

#include <vector>
#include <string>

class Utils {

public:
    static const std::vector<std::string> explode(std::string &s, const char &c);

    static bool isMathOperator(char c);
    static bool isAnyOperator(char c);

};



#endif //FLIGHTGEARINTERPRETER_UTILS_H
