// Bishop.cpp
// Created by Wayne Stevens on 4/19/18.
//
//

#include "Bishop.h"

Bishop::Bishop(Square square, std::string color) {
    position = square;
    player = color;
    if(color == "white" || color == "White" || color == "WHITE" || color == "w" || color == "W") {
        piece_name = 'B';
    } else {
        piece_name = 'b';
    }

}

void Bishop::updateMoves(std::vector<std::vector<Piece*>> &board) {
    // These are the possible X values and Y values that the new square can take
    moveList.clear();
    bool stop1 = false, stop2 = false, stop3 = false, stop4 = false;
    for(int i = 1; i < 8; i++) {

        int poss_x[2] = {position.x + i, position.x - i};
        int poss_y[2] = {position.y + i, position.y - i};

        // check to see if potential row and column pair is valid
        if(validPosition(poss_x[0], poss_y[0]) && !stop1) {
            if(board[poss_x[0]][poss_y[0]]->getName() == '-'){
                moveList.push_back(Square(poss_x[0], poss_y[0]));
            }
            else {
                if (board[poss_x[0]][poss_y[0]]->getPlayer() != player){
                    moveList.push_back(Square(poss_x[0], poss_y[0]));
                }
                stop1 = true;
            }
        }
        if(validPosition(poss_x[0], poss_y[1]) && !stop2) {
            if(board[poss_x[0]][poss_y[1]]->getName() == '-'){
                moveList.push_back(Square(poss_x[0], poss_y[1]));
            }
            else {
                if (board[poss_x[0]][poss_y[1]]->getPlayer() != player){
                    moveList.push_back(Square(poss_x[0], poss_y[1]));
                }
                stop2 = true;
            }
        }
        if(validPosition(poss_x[1], poss_y[0]) && !stop3) {
            if(board[poss_x[1]][poss_y[0]]->getName() == '-'){
                moveList.push_back(Square(poss_x[1], poss_y[0]));
            }
            else {
                if (board[poss_x[1]][poss_y[0]]->getPlayer() != player){
                    moveList.push_back(Square(poss_x[1], poss_y[0]));
                }
                stop3 = true;
            }
        }
        if(validPosition(poss_x[1], poss_y[1]) && !stop4) {
            if(board[poss_x[1]][poss_y[1]]->getName() == '-'){
                moveList.push_back(Square(poss_x[1], poss_y[1]));
            }
            else {
                if (board[poss_x[1]][poss_y[1]]->getPlayer() != player){
                    moveList.push_back(Square(poss_x[1], poss_y[1]));
                }
                stop4 = true;
            }
        }

    }

}

void Bishop::moveTo(Square newPosition) {
    position = newPosition;
}

std::vector<Square> Bishop::getMoves() {
    return moveList;
}

Square Bishop::getPosition() {return position;}

char Bishop::getName() {return piece_name;}
