//
// Created by sapir on 14/01/2020.
//

#ifndef SOLID_SERVER_REDO_POSITION_H
#define SOLID_SERVER_REDO_POSITION_H


class Position {
public:
    Position(int row, int col);

    Position();

    bool operator==(const Position &pos) const;

    bool operator!=(const Position &pos) const;

    int getRow() const;

    int getCol() const;

private:
    int row, col;

};


#endif //SOLID_SERVER_REDO_POSITION_H
