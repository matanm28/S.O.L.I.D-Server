//
// Created by sapir on 18/01/2020.
//

#ifndef SOLID_SERVER_REDO_ASTAR_H
#define SOLID_SERVER_REDO_ASTAR_H

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
class Astar : public Searcher<Solution, Var> {
public:
    Solution search(ISearchable<Var>* searchable) {
        searchable->getInitialState()->setHeuristicCost(0);
        this->addToOpenList(searchable->getInitialState());
        vector<State<Var> *> *closed = new vector<State<Var>*>();
        while (this->openListSize() > 0) {
            State<Var> *n = this->popOpenList();
            closed->push_back(n);
            //if n is goal - we reached the best path
            if (searchable->isGoalState(n)) {
                return this->backTrace(closed);
            }
            vector<State<Var> *> succerssors = searchable->getAllPossibleStates(n);
            for (State<Var> *s: succerssors) {
                s->setHeuristicCost(searchable->calcHeuristic(s));
                double potential_f = s->getTrialCost() + s->getHeuristicCost();
                double curr_f = n->getTrialCost() + n->getHeuristicCost();
                // if a node with the same position as successor is in the OPEN list
                // which has a lower f than successor, skip this successor
                if(this->isInOpenList(s) && potential_f > curr_f) {
                    continue;
                }
                // if a node with the same position as
                // successor  is in the CLOSED list which has
                // a lower f than successor, skip this successor
                //otherwise, add the node to the open list
                if(isInClosed(closed, s) && potential_f > curr_f) {
                    continue;
                } else {
                    if (!this->isInOpenList(s)) {
                        this->addToOpenList(s);
                    } else {
                        this->updateOpenList(s);
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


#endif //SOLID_SERVER_REDO_ASTAR_H
