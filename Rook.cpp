//
// Created by Wayne Stevens on 4/21/18.
//

#include "Rook.h"

Rook::Rook(Square square, std::string color) : position(square), player(color) {piece_name = 'R';};

Rook::Rook(std::string color) {
    player = color;
    if(color == "white" || color == "White" || color == "WHITE")
        position = Square(0,7);
    else
        position = Square(0,0);
}

void Rook::moveTo(Square newPosition) {
    position = newPosition;
}

void Rook::updateMoves(std::vector<std::vector<Piece*>> &board) {
    // These are the possible X values and Y values that the new square can take
    moveList.clear();
    bool stop1 = false, stop2 = false, stop3 = false, stop4 = false;
    for(int i = 1; i < 8; i++) {

        int poss_x[2] = {position.x + i, position.x - i};
        int poss_y[2] = {position.y + i, position.y - i};

        // check to see if potential row and column pair is valid
        if(validPosition(poss_x[0], position.y) && !stop1) {
            if(board[poss_x[0]][position.y]->getName() == '-'){
                moveList.push_back(Square(poss_x[0], position.y));
            }
            else {
                if (board[poss_x[0]][position.y]->getPlayer() != player){
                    moveList.push_back(Square(poss_x[0], position.y));
                }
                stop1 = true;
            }
        }
        if(validPosition(poss_x[1], position.y) && !stop2) {
            if(board[poss_x[1]][position.y]->getName() == '-'){
                moveList.push_back(Square(poss_x[1], position.y));
            }
            else {
                if (board[poss_x[1]][position.y]->getPlayer() != player){
                    moveList.push_back(Square(poss_x[1], position.y));
                }
                stop2 = true;
            }        }
        if(validPosition(position.x, poss_y[0]) && !stop3) {
            if(board[position.x][poss_y[0]]->getName() == '-'){
                moveList.push_back(Square(position.x, poss_y[0]));
            }
            else {
                if (board[position.x][poss_y[0]]->getPlayer() != player){
                    moveList.push_back(Square(position.x, poss_y[0]));
                }
                stop3 = true;
            }        }
        if(validPosition(position.x, poss_y[1]) && !stop4) {
            if(board[position.x][poss_y[1]]->getName() == '-'){
                moveList.push_back(Square(position.x, poss_y[1]));
            }
            else {
                if (board[position.x][poss_y[1]]->getPlayer() != player){
                    moveList.push_back(Square(position.x, poss_y[1]));
                }
                stop4 = true;
            }
        }
    }

}

Square Rook::getPosition() {return position;}


std::vector<Square> Rook::getMoves() {
    return moveList;
}

char Rook::getName() {return piece_name;}
