//
// Created by sapir on 14/01/2020.
//

#include "BestFS.h"


template<class Var>
vector<State<Var>> BestFS<Var>::search(ISearchable<Var>* searchable) {
    this->addToOpenList(searchable->getInitialState());
    priority_queue<State<Var>> closed;
    while (this->openListSize() > 0) {
        State<Var> n = this->popOpenList();
        closed.push_back(n);
        //if n is goal - we reached the best path
        if (searchable->isGoalState(n)) {
            return backTrace(searchable, n);
        }
        vector<State<Var>> succerssors = searchable->getAllPossibleStates(n);
        for (State<Var> s: succerssors) {
            //if not in closed and not in openList - add to open
            if (!this->isInOpenList(s) && this->isInClosed(s, closed)) {
                this->addToOpenList(s);
            } else {
                //if this new path has better cost than previous one
                //operator by cost
                if (s < findState(s)) {
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
}

template<class Var>
State<Var> BestFS<Var>::findState(ISearchable<Var>* searchable, priority_queue<State<Var>> closed, State<Var> state) {
    //check in openList
    if (this->isInOpenList(state)) {
        return this->getState(state);
    } else {
        auto iter = std::find(closed.begin(), closed.cend(), state);
        return *iter;
    }
}

template<class Var>
State<Var> BestFS<Var>::backTrace(ISearchable<Var>* searchable, State<Var> state) {
    vector<State<Var>> trace;
    trace.push_front(state);
    while (state != searchable->getInitialState()) {
        state = state.getCameFrom();
        trace.push_front(state);
    }
    trace.push_front(state);
    return trace;
}