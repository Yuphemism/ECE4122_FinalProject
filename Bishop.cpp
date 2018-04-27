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

void Bishop::updateMoves() {
    // These are the possible X values and Y values that the new square can take
    moveList.clear();
    for(int i = 1; i < 8; i++) {

        int poss_x[2] = {position.x + i, position.x - i};
        int poss_y[2] = {position.y + i, position.y - i};

        // check to see if potential row and column pair is valid
        if(validPosition(poss_x[0], poss_y[0])) {
            moveList.push_back(Square(poss_x[0], poss_y[0]));
        }
        if(validPosition(poss_x[0], poss_y[1])) {
            moveList.push_back(Square(poss_x[0], poss_y[1]));
        }
        if(validPosition(poss_x[1], poss_y[0])) {
            moveList.push_back(Square(poss_x[1], poss_y[0]));
        }
        if(validPosition(poss_x[1], poss_y[1])) {
            moveList.push_back(Square(poss_x[1], poss_y[1]));
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