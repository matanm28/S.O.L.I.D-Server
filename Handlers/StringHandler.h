//
// Created by matan on 1/20/20.
//

#ifndef SOLID_SERVER_REDO_STRINGHANDLER_H
#define SOLID_SERVER_REDO_STRINGHANDLER_H

#include "ClientHandler.h"
#include "../Solver/ISolver.h"
#include "../Solver/StringReverser.h"
#include "../CacheManagers/CacheManager.h"
#include <string>

using namespace std;

class StringHandler : public ClientHandler<string, string, string> {
private:
    ISolver<string, string> *solver;
    CacheManager<string> *cache;
public:
    StringHandler();

    void handleClient(ifstream &inputStream, ofstream &outputStream) override;

protected:
    string makeProblem(ifstream &inputStream);

    void writeSolution(ofstream &outputStream, string solution);


};


#endif //SOLID_SERVER_REDO_STRINGHANDLER_H
