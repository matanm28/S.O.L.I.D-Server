//
// Created by matan on 1/14/20.
//

#include "Searcher.h"
//
// Created by sapir on 13/01/2020.
//

#include "Searcher.h"

template<class Solution, class Position>
void Searcher<Solution, Position>::addToOpenList(State<Position> state) {
    this->openList.push(state);
}

template<class Solution, class Position>
Searcher<Solution, Position>::Searcher() {
    this->evaluatedNum = 0;
}

template<class Solution, class Position>
int Searcher<Solution, Position>::getNumberOfNodesEvaluated() {
    return this->evaluatedNum;
}

template<class Solution, class Position>
State<Position> Searcher<Solution, Position>::popOpenList() {
    this->evaluatedNum++;
    State<Position> popState = this->openList.top();
    this->openList.pop();
    return popState;
}

template<class Solution, class Position>
int Searcher<Solution, Position>::openListSize() {
    return this->openList.size();
}

template<class Solution, class Position>
bool Searcher<Solution, Position>::isInOpenList(State<Position> state) {
    return (std::find(openList.cbegin(), openList.cend(), state) != this->openList.cend());
}

template<class Solution, class Position>
State<Position> Searcher<Solution, Position>::getState(State<Position> state) {
    auto iter = std::find(openList.cbegin(), openList.cend(), state);
    return *iter;
}

template<class Solution, class Position>
void Searcher<Solution, Position>::updateOpenList(State<Position> state) {
    priority_queue<State<Position>> temp;
    while (!this->openList.empty()) {
        State<Position> tempState = this->openList.top();
        this->openList.pop();
        if (state == tempState) {
            temp.push(state);
        } else {
            temp.push(tempState);
        }
    }
    this->openList = temp;

}



