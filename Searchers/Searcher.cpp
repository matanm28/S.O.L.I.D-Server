//
// Created by matan on 1/14/20.
//

#include "Searcher.h"
//
// Created by sapir on 13/01/2020.
//

#include "Searcher.h"

//template<class Solution, class Var>
//void Searcher<Solution, Var>::addToOpenList(State<Var> state) {
//    this->openList.push(state);
//}
//
//template<class Solution, class Var>
//Searcher<Solution, Var>::Searcher() {
//    this->evaluatedNum = 0;
//}
//
//template<class Solution, class Var>
//int Searcher<Solution, Var>::getNumberOfNodesEvaluated() {
//    return this->evaluatedNum;
//}
//
//template<class Solution, class Var>
//State<Var> Searcher<Solution, Var>::popOpenList() {
//    this->evaluatedNum++;
//    State<Var> popState = this->openList.top();
//    this->openList.pop();
//    return popState;
//}
//
//template<class Solution, class Var>
//int Searcher<Solution, Var>::openListSize() {
//    return this->openList.size();
//}
//
//template<class Solution, class Var>
//bool Searcher<Solution, Var>::isInOpenList(State<Var> state) {
//    return (std::find(openList.cbegin(), openList.cend(), state) != this->openList.cend());
//}
//
//template<class Solution, class Var>
//State<Var> Searcher<Solution, Var>::getState(State<Var> state) {
//    auto iter = std::find(openList.cbegin(), openList.cend(), state);
//    return *iter;
//}
//
//template<class Solution, class Var>
//void Searcher<Solution, Var>::updateOpenList(State<Var> state) {
//    priority_queue<State<Var>> temp;
//    while (!this->openList.empty()) {
//        State<Var> tempState = this->openList.top();
//        this->openList.pop();
//        if (state == tempState) {
//            temp.push(state);
//        } else {
//            temp.push(tempState);
//        }
//    }
//    this->openList = temp;
//
//}



