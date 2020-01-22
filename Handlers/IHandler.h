//
// Created by matan on 1/21/20.
//

#ifndef SOLID_SERVER_REDO_IHANDLER_H
#define SOLID_SERVER_REDO_IHANDLER_H

#include <iostream>
#include <fstream>

using namespace std;

class IHandler {
public:
    virtual void handleClient(ifstream &inputStream, ofstream &outputStream) = 0;
};


#endif //SOLID_SERVER_REDO_IHANDLER_H
