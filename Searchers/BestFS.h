//
// Created by sapir on 14/01/2020.
//

#ifndef SOLID_SERVER_REDO_BESTFS_H
#define SOLID_SERVER_REDO_BESTFS_H


#include "Searcher.h"
#include "ISearcher.h"
#include "../Searchables/ISearchable.h"
#include "../State.h"
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <stack>

using namespace std;
//Solution is vector<State<Var>>:
template<class Solution, class Var>
class BestFS : public Searcher<Solution, Var> {
public:
    Solution search(ISearchable<Var>* searchable) {
        this->addToOpenList(searchable->getInitialState());
        vector<State<Var>*>* closed = new vector<State<Var>*>();
        while (this->openListSize() > 0) {
            State<Var>* n = this->popOpenList();
            closed->push_back(n);
            //if n is goal - we reached the best path
            if (searchable->isGoalState(n)) {
                vector<State<Var>*>* trace = this->backTrace(closed);
                return trace;
            }
            vector<State<Var>*> succerssors = searchable->getAllPossibleStates(n);
            for (State<Var>* s: succerssors) {
                //if not in closed and not in openList - add to open
                if (!this->isInOpenList(s) && !this->isInClosed(closed,s)) {
                    this->addToOpenList(s);
                } else {
                    double curr_trial = n->getTrialCost();
                    double potential_trial = s->getTrialCost();
                    //if this new path has better cost than previous one
                    //operator by cost
                    if (potential_trial < curr_trial) {
                        //if not in  open - add it to open
                        if (!this->isInOpenList(s)) {
                            this->addToOpenList(s);
                        } else {
                            //in open, so udjust its priority in openList
                            this->updateOpenList(s);
                        }
                    }
                }
            }
        }
        throw "no path exists";
    }

    bool isInClosed(vector<State<Var>*>* closed, State<Var>* state) {
        for(int i = 0; i < closed->size(); i++) {
            if(*closed->at(i) == *state) {
                return true;
            }
        }
        return false;
    }

    Solution backTrace(vector<State<Var>*>* closed) {
        vector<State<Var>*> *trace = new vector<State<Var>*>();
        State<Var>* tempState = closed->at(closed->size()-1);
        while(tempState != nullptr) {
            trace->push_back(tempState);
            tempState = tempState->getCameFrom();
        }
        return trace;
    }
};

#endif //SOLID_SERVER_REDO_BESTFS_H
