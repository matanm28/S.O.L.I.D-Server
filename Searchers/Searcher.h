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
template <class Solution, class Var>
class Searcher : public ISearcher<Solution,Var> {
private:
    priority_queue<State<Var>> openList;
    int evaluatedNum;
protected:
    void addToOpenList(State<Var> state) {
        this->openList.push(state);
    }

    int getNumberOfNodesEvaluated() {
        return this->evaluatedNum;
    }

    State<Var> popOpenList() {
        this->evaluatedNum++;
        State<Var> popState = this->openList.top();
        this->openList.pop();
        return popState;
    }

    int openListSize() {
        return this->openList.size();
    }

    bool isInOpenList(State<Var> state) {
        return (std::find(openList.cbegin(), openList.cend(), state) != this->openList.cend());
    }


    State<Var> getState(State<Var> state) {
        auto iter = std::find(openList.cbegin(), openList.cend(), state);
        return *iter;
    }

    void updateOpenList(State<Var> state) {
        priority_queue<State<Var>> temp;
        while (!this->openList.empty()) {
            State<Var> tempState = this->openList.top();
            this->openList.pop();
            if (state == tempState) {
                temp.push(state);
            } else {
                temp.push(tempState);
            }
        }
        this->openList = temp;
    }
//    void addToOpenList(State<Var> state);
//
//    int getNumberOfNodesEvaluated();
//
//    State<Var> popOpenList();
//
//    int openListSize();
//
//    bool isInOpenList(State<Var> state);
//
//    void updateOpenList(State<Var> state);
//
//    State<Var> getState(State<Var> state);

public:
    Searcher() {
        this->evaluatedNum = 0;
    }
    virtual Solution search(ISearchable<Var>* iSearchable) = 0;
};


#endif //SOLID_SERVER_REDO_SEARCHER_H
