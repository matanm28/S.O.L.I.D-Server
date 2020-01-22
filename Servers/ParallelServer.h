//
// Created by matan on 1/21/20.
//

#ifndef SOLID_SERVER_REDO_PARALLELSERVER_H
#define SOLID_SERVER_REDO_PARALLELSERVER_H

#include "BasicServer.h"
#include <thread>
#include <vector>

class ParallelServer : public BasicServer {
private:
    vector<bool> filesArr;

    int getAvailableIndex();

    void freeFile(int index);

protected:
    void solveProblem(string solutionFile, string problemFile, Socket clientSocket, string number);

public:
    ParallelServer(int numOfListeningPorts);

    ParallelServer();

    void run() override;

};


#endif //SOLID_SERVER_REDO_PARALLELSERVER_H
