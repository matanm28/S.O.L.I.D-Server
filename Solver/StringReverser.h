//
// Created by matan on 1/20/20.
//

#ifndef SOLID_SERVER_REDO_STRINGREVERSER_H
#define SOLID_SERVER_REDO_STRINGREVERSER_H

#include "ISolver.h"
#include <string>
#include <utility>

using namespace std;

class StringReverser : public ISolver<string, string> {
public:
    string solve(string problem) override;
};


#endif //SOLID_SERVER_REDO_STRINGREVERSER_H
