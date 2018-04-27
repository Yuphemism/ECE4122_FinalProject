#include "Piece.h"



Piece::Piece(Square square, std::string color) {
    position = square;
    player = color;

}
Piece::Piece() {
    position.x = 0;
    position.y = 0;
    player = "";

}

bool Piece::validPosition(int x_pos, int y_pos) {
    return x_pos >= 0 && x_pos <= 7 && y_pos >= 0 && y_pos <= 7;
}




