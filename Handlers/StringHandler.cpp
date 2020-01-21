//
// Created by matan on 1/20/20.
//

#include "StringHandler.h"


void StringHandler::handleClient(ifstream &inputStream, ofstream &outputStream) {
    string problem = this->makeProblem(inputStream);
    string solution;
    try {
        solution = this->cache->get(problem);
    } catch (char *exception) {
        solution = this->solver->solve(problem);
        this->cache->insert(problem, solution);
    }
    this->writeSolution(outputStream, solution);
}

string StringHandler::makeProblem(ifstream &inputStream) {
    string problem;
    inputStream >> problem;
    return problem;
}

void StringHandler::writeSolution(ofstream &outputStream, string solution) {
    outputStream << solution;
}