//
// Created by shaked on 12/22/18.
//

#ifndef FLIGHTGEARINTERPRETER_COMMAND_H
#define FLIGHTGEARINTERPRETER_COMMAND_H


class Command {

public:
    double virtual execute() = 0;

};


#endif //FLIGHTGEARINTERPRETER_COMMAND_H
