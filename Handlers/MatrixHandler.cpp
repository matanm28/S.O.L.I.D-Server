//
// Created by matan on 1/20/20.
//

#include "MatrixHandler.h"


MatrixHandler::MatrixHandler(ISolver<ISearchable<Position> *, vector<State<Position> *> *> *solver,
                             CacheManager<string> *cache) : MyClientHandler(solver, cache) {}

MatrixHandler::MatrixHandler(ISolver<ISearchable<Position> *, vector<State<Position> *> *> *solver) : MyClientHandler(
        solver) {}

ISearchable<Position> *MatrixHandler::makeProblem(ifstream &inputStream) {
    MatrixBuilder mb;
    ISearchable<Position> *matrix = mb.buildMatrix(inputStream);
    return matrix;
}

void MatrixHandler::writeSolution(ofstream &outputStream, vector<State<Position> *> *solution) {
    this->writeSolution(this->solutionToString(solution), outputStream);
}

string MatrixHandler::solutionToString(vector<State<Position> *> *solution) {
    unsigned int numOfLines, count;
    string outputString;
    numOfLines = solution->size() / NUM_OF_LINES_CONSTANT;
    count = 0;
    for (long i = solution->size() - 2; i >= 0; i--) {
        outputString.append(solution->at(i)->getDirection());
        if (i) {
            outputString.append(", ");
        }
        if (count == numOfLines) {
            count = 0;
            outputString.append("\n");
        } else {
            count++;
        }
    }
    return outputString;
}

void MatrixHandler::writeSolution(string solution, ofstream &outputStream) {
    outputStream << solution;
}

