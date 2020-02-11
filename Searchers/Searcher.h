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
class MyComperator {
public:
    bool operator()(State<Var>* left, State<Var>* right) {
        return (*left > *right);
    }
};

private:
    priority_queue<State<Var>*, vector<State<Var>*>, MyComperator> openList;
    int evaluatedNum;
protected:
    void addToOpenList(State<Var>* state) {
        this->openList.push(state);
    }

    int getNumberOfNodesEvaluated() {
        return this->evaluatedNum;
    }

    State<Var>* popOpenList() {
        this->evaluatedNum++;
        State<Var>* popState = this->openList.top();
        this->openList.pop();
        return popState;
    }

    int openListSize() {
        return this->openList.size();
    }

    bool isInOpenList(State<Var>* state) {
        priority_queue<State<Var>*, vector<State<Var>*>, MyComperator> temp = this->openList;
        while (!temp.empty()) {
            State<Var>* tempState = temp.top();
            temp.pop();
            if (*state == *tempState) {
                return true;
            }
        }
        return false;
    }

    void updateOpenList(State<Var>* state) {
        priority_queue<State<Var>*, vector<State<Var>*>, MyComperator> temp;
        while (!this->openList.empty()) {
            State<Var> *tempState = this->openList.top();
            this->openList.pop();
            if (*state == *tempState) {
                temp.push(state);
            } else {
                temp.push(tempState);
            }
        }
        this->openList = temp;
    }

    void emptyList() {
        while (!this->openList.empty()) {
            this->openList.pop();
        }
    }

public:
    Searcher() {
        this->evaluatedNum = 0;
    }

    virtual Solution search(ISearchable<Var> *iSearchable) = 0;

};


#endif //SOLID_SERVER_REDO_SEARCHER_H
