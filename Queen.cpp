//
// Created by Wayne Stevens on 4/20/18.
//

#include "Queen.h"
Queen::Queen(Square square, std::string color) {
    position = square;
    player = color;
    if(color == "white" || color == "White" || color == "WHITE" || color == "w" || color == "W") {
        piece_name = 'Q';
    } else {
        piece_name = 'q';
    }
}

Queen::Queen(std::string color) {
    player = color;
    if(color == "white" || color == "White" || color == "WHITE" || "w" || "W") {
        position = Square(3, 7);
        piece_name = 'Q';
    } else {
        position = Square(3, 0);
        piece_name = 'q';
    }
}

void Queen::updateMoves() {
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

void Queen::moveTo(Square newPosition) {
    position = newPosition;
}

std::vector<Square> Queen::getMoves() {
    return moveList;
}

Square Queen::getPosition() {return position;}

char Queen::getName() {return piece_name;}
