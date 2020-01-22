//
// Created by sapir on 19/01/2020.
//

#ifndef SOLID_SERVER_REDO_MATRIXBUILDER_H
#define SOLID_SERVER_REDO_MATRIXBUILDER_H
#define BUFFER_SIZE 256
#define LINE_DELIM '\n'
#define CELLS_DELIM ","
#define DEFAULT_VALUE 0

#include "Searchables/Matrix.h"
#include "Position.h"
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
class MatrixBuilder {
public:
    Matrix *buildMatrix(ifstream &inFile);

    vector<string> splitString(string source, const string &delimiter);

    vector<double> createVector(vector<string> stringVector);

private:
    bool checkLegalRow(string row);
};


#endif //SOLID_SERVER_REDO_MATRIXBUILDER_H
