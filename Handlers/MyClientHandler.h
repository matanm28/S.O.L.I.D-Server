//
// Created by matan on 1/20/20.
//

#ifndef SOLID_SERVER_REDO_MYCLIENTHANDLER_H
#define SOLID_SERVER_REDO_MYCLIENTHANDLER_H


#include "../CacheManagers/CacheManager.h"
#include "../Searchables/ISearchable.h"
#include "../Solver/ISolver.h"
#include "ClientHandler.h"
#include "../Position.h"
#include <string>
#include <vector>
#include "../State.h"
#include "../Position.h"

using namespace std;

template<class Problem, class Solution, class Var>
class MyClientHandler : public ClientHandler<Problem, Solution, Var> {
protected:
    ISolver<Problem, Solution> *solver;
    CacheManager<Solution> *cache;

    MyClientHandler(ISolver<ISearchable<Var> *, Solution> *solver, CacheManager<Solution> *cache) {
        this->solver = solver;
        this->cache = cache;
    }

public:
    virtual void handleClient(ifstream &inputStream, ofstream &outputStream) override {
        ISearchable<Var> *searchable = this->makeProblem(inputStream);
        Solution solution;
        try {
            solution = this->cache->get(searchable->toString());
        } catch (char *exception) {
            //todo check for possible exception here
            solution = this->solver->solve(searchable);
            this->cache->insert(searchable->toString(), solution);
        }
        this->writeSolution(outputStream, solution);
    }
};

#endif //SOLID_SERVER_REDO_MYCLIENTHANDLER_H
