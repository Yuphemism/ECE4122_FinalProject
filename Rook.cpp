//
// Created by Wayne Stevens on 4/21/18.
//

#include "Rook.h"

Rook::Rook(Square square, std::string color) {
    position = square;
    player = color;
    if (color == "W" || color == "w" || color == "white" || color == "White")
        piece_name = 'R';
    else
        piece_name = 'r';

}

void Rook::moveTo(Square newPosition) {
    position = newPosition;
}

void Rook::updateMoves(std::vector<std::vector<Piece*> > board) {
    // These are the possible X values and Y values that the new square can take
    moveList.clear();
    bool stopN, stopE, stopS, stopW = false;
    for(int i = 1; i < 8; i++) {

        int poss_x[2] = {position.x + i, position.x - i};
        int poss_y[2] = {position.y + i, position.y - i};

        // check to see if potential row and column pair is valid
        if(validPosition(poss_x[0], position.y)) {
            if(board[position.y][poss_x[0]] -> getColor() == player) {
                stopE = true;
            } else if(board[position.y][poss_x[0]] -> getColor() != "none") {
                moveList.push_back(Square(poss_x[0], position.y));
                stopE = true;
            }
            if(!stopE) {
                moveList.push_back(Square(poss_x[0], position.y));
            }
        }
        if(validPosition(poss_x[1], position.y)) {
            if(board[position.y][poss_x[1]] -> getColor() == player) {
                stopW = true;
            } else if(board[position.y][poss_x[1]]-> getColor() != "none") {
                moveList.push_back(Square(poss_x[1], position.y));
                stopW = true;
            }
            if(!stopW) {
                moveList.push_back(Square(poss_x[1], position.y));
            }
        }
        if(validPosition(position.x, poss_y[0])) {
            if(board[poss_y[0]][position.x] -> getColor() == player) {
                stopN = true;
            } else if(board[poss_y[0]][position.x] -> getColor() != "none") {
                moveList.push_back(Square(position.x, poss_y[0]));
                stopN = true;
            }
            if(!stopN) {
                moveList.push_back(Square(position.x, poss_y[0]));
            }
        }
        if(validPosition(position.x, poss_y[1])) {
            if(board[poss_y[1]][position.x] -> getColor() == player) {
                stopS = true;
            } else if(board[poss_y[1]][position.x] -> getColor() != "none") {
                moveList.push_back(Square(position.x, poss_y[1]));
                stopS = true;
            }
            if(!stopS) {
                moveList.push_back(Square(position.x, poss_y[1]));
            }
        }
    }

}

Square Rook::getPosition() {return position;}


std::vector<Square> Rook::getMoves() {
    return moveList;
}
std::string Rook::getColor(){return player;}
char Rook::getName() {return piece_name;}
