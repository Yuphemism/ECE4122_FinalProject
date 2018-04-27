#include "Piece.h"



Piece::Piece(int x_pos, int y_pos, std::string color) {
    x = x_pos;
    y = y_pos;
    player = color;
}

Piece::Piece() {
    x = 0;
    y = 0;
    player = "";
}


void Piece::moveTo(int x_pos, int y_pos) {
    x = x_pos;
    y = y_pos;
}

bool Piece::validPosition(int x_pos, int y_pos) {
    return x_pos >= 0 && x_pos <= 7 && y_pos >= 0 && y_pos <= 7;
}




