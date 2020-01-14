//
// Created by sapir on 14/01/2020.
//

#include "Matrix.h"

Matrix::Matrix() {
    this->matrix[0] = {1,2,3};
    this->matrix[1] = {0,4,5};
    this->matrix[2] = {0,0,0};
    this->init = new State<Position>(Position(0,0));
    this->goal = new State<Position>(Position(2,2));
}

State<Position> Matrix::getInitialState() {
    return *this->init;
}

bool Matrix::isGoalState(State<Position> state) {
    return (state == *this->goal);
}

vector<State<Position>> Matrix::getAllPossibleStates(State<Position> state) {
    Position pos = state.getState();
    int i, j;
    i = pos.getRow();
    j = pos.getCol();
    vector<State<Position>> adj;
    //up
    if (this->isInBoundaries(i - 1, j)) {
        adj.push_back(State<Position>(Position(i - 1, j), this->matrix[i - 1][j] + state.getCost(), &state));
    }
    //down
    if (this->isInBoundaries(i + 1, j)) {
        adj.push_back(State<Position>(Position(i + 1, j), this->matrix[i + 1][j] + state.getCost(), &state));
    }
    //left
    if (this->isInBoundaries(i, j - 1)) {
        adj.push_back(State<Position>(Position(i, j - 1), this->matrix[i][j - 1] + state.getCost(), &state));
    }
    //right
    if (this->isInBoundaries(i, j + 1)) {
        adj.push_back(State<Position>(Position(i, j + 1), this->matrix[i][j + 1] + state.getCost(), &state));
    }
    return adj;
}

bool Matrix::isInBoundaries(int row, int col) {
    return (0 <= row && row <= this->matrix[0].size() - 1) && (0 <= col && col <= this->matrix.size() - 1);

}
