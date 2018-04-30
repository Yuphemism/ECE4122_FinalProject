#include "Piece.h"



Piece::Piece(Square square, std::string color) {
    current_position = square;
    player = color;
    piece_name = '-';

}
Piece::Piece() {
    current_position.x = 0;
    current_position.y = 0;
    player = "";
    piece_name = '-';

}
void Piece::moveTo(Square newPosition) {
    current_position = newPosition;
}
void Piece::updateMoves(){
}
std::vector<Square> Piece::getMoves(){
    std::vector<Square> empty;
        return empty;
}
bool Piece::validPosition(int x_pos, int y_pos) {
    return x_pos >= 0 && x_pos <= 7 && y_pos >= 0 && y_pos <= 7;
}
char Piece::getName(){
    return piece_name;
}
std::string Piece::getColor() {
    return player;
}
Square Piece::getPos() {
    return current_position;
}



