//
// Created by matan on 1/20/20.
//

#ifndef SOLID_SERVER_REDO_MATRIXHANDLER_H
#define SOLID_SERVER_REDO_MATRIXHANDLER_H

#define NUM_OF_LINES_CONSTANT 4

#include "MyClientHandler.h"
#include "../Searchables/Matrix.h"
#include "../MatrixBuilder.h"
#include "../Position.h"
#include <vector>

class MatrixHandler : public MyClientHandler<vector<State<Position> *>, Position> {
public:
    MatrixHandler(ISolver<ISearchable<Position> *, vector<State<Position> *>> *solver,
                  CacheManager<string> *cache);

    MatrixHandler(ISolver<ISearchable<Position> *, vector<State<Position> *>> *solver);

protected:
    ISearchable<Position> *makeProblem(ifstream &inputStream) override;

    void writeSolution(ofstream &outputStream, vector<State<Position> *> solution) override;

    void writeSolution(string solution, ofstream &outputStream) override;

    string solutionToString(vector<State<Position> *> solution) override;

};


#endif //SOLID_SERVER_REDO_MATRIXHANDLER_H
