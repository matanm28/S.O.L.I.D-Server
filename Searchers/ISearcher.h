//
// Created by matan on 1/14/20.
//

#ifndef SOLID_SERVER_REDO_ISEARCHER_H
#define SOLID_SERVER_REDO_ISEARCHER_H

template <class Solution, class Position>
class ISearcher {
    virtual Solution search(ISearchable<Position> iSearchable)= 0;

};


#endif //SOLID_SERVER_REDO_ISEARCHER_H
