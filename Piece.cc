#include "Piece.h"



Piece::Piece(Square square, std::string color) {
    current_position = square;
    player = color;

}
Piece::Piece() {
    current_position.x = 0;
    current_position.y = 0;
    player = "";

}
void Piece::moveTo(Square newPosition) {
    current_position = newPosition;
}
void updateMoves(){
}
std::vector<Square> Piece::getMoves(){
    std::vector<Square> empty;
        return empty;
}
bool Piece::validPosition(int x_pos, int y_pos) {
    return x_pos >= 0 && x_pos <= 7 && y_pos >= 0 && y_pos <= 7;
}
char Piece::getName(){
    return '-';
}




