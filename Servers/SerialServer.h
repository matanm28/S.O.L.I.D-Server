//
// Created by matan on 1/21/20.
//

#ifndef SOLID_SERVER_REDO_SERIALSERVER_H
#define SOLID_SERVER_REDO_SERIALSERVER_H

#include "BasicServer.h"

class SerialServer : public BasicServer {
public:
    SerialServer();

    SerialServer(int numOfListeningPorts);

    void run() override;

};


#endif //SOLID_SERVER_REDO_SERIALSERVER_H
