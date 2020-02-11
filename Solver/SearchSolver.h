//
// Created by matan on 1/14/20.
//

#ifndef SOLID_SERVER_REDO_SEARCHSOLVER_H
#define SOLID_SERVER_REDO_SEARCHSOLVER_H

#include "ISolver.h"
#include "../Searchers/ISearcher.h"
#include <mutex>

template <class Problem, class Solution, class Var>
class SearchSolver : public ISolver<Problem, Solution> {
private:
    mutex locker;

public:
    ISearcher<Solution, Var> *searcher;

    //Algorithm Searcher throw the constructor
    SearchSolver(ISearcher<Solution, Var> *searcher) {
        this->searcher = searcher;
    }

    //the searchable as parameter
    Solution solve(Problem problem) override {
        this->locker.lock();
        Solution solution = this->searcher->search(problem);
        this->locker.unlock();
        return solution;
    }
};


#endif //SOLID_SERVER_REDO_SEARCHSOLVER_H
