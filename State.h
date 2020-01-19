//
// Created by matan on 1/14/20.
//

#ifndef SOLID_SERVER_REDO_STATE_H
#define SOLID_SERVER_REDO_STATE_H

#include <iostream>
#include <string>
#include "Position.h"
using namespace std;
template<class Var>
class State {
private:
    Var state;
    double cost, trialCost, heuristicCost;
    State<Var> *cameFrom;
    string direction;
public:
    State(Var state, State<Var> *cameFrom) {
        this->state = state;
        this->cameFrom = cameFrom;

    }

    State(Var state, double cost) {
        this->state = state;
        this->cost = cost;
    }

    State(Var state, double cost, double trialCost) {
        this->state = state;
        this->cost = cost;
        this->trialCost = trialCost;
    }

    State(Var state, double cost, double trialCost, State<Var> *cameFrom) {
        this->state = state;
        this->cameFrom = cameFrom;
        this->cost = cost;
        this->trialCost = trialCost;
    }

    State(Var state, double cost, double trialCost, State<Var> *cameFrom, string direction) {
        this->state = state;
        this->cameFrom = cameFrom;
        this->cost = cost;
        this->trialCost = trialCost;
        this->direction = direction + "(" + to_string(this->trialCost) + ")";
    }

    void setTrialCost(double trialCost) {
        this->trialCost = trialCost;

    }

    void setHeuristicCost(double heuristicCost) {
        this->heuristicCost = heuristicCost;
    }

    void setCost(double cost) {
        this->cost = cost;

    }

    void setCameFrom(State<Var> *cameFrom) {
        this->cameFrom = cameFrom;
    }

    double getCost() {
        return this->cost;
    }

    double getTrialCost() const {
        return trialCost;
    }

    State<Var> *getCameFrom() {
        return this->cameFrom;
    }

    Var getState() {
        return this->state;
    }

    double getHeuristicCost() const {
        return heuristicCost;
    }

    const string &getDirection() const {
        return direction;
    }

    bool operator==(const State &rhs) const {
        return state == rhs.state;
    }

    bool operator!=(const State &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const State &rhs) const {
        return this->trialCost < rhs.getTrialCost();
    }


    bool operator>(const State &rhs) const {
        return this->trialCost > rhs.getTrialCost();
    }

    bool operator<=(const State &rhs) const {
        return !(rhs > *this);
    }

    bool operator>=(const State &rhs) const {
        return !(rhs < *this);
    }
};


#endif //SOLID_SERVER_REDO_STATE_H
