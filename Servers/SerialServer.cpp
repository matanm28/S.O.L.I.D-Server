//
// Created by matan on 1/21/20.
//

#include "SerialServer.h"

SerialServer::SerialServer() : BasicServer() {}

SerialServer::SerialServer(int numOfListeningPorts) : BasicServer(1) {}

void SerialServer::run() {
    while (!this->isStopped()) {
        if (this->portsAvailable()) {
            Socket clientSocket = this->listenAndWait();
            if (clientSocket == -1) {
                continue;
            }
            this->solveProblem(OUTPUT_FILE, INPUT_FILE, clientSocket);
            this->closeSocket(clientSocket);
        }
    }
}

