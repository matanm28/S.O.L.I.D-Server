//
// Created by matan on 1/21/20.
//

#include "BasicServer.h"

BasicServer::BasicServer(int numOfListeningPorts) : numOfListeningPorts(numOfListeningPorts) {}

BasicServer::BasicServer() {
    this->numOfListeningPorts = 1;
}

void BasicServer::open(int port, IHandler *handler) {
    this->port = port;
    this->handler = handler;
    this->serverSocket = this->createSocket();
    if (this->serverSocket == -1 || this->serverSocket == -2 || this->serverSocket == -3) {
        exit(this->serverSocket);
    }
}

Socket BasicServer::createSocket() {
    //create socket
    Socket socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        cerr << "Could not create a socket" << endl;
        return -1;
    }
    //bind socket to IP address
    //create the sockaddr obj.
    this->address.sin_family = AF_INET;
    //give me any IP allocated for my machine
    this->address.sin_addr.s_addr = INADDR_ANY;
    //convert our port to a number that the network understands.
    this->address.sin_port = htons(this->port);

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cerr << "Could not bind the socket to an IP" << endl;
        return -2;
    }
    //making socket listen to the port
    if (listen(socketfd, numOfListeningPorts) == -1) {
        cerr << "Error during listening command" << endl;
        return -3;
    } else {
        cout << "Server is now listening..." << endl;
        cout << "Listening to " << this->numOfListeningPorts << " clients" << endl;

    }
    return socketfd;
}

Socket BasicServer::listenAndWait() {
    // accepting a client
    int addressLength = sizeof(this->address);
    Socket clientSocket = accept(this->serverSocket, (struct sockaddr *) &(this->address),
                                 (socklen_t *) &addressLength);
    if (clientSocket == -1) {
        cerr << "Error accepting client" << endl;
        return clientSocket;
    }
    this->numOfUsedPorts++;
    return clientSocket;
}

void BasicServer::closeSocket(Socket socket) {
    close(socket);
    this->numOfUsedPorts--;
}

void BasicServer::readData(string fileName, Socket socket) {
    string exactData, prevData, data;
    char buffer[BUFFER];
    int validRead;
    //reading from client
    bzero(buffer, BUFFER);
    validRead = read(socket, buffer, BUFFER);
    data.append(buffer, validRead);
    while (data.find(END_STATEMENT) == string::npos) {
        int currRead = 0;
        bzero(buffer, BUFFER);
        currRead = read(socket, buffer, BUFFER);
        validRead += currRead;
        data.append(buffer, currRead);
    }
    exactData = data.substr(0, data.find(END_STATEMENT));
    ofstream outFile{fileName};
    if (!outFile) {
        cerr << "error opening file" << endl;
        return;
    }
    outFile << exactData << endl;
    outFile.close();
    data.erase(0, data.find(END_STATEMENT) + strlen(END_STATEMENT) + 1);
    //std::cout << exactData << std::endl;
}

void BasicServer::sendData(string fileName, Socket socket) {
    string data;
    char buffer[BUFFER];
    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "error opening file" << endl;
        return;
    }
    while (!inFile.eof()) {
        inFile.getline(buffer, BUFFER);
        data.append(buffer);
        bzero(buffer, BUFFER);
    }
    send(socket, data.c_str(), data.size(), 0);
    cout << "Server sent:" << endl;
    cout << data << endl;
}

void BasicServer::solveProblem(string solutionFile, string problemFile, Socket clientSocket) {
    this->readData(problemFile, clientSocket);
    ifstream inFile(problemFile, ios::in);
    ofstream outFile(solutionFile, ios::out);
    this->handler->handleClient(inFile, outFile);
    inFile.close();
    outFile.close();
    this->sendData(solutionFile, clientSocket);

}

bool BasicServer::portsAvailable() {
    return this->numOfUsedPorts < this->numOfListeningPorts;
}

bool BasicServer::isStopped() const {
    return this->stopped;
}

int BasicServer::getNumOfActivePorts() {
    return this->numOfUsedPorts;
}

void BasicServer::stop() {
    this->stopped = true;
    while (this->getNumOfActivePorts() != 0) {
        sleep(5);
        cout << "Waiting for all ports to close" << endl;
    }
    close(this->serverSocket);
}
