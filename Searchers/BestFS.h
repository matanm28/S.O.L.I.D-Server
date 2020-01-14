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
#include <vector>

using namespace std;
//Solution is vector<State<Var>>:
template<class Var>
class BestFS : public Searcher<vector<State<Var>>, Var> {
public:
    vector<State<Var>> search(ISearchable<Var>* searchable) override;

    State<Var> findState(ISearchable<Var>* searchable, priority_queue<State<Var>> closed, State<Var> state);

    State<Var> backTrace(ISearchable<Var>* searchable, State<Var> state);
};



#endif //SOLID_SERVER_REDO_BESTFS_H
