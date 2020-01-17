//
// Created by sapir on 14/01/2020.
//

#include "Matrix.h"

Matrix::Matrix() {
    vector<vector<double> > vect{ {1, 0.0, 0.0,100 },
                               { 1, 1, 100, 200 },
                               { 1, 0.0, 1, 1 } };

    vector<vector<double> > vect1{ {1,0.0,0.0,100},
                                 {1,1,100,200},
                                   {1,0,1,1}};
    this->matrix = vect1;
    this->init = new State<Position>(Position(0,0), 1.0, 1.0, NULL);
    this->goal = new State<Position>(Position(2,3),1);
}

State<Position>* Matrix::getInitialState() {
    return this->init;
}

bool Matrix::isGoalState(State<Position>* state) {
    return (*state == *this->goal);
}

vector<State<Position>*> Matrix::getAllPossibleStates(State<Position>* state) {
    Position pos = state->getState();
    int i, j;
    i = pos.getRow();
    j = pos.getCol();
    vector<State<Position>*> adj;
    //up
    if (this->isInBoundaries(i - 1, j)) {
        State<Position>* s = new State<Position>(Position(i - 1,j), this->matrix[i - 1][j],this->matrix[i - 1][j] + state->getTrialCost(), state, "Up");
        adj.push_back(s);
    }
    //down
    if (this->isInBoundaries(i + 1, j)) {
        adj.push_back(new State<Position>(Position(i + 1, j), this->matrix[i + 1][j],this->matrix[i + 1][j] + state->getTrialCost(), state, "Down"));
    }
    //left
    if (this->isInBoundaries(i, j - 1)) {
        adj.push_back(new State<Position>(Position(i, j - 1), this->matrix[i][j - 1],this->matrix[i][j - 1] + state->getTrialCost(), state, "Left"));
    }
    //right
    if (this->isInBoundaries(i, j + 1)) {
        adj.push_back(new State<Position>(Position(i, j + 1), this->matrix[i][j + 1],this->matrix[i][j + 1] + state->getTrialCost(), state, "Right"));
    }
    return adj;
}

bool Matrix::isInBoundaries(int row, int col) {
    return (0 <= row && row <= this->matrix.size() - 1) && (0 <= col && col <= this->matrix[0].size() - 1);

}
