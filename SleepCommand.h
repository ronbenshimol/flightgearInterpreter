//
// Created by shaked on 12/23/18.
//

#ifndef FLIGHTGEARINTERPRETER_SLEEPCOMMAND_H
#define FLIGHTGEARINTERPRETER_SLEEPCOMMAND_H

#include <chrono>
#include <thread>

#include "Command.h"
#include "Expression.h"


/**
 * receives string to print
 */
class SleepCommand : public Command {

    Expression *exp;

public:

    SleepCommand(Expression *exp) : exp(exp) {}

    double execute() override {

        int timeToSleep = (int) exp->calculate();

        std::this_thread::sleep_for(std::chrono::milliseconds(timeToSleep));

        return 0;
    }

};


#endif //FLIGHTGEARINTERPRETER_SLEEPCOMMAND_H
