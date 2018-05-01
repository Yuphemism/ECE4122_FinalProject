//
// Created by Wayne Stevens on 4/15/18.
//

#include "Knight.h"



Knight::Knight(Square square, std::string color) {
    position = square;
    player = color;
    if(color == "white" || color == "White" || color == "WHITE" || color == "w" || color == "W") {
        piece_name = 'N';
    } else {
        piece_name = 'n';
    }
}



void Knight::updateMoves(std::vector<std::vector<Piece*> > board) {

    moveList.clear();
    // knight can at most move to eight different locations in an "L" shape form
    // These are the possible X values and Y values that the new square can take
    int poss_y[4] = {position.y + 1, position.y - 1, position.y + 2, position.y - 2};
    int poss_x[4] = {position.x + 1, position.x - 1, position.x + 2, position.x - 2};

    // define a counter to keep track of how large the valid moveList will be
    int counter = 0;
    if(validPosition(poss_y[0],poss_x[2])) {
        if (board[poss_y[0]][poss_x[2]]->getColor() != player) {
            counter++;
            Square sq = Square(poss_x[2], poss_y[0]);
            moveList.push_back(sq);
        }
    }
    if(validPosition(poss_y[0], poss_x[3])) {
        if (board[poss_y[0]][poss_x[3]]->getColor() != player) {
            counter++;
            Square sq = Square(poss_x[3], poss_y[0]);
            moveList.push_back(sq);
        }
    }
    if(validPosition(poss_y[1], poss_x[2])) {
        if (board[poss_y[1]][poss_x[2]]->getColor() != player) {
            counter++;
            Square sq = Square(poss_x[2], poss_y[1]);
            moveList.push_back(sq);
        }
    }
    if(validPosition(poss_y[1], poss_x[3])) {
        if (board[poss_y[1]][poss_x[3]]->getColor() != player) {
            counter++;
            Square sq = Square(poss_x[3], poss_y[1]);
            moveList.push_back(sq);
        }
    }
    if(validPosition(poss_y[2],poss_x[0])) {
        if (board[poss_y[2]][poss_x[0]]->getColor() != player) {
            counter++;
            Square sq = Square(poss_x[0], poss_y[2]);
            moveList.push_back(sq);
        }
    }
    if(validPosition(poss_y[2], poss_x[0])) {
        if (board[poss_y[2]][poss_x[0]]->getColor() != player) {
            counter++;
            Square sq = Square(poss_x[0], poss_y[2]);
            moveList.push_back(sq);
        }
    }
    if(validPosition(poss_y[3], poss_x[1])) {
        if (board[poss_y[3]][poss_x[1]]->getColor() != player) {
            counter++;
            Square sq = Square(poss_x[1], poss_y[3]);
            moveList.push_back(sq);
        }
    }
    if(validPosition(poss_y[3], poss_x[1])) {
        if (board[poss_y[3]][poss_x[1]]->getColor() != player) {
            counter++;
            Square sq = Square(poss_x[1], poss_y[3]);
            moveList.push_back(sq);
        }
    }


}

void Knight::moveTo(Square newPosition) {
    position = newPosition;
}

Square Knight::getPosition() {return position;}


std::vector<Square> Knight::getMoves() {
    return moveList;
}
std::string Knight::getColor(){return player;}
char Knight::getName() {return piece_name;}
