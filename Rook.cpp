//
// Created by Wayne Stevens on 4/21/18.
//

#include "Rook.h"

Rook::Rook(Square square, std::string color) : position(square), player(color) {};

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

void Rook::updateMoves() {
    // These are the possible X values and Y values that the new square can take
    moveList.clear();
    for(int i = 1; i < 8; i++) {

        int poss_x[2] = {position.x + i, position.x - i};
        int poss_y[2] = {position.y + i, position.y - i};

        // check to see if potential row and column pair is valid
        if(validPosition(poss_x[0], position.y)) {
            moveList.push_back(Square(poss_x[0], position.y));
        }
        if(validPosition(poss_x[1], position.y)) {
            moveList.push_back(Square(poss_x[1], position.y));
        }
        if(validPosition(position.x, poss_y[0])) {
            moveList.push_back(Square(position.x, poss_y[0]));
        }
        if(validPosition(position.x, poss_y[1])) {
            moveList.push_back(Square(position.x, poss_y[1]));
        }
    }

}

Square Rook::getPosition() {return position;}


std::vector<Square> Rook::getMoves() {
    return moveList;
}

char Rook::getName() {return 'R';}
