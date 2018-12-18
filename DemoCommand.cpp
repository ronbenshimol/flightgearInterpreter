//
// Created by shaked on 12/18/18.
//

#include <iostream>
#include "DemoCommand.h"

int DemoCommand::execute(vector<string> stringVec, int index) {

    cout << stringVec.at(index) << stringVec.at(index+1) << endl;

    return 2;
}
