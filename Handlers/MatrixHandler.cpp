//
// Created by matan on 1/20/20.
//

#include "MatrixHandler.h"


MatrixHandler::MatrixHandler(ISolver<ISearchable<Position> *, vector<State<Position> *>> *solver,
                             CacheManager<vector<State<Position> *>> *cache) : MyClientHandler(solver, cache) {

}

ISearchable<Position> *MatrixHandler::makeProblem(ifstream &inputStream) {
    MatrixBuilder mb;
    ISearchable<Position> *matrix = mb.buildMatrix(inputStream);
    return matrix;
}

void MatrixHandler::writeSolution(ofstream &outputStream, vector<State<Position> *> solution) {
    unsigned int numOfLines, count;
    numOfLines = solution.size() / NUM_OF_LINES_CONSTANT;
    count = 0;
    for (State<Position> *state: solution) {
        outputStream << state->getDirection() << ", ";
        if (count == numOfLines) {
            count = 0;
            outputStream << endl;
        } else {
            count++;
        }
    }
}

