//
// Created by sapir on 15/01/2020.
//

#ifndef SOLID_SERVER_REDO_DFS_H
#define SOLID_SERVER_REDO_DFS_H

#include "Searcher.h"
#include "ISearcher.h"
#include "../Position.h"
#include "../Searchables/ISearchable.h"
#include "../State.h"
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <stack>

using namespace std;

template <class Solution, class Var>
class DFS : public Searcher<Solution, Var>{
public:
    Solution search(ISearchable<Var> *searchable) override {
        stack<State<Var>*> stack;
        vector<State<Var>*> marked;
        vector<State<Var>*> adj;
        State<Var>* currState;
        stack.push(searchable->getInitialState());
        while(!stack.empty()) {
            currState = stack.top();
            stack.pop();
            //if currState is goal - we got a path from init to goal
            if(searchable->isGoalState(currState)) {
                marked.push_back(currState);
                return backTrace(marked);
            }
            if(isMark(marked, currState)) {
                continue;
            }
            marked.push_back(currState);
            adj = searchable->getAllPossibleStates(currState);
            for (State<Var>* a: adj) {
                stack.push(a);
            }
        }
        cerr<<"there is no path"<<endl;
    }

    bool isMark(vector<State<Var>*> marked, State<Var>* state) {
        for(int i = 0; i < marked.size(); i++) {
            if(*marked[i] == *state) {
                return true;
            }
        }
        return false;
    }

    Solution backTrace(vector<State<Var>*> marked) {
        vector<State<Var>*> trace;
        State<Var>* tempState = marked[marked.size()-1];
        while(tempState != NULL) {
            trace.push_back(tempState);
            tempState = tempState->getCameFrom();
        }
        return trace;
    }


};



#endif //SOLID_SERVER_REDO_DFS_H
