//
// Created by matan on 1/21/20.
//

#ifndef SOLID_SERVER_REDO_BASICSERVER_H
#define SOLID_SERVER_REDO_BASICSERVER_H

#include "IServer.h"

class BasicServer : public server_side::IServer {
private:
    int numOfListeningPorts, numOfUsedPorts;
protected:
    Socket serverSocket;
    int port;
    bool stopped;
    IHandler *handler;
    sockaddr_in address;

public:
    void open(int port, IHandler *handler) override;

    virtual void run() = 0;

    virtual void stop();

protected:
    BasicServer();

    BasicServer(int numOfListeningPorts);

    virtual void solveProblem(string solutionFile, string problemFile, Socket clientSocket);

    bool portsAvailable();

    void closeSocket(Socket socket);

    bool isStopped() const;

    int getNumOfActivePorts();

    int getNumOfPorts();

    virtual Socket createSocket();

    virtual Socket listenAndWait();

    virtual void readData(string fileName, Socket socket);

    virtual void sendData(string fileName, Socket socket);
};


#endif //SOLID_SERVER_REDO_BASICSERVER_H
