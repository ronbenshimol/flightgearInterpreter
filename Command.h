//
// Created by shaked on 12/16/18.
//

#ifndef FLIGHTGEARINTERPRETER_COMMAND_H
#define FLIGHTGEARINTERPRETER_COMMAND_H

#include <vector>
#include <string>

using namespace std;

class Command {

public:
    virtual /**
     * executes the appropriate command
     * promotes the index if additional parameters are needed. 1 minimum!
     * @return
     */
    int execute(vector<string> stringVec, int index) = 0;

};


#endif //FLIGHTGEARINTERPRETER_COMMAND_H
