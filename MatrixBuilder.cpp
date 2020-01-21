//
// Created by sapir on 19/01/2020.
//

#include "MatrixBuilder.h"

Matrix* MatrixBuilder::buildMatrix(ifstream &inFile) {
    string line;
    vector<vector<double>> matrix;
    vector<vector<string>> lines;
    State<Position>* init = nullptr;
    State<Position>* goal = nullptr;
    char buffer[BUFFER_SIZE];
    while (!inFile.eof()) {
        inFile.getline(buffer, BUFFER_SIZE, LINE_DELIM);
        line.append(buffer);
        //bzero(buffer, BUFFER_SIZE);
        //get all file and stuck - dont know why..
//        while (line.find(LINE_DELIM) == string::npos) {
//            inFile.getline(buffer, BUFFER_SIZE, LINE_DELIM);
//            line.append(buffer);
//            bzero(buffer, BUFFER_SIZE);
//        }
        string row = line.substr(0, line.find(LINE_DELIM));
        line.erase(0, line.find(LINE_DELIM) + 1);
        vector<string> matrixStringRow = splitString(row, CELLS_DELIM);
        lines.push_back(matrixStringRow);
        line ="";
    }
    inFile.clear();
    inFile.seekg(0, ios::beg);
    bool initFlag = true;
    for (vector<string> vec: lines) {
        if(vec[0] != "end") {
            if (vec.size() == 2) {
                int row = stoi(vec[0]);
                int col = stoi(vec[1]);
                if (initFlag) {
                    init = new State<Position>(Position(row,col), matrix[row][col], matrix[row][col], nullptr);
                    initFlag = false;
                } else {
                    goal = new State<Position>(Position(row,col), matrix[row][col]);
                }
            } else {
                matrix.push_back(this->createVector(vec));
            }
        } else {
            break;
        }
    }
    Matrix* m = new Matrix(matrix, init, goal);
    return m;
}

vector<string> MatrixBuilder::splitString(string source, const string &delimiter) {
    vector<string> tokensList;
    size_t pos = 0;
    string token;
    while ((pos = source.find(delimiter)) != std::string::npos) {
        token = source.substr(0, pos);
        tokensList.push_back(token);
        source.erase(0, pos + delimiter.length());
    }
    tokensList.push_back(source);
    return tokensList;
}

vector<double> MatrixBuilder::createVector(vector<string> stringVector) {
    vector<double> matrixRow;
    for (const string &str :stringVector) {
        double num;
        try {
            num = stod(str);
        } catch (exception &e) {
            cerr << "Failed for: " + str << endl;
            num = DEFAULT_VALUE;
        }
        matrixRow.push_back(num);
    }
    return matrixRow;
}


