//
// Created by shaked on 12/22/18.
//

#ifndef FLIGHTGEARINTERPRETER_COMMAND_H
#define FLIGHTGEARINTERPRETER_COMMAND_H


class Command {

public:
    virtual double execute() = 0;
    virtual ~Command() = default;
};


#endif //FLIGHTGEARINTERPRETER_COMMAND_H
