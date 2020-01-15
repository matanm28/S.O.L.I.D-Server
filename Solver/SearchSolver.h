//
// Created by matan on 1/14/20.
//

#ifndef SOLID_SERVER_REDO_SEARCHSOLVER_H
#define SOLID_SERVER_REDO_SEARCHSOLVER_H

#include "ISolver.h"
#include "../Searchers/ISearcher.h"

template <class Problem, class Solution, class Var>
class SearchSolver : public ISolver<Problem,Solution>{
private:
public:
    ISearcher<Solution, Var>* searcher;
    //Algorithm Searcher throw the constructor
    SearchSolver(ISearcher<Solution, Var>* searcher) {
        this->searcher = searcher;
    }
    //the searchable as parameter
    Solution solve(Problem problem) override {
        return this->searcher->search(problem);
    }
};


#endif //SOLID_SERVER_REDO_SEARCHSOLVER_H
