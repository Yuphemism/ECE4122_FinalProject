//
// Created by Wayne Stevens on 4/11/18.
//

#include "Square.h"


Square::Square() : x(0), y(0) {}
Square::Square(int x_coord, int y_coord) : x(x_coord), y(y_coord) {}


Square &Square :: operator= (const Square &square) {
    this->x = square.x;
    this->y = square.y;
    return *this;
}

bool Square:: operator== (const Square & Rsquare) const{
    return (this->x == Rsquare.x && this->y == Rsquare.y);
}
//
bool Square:: operator!=(const Square & Rsquare) const {
    return (this->x != Rsquare.x || this->y != Rsquare.y);
}