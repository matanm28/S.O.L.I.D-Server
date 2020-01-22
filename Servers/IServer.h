//
// Created by matan on 1/21/20.
//

#ifndef SOLID_SERVER_REDO_ISERVER_H
#define SOLID_SERVER_REDO_ISERVER_H


#define BUFFER_SIZE 1024
#define DEFAULT_SOCKET 5600
#define END_STATEMENT "end"
#define INPUT_FILE "problem.txt"
#define OUTPUT_FILE "solution.txt"

#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <fstream>
#include <strings.h>
#include <cstring>
#include "../Handlers/IHandler.h"

typedef int Socket;

namespace server_side {
    class IServer;
}

class server_side::IServer {
    virtual void open(int port, IHandler *handler) = 0;

    virtual void run() = 0;

    virtual void stop() = 0;

};

#endif //SOLID_SERVER_REDO_ISERVER_H
