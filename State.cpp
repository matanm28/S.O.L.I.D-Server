//
// Created by matan on 1/14/20.
//

#include "State.h"

template<class Position>
State<Position>::State(Position state) {
    this->state = state;
}

template<class Position>
State<Position>::State(Position state, State<Position> *cameFrom) {
    this->state = state;
    this->cameFrom = cameFrom;

}

template<class Position>
State<Position>::State(Position state, double cost, State<Position> *cameFrom) {
    this->state = state;
    this->cameFrom = cameFrom;
    this->cost = cost;
}

template<class Position>
void State<Position>::setCost(double cost) {
    this->cost = cost;

}

template<class Position>
void State<Position>::setCameFrom(State<Position> *cameFrom) {
    this->cameFrom = cameFrom;
}

template<class Position>
double State<Position>::getCost() {
    return this->cost;
}

template<class Position>
State<Position> *State<Position>::getCameFrom() {
    return this->cameFrom;
}

template<class Position>
Position State<Position>::getState() {
    return this->state;
}

template<class Position>
bool State<Position>::operator==(const State &rhs) const {
    return state == rhs.state;
}

template<class Position>
bool State<Position>::operator!=(const State &rhs) const {
    return !(rhs == *this);
}

template<class Position>
bool State<Position>::operator<(const State &rhs) const {
    return this->cost < rhs.getCost();
}

template<class Position>
bool State<Position>::operator>(const State &rhs) const {
    return this->cost > rhs.getCost();
}

template<class Position>
bool State<Position>::operator<=(const State &rhs) const {
    return !(rhs > *this);
}

template<class Position>
bool State<Position>::operator>=(const State &rhs) const {
    return !(rhs < *this);
}
