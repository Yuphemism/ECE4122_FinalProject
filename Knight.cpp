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



void Knight::updateMoves(std::vector<std::vector<Piece*>> &board) {

    moveList.clear();
    // knight can at most move to eight different locations in an "L" shape form
    // These are the possible X values and Y values that the new square can take
    int poss_x[4] = {position.x + 1, position.x - 1, position.x + 2, position.x - 2};
    int poss_y[4] = {position.y + 1, position.y - 1, position.y + 2, position.y - 2};

    // define a counter to keep track of how large the valid moveList will be
    if(validPosition(poss_x[0],poss_y[2])) {
        if(board[poss_x[0]][poss_y[2]]->getName() == '-' || board[poss_x[0]][poss_y[2]]->getPlayer() != player)
            moveList.push_back(Square(poss_x[0], poss_y[2]));
    }
    if(validPosition(poss_x[1], poss_y[2])) {
        if(board[poss_x[1]][poss_y[2]]->getName() == '-' || board[poss_x[1]][poss_y[2]]->getPlayer() != player)
            moveList.push_back(Square(poss_x[1], poss_y[2]));
    }
    if(validPosition(poss_x[2], poss_y[0])) {
        if(board[poss_x[2]][poss_y[0]]->getName() == '-' || board[poss_x[2]][poss_y[0]]->getPlayer() != player)
            moveList.push_back(Square(poss_x[2], poss_y[0]));
    }
    if(validPosition(poss_x[3], poss_y[0])) {
        if(board[poss_x[3]][poss_y[0]]->getName() == '-' || board[poss_x[3]][poss_y[0]]->getPlayer() != player)
            moveList.push_back(Square(poss_x[3], poss_y[0]));
    }
    if(validPosition(poss_x[2],poss_y[1])) {
        if(board[poss_x[2]][poss_y[1]]->getName() == '-' || board[poss_x[2]][poss_y[1]]->getPlayer() != player)
            moveList.push_back(Square(poss_x[2], poss_y[1]));
    }
    if(validPosition(poss_x[3], poss_y[1])) {
        if(board[poss_x[3]][poss_y[1]]->getName() == '-' || board[poss_x[3]][poss_y[1]]->getPlayer() != player)
            moveList.push_back(Square(poss_x[3], poss_y[1]));
    }
    if(validPosition(poss_x[0], poss_y[3])) {
        if(board[poss_x[0]][poss_y[3]]->getName() == '-' || board[poss_x[0]][poss_y[3]]->getPlayer() != player)
            moveList.push_back(Square(poss_x[0], poss_y[3]));
    }
    if(validPosition(poss_x[1], poss_y[3])) {
        if(board[poss_x[1]][poss_y[3]]->getName() == '-' || board[poss_x[1]][poss_y[3]]->getPlayer() != player)
            moveList.push_back(Square(poss_x[1], poss_y[3]));
    }


}

void Knight::moveTo(Square newPosition) {
    position = newPosition;
}

Square Knight::getPosition() {return position;}


std::vector<Square> Knight::getMoves() {
    return moveList;
}

char Knight::getName() {return piece_name;}
