//
// Created by matan on 1/14/20.
//

#ifndef SOLID_SERVER_REDO_ISEARCHABLE_H
#define SOLID_SERVER_REDO_ISEARCHABLE_H

#include "../State.h"
#include "../Position.h"
#include <vector>

using namespace std;

template<class Position>
class ISearchable {
public:
    virtual State<Position> *getInitialState() = 0;

    virtual State<Position> *getGoalState() = 0;

    virtual double calcHeuristic(State<Position> *current) = 0;

    virtual bool isGoalState(State<Position> *state) = 0;

    virtual vector<State<Position> *> getAllPossibleStates(State<Position> *state) = 0;
};


#endif //SOLID_SERVER_REDO_ISEARCHABLE_H
