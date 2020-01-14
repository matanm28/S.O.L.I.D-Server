//
// Created by matan on 1/14/20.
//

#ifndef SOLID_SERVER_REDO_STATE_H
#define SOLID_SERVER_REDO_STATE_H

template<class Position>

class State {
private:
    Position state;
    double cost;
    State<Position> *cameFrom;
public:
    explicit State(Position state);

    State(Position state, State<Position> *cameFrom);

    State(Position state, double cost, State<Position> *cameFrom);

    void setCost(double cost);

    void setCameFrom(State<Position> *cameFrom);

    double getCost();

    State<Position> *getCameFrom();

    Position getState();

    bool operator==(const State &rhs) const;

    bool operator!=(const State &rhs) const;

    bool operator<(const State &rhs) const;

    bool operator>(const State &rhs) const;

    bool operator<=(const State &rhs) const;

    bool operator>=(const State &rhs) const;
};


#endif //SOLID_SERVER_REDO_STATE_H
