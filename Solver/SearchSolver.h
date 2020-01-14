//
// Created by matan on 1/14/20.
//

#ifndef SOLID_SERVER_REDO_SEARCHSOLVER_H
#define SOLID_SERVER_REDO_SEARCHSOLVER_H

#include "ISolver.h"

template <class Problem, class Solution, class Position>
class SearchSolver : public ISolver<Problem,Solution>{
private:
    ISearcher<Position>* searcher;
public:
    SearchSolver(Isearcher<Position>* searcher){searcher(searcher)};
    Solution solve(Problem problem) override {
        return this->searcher.search(problem);
    }
};


#endif //SOLID_SERVER_REDO_SEARCHSOLVER_H
