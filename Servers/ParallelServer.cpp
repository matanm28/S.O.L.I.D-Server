//
// Created by matan on 1/21/20.
//

#include "ParallelServer.h"

ParallelServer::ParallelServer(int numOfListeningPorts) : BasicServer(numOfListeningPorts) {
    this->filesArr.assign(numOfListeningPorts, true);
}

ParallelServer::ParallelServer() : BasicServer() {
    this->filesArr.assign(10, true);
}

void ParallelServer::run() {
    while (!this->isStopped()) {
        if (this->portsAvailable()) {
            Socket clientSocket = this->listenAndWait();
            if (clientSocket == -1) {
                continue;
            }
            string solution, problem, number;
            number = to_string(this->getAvailableIndex());
            cout << "Server is now connected, connection ID: " << number << endl;
            solution.append(number);
            solution.append(OUTPUT_FILE);
            problem.append(number);
            problem.append(INPUT_FILE);
            thread *solveThread = new thread(&ParallelServer::solveProblem, this, solution, problem, clientSocket,
                                             number);
            solveThread->detach();
        } else {
            cerr << "queue full" << endl;
            sleep(5);
        }
    }
}

void ParallelServer::solveProblem(string solutionFile, string problemFile, Socket clientSocket, string number) {
    BasicServer::solveProblem(solutionFile, problemFile, clientSocket);
    this->freeFile(stoi(number));
    this->closeSocket(clientSocket);

}

int ParallelServer::getAvailableIndex() {
    int size = this->filesArr.size();
    int i;
    for (i = 0; i < size; i++) {
        if (this->filesArr.at(i)) {
            this->filesArr.at(i) = false;
            return i + 1;
        }
    }
    return i + 1;
}

void ParallelServer::freeFile(int index) {
    this->filesArr.at(index - 1) = true;
}
