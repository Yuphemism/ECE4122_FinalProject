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

void Queen::updateMoves(std::vector<std::vector<Piece*>> &board) {
    // These are the possible X values and Y values that the new square can take
    moveList.clear();
    bool stop1 = false, stop2 = false, stop3 = false, stop4 = false;
    bool stop5 = false, stop6 = false, stop7 = false, stop8 = false;

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
        if(validPosition(poss_x[0], position.y) && !stop5) {
            if(board[poss_x[0]][position.y]->getName() == '-'){
                moveList.push_back(Square(poss_x[0], position.y));
            }
            else {
                if (board[poss_x[0]][position.y]->getPlayer() != player){
                    moveList.push_back(Square(poss_x[0], position.y));
                }
                stop5 = true;
            }
        }
        if(validPosition(poss_x[1], position.y) && !stop6) {
            if(board[poss_x[1]][position.y]->getName() == '-'){
                moveList.push_back(Square(poss_x[1], position.y));
            }
            else {
                if (board[poss_x[1]][position.y]->getPlayer() != player){
                    moveList.push_back(Square(poss_x[1], position.y));
                }
                stop6 = true;
            }
        }
        if(validPosition(position.x, poss_y[0]) && !stop7) {
            if(board[position.x][poss_y[0]]->getName() == '-'){
                moveList.push_back(Square(position.x, poss_y[0]));
            }
            else {
                if (board[position.x][poss_y[0]]->getPlayer() != player){
                    moveList.push_back(Square(position.x, poss_y[0]));
                }
                stop7 = true;
            }
        }
        if(validPosition(position.x, poss_y[1]) && !stop8) {
            if(board[position.x][poss_y[1]]->getName() == '-'){
                moveList.push_back(Square(position.x, poss_y[1]));
            }
            else {
                if (board[position.x][poss_y[1]]->getPlayer() != player){
                    moveList.push_back(Square(position.x, poss_y[1]));
                }
                stop8 = true;
            }
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
