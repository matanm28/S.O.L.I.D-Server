//
// Created by matan on 1/14/20.
//

#ifndef SOLID_SERVER_REDO_SEARCHER_H
#define SOLID_SERVER_REDO_SEARCHER_H

#include "ISearcher.h"
#include "../State.h"
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
template <class Solution, class Position>
class Searcher : public ISearcher<Solution,Position> {
private:
    priority_queue<State<Position>> openList;
    int evaluatedNum;
protected:
    void addToOpenList(State<Position> state);

    int getNumberOfNodesEvaluated();

    State<Position> popOpenList();

    int openListSize();

    bool isInOpenList(State<Position> state);

    void updateOpenList(State<Position> state);

    State<Position> getState(State<Position> state);

public:

    Searcher();

    virtual Solution search(ISearchable<Position> iSearchable)= 0;
};


#endif //SOLID_SERVER_REDO_SEARCHER_H
