//
// Created by shaked on 12/22/18.
//

#ifndef FLIGHTGEARINTERPRETER_DEMOCOMMAND_H
#define FLIGHTGEARINTERPRETER_DEMOCOMMAND_H

#include <iostream>
#include "Command.h"

class DemoCommand : public Command {

    std::string num;
public:

    DemoCommand(const std::string &num) : num(num) {}

    double execute() override {
        std::cout << "demo: " << num << std::endl;
    }

};


#endif //FLIGHTGEARINTERPRETER_DEMOCOMMAND_H
