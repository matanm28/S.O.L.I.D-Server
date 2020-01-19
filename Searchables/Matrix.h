//
// Created by sapir on 14/01/2020.
//

#ifndef SOLID_SERVER_REDO_MATRIX_H
#define SOLID_SERVER_REDO_MATRIX_H

#define INFINITY -1
#include "ISearchable.h"
#include "../Position.h"
#include <vector>

using namespace std;

class Matrix : public ISearchable<Position> {
private:
    vector<vector<double>> matrix;
    State<Position> *init, *goal;

    bool isInBoundaries(int row, int col);

public:
    Matrix();

    Matrix(vector<vector<double>> matrix,  State<Position> *init,  State<Position> *goal);

        double calcHeuristic(State<Position>* current) override;

    State<Position>* getInitialState() override;

    State<Position>* getGoalState() override;

    bool isGoalState(State<Position>* state) override;

    vector<State<Position>*> getAllPossibleStates(State<Position>* state) override;

};


#endif //SOLID_SERVER_REDO_MATRIX_H
