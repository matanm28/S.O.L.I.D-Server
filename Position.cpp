//
// Created by sapir on 14/01/2020.
//

#include "Position.h"

Position::Position() {}

Position::Position(int row, int col) : row(row), col(col) {}

bool Position::operator==(const Position &pos) const {
    return (this->row == pos.getRow() && this->col == pos.getCol());
}

bool Position::operator!=(const Position &pos) const {
    return !(*this == pos);
}

int Position::getRow() const {
    return row;
}

int Position::getCol() const {
    return col;
}

string Position::toString() {
    string posStr;
    posStr.append(to_string(this->getRow()));
    posStr.append(DELIMITER);
    posStr.append(to_string(this->getCol()));
    return posStr;
}
