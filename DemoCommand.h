//
// Created by shaked on 12/18/18.
//

#ifndef FLIGHTGEARINTERPRETER_DEMOCOMMAND_H
#define FLIGHTGEARINTERPRETER_DEMOCOMMAND_H

#include "Command.h"

class DemoCommand : public Command  {

public:

    int execute(vector<string> stringVec, int index) override;
};


#endif //FLIGHTGEARINTERPRETER_DEMOCOMMAND_H
