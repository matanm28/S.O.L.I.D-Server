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
#include "../MatrixBuilder.h"
#include <mutex>

using namespace std;

template<class Solution, class Var>
class MyClientHandler : public ClientHandler<ISearchable<Var> *, Solution, Var> {
protected:
    mutex cacheLock;
    ISolver<ISearchable<Var> *, vector<State<Position> *> *> *solver;
    CacheManager<string> *cache;

    MyClientHandler(ISolver<ISearchable<Var> *, Solution> *solver, CacheManager<string> *cache) {
        this->solver = solver;
        this->cache = cache;
    }

    MyClientHandler(ISolver<ISearchable<Var> *, vector<State<Position> *> *> *solver) {
        this->solver = solver;
        this->cache = new CacheManager<string>(5);
    }

public:
    virtual void handleClient(ifstream &inputStream, ofstream &outputStream) override {
        ISearchable<Var> *searchable = this->makeProblem(inputStream);
        string solutionStr;
        this->cacheLock.lock();
        try {
            solutionStr = this->cache->get(searchable->toString());
            this->writeSolution(solutionStr, outputStream);
            this->cacheLock.unlock();
        } catch (const char *exception) {
            //todo check for possible exception here
            Solution solution = this->solver->solve(searchable);
            this->cache->insert(searchable->toString(), this->solutionToString(solution));
            this->writeSolution(outputStream, solution);
            this->cacheLock.unlock();
        }

    }
};

#endif //SOLID_SERVER_REDO_MYCLIENTHANDLER_H
