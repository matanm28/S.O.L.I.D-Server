//
// Created by matan on 1/20/20.
//

#ifndef SOLID_SERVER_REDO_CLIENTHANDLER_H
#define SOLID_SERVER_REDO_CLIENTHANDLER_H

#define DEFAULT_CAP 5

#include "../CacheManagers/CacheManager.h"
#include <iostream>
#include <fstream>

using namespace std;

template<class Problem, class Solution, class Var>
class ClientHandler {
public:
    virtual void handleClient(ifstream &inputStream, ofstream &outputStream) = 0;

    /*virtual Problem makeProblem(ifstream &inputStream) = 0;

    virtual void writeSolution(ofstream &outputStream, Solution solution) = 0;*/


};


#endif //SOLID_SERVER_REDO_CLIENTHANDLER_H
