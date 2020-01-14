//
// Created by matan on 1/14/20.
//

#ifndef SOLID_SERVER_REDO_ISOLVER_H
#define SOLID_SERVER_REDO_ISOLVER_H

template <class Problem, class Solution>
class ISolver {
public:
    virtual Solution solve(Problem problem) = 0;
};


#endif //SOLID_SERVER_REDO_ISOLVER_H
