//
// Created by matan on 1/14/20.
//

#ifndef SOLID_SERVER_REDO_ISEARCHER_H
#define SOLID_SERVER_REDO_ISEARCHER_H

#include "../Searchables/ISearchable.h"

template<class Solution, class Var>
class ISearcher {
    virtual Solution search(ISearchable<Var>* iSearchable) = 0;
};


#endif //SOLID_SERVER_REDO_ISEARCHER_H
