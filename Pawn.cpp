//
// Created by Wayne Stevens on 4/21/18.
//

#include "Pawn.h"
#include <iostream>
Pawn::Pawn(Square square, std::string color) {
        position = square;
        player = color;
        if (color == "W" || color == "w" || color == "white" || color == "White")
            piece_name = 'P';
        else
            piece_name = 'p';

}


void Pawn::updateMoves(std::vector<std::vector<Piece*> > board) {
    // knight can at most move to eight different locations in an "L" shape form
    // These are the possible X values and Y values that the new square can take
    moveList.clear();
    if (player == "white") {
        int poss_y[2] = {position.y - 1, position.y - 2};
        int poss_x[3] = {position.x, position.x + 1, position.x - 1};

        int counter = 0;

        // Move: forward by 2, TODO: check to make sure pawn is previously unmoved
        // Move: forward by 1
        if (validPosition(poss_x[0], poss_y[1]) && (counter == 0)) {
            counter++;
            Square sq = Square(poss_x[0], poss_y[1]);
            if (board[position.y - 2][position.x]->getName() == '-') {
                moveList.push_back(sq);
            }
        }
        if (validPosition(poss_x[0], poss_y[0])) {
            counter++;
            Square sq = Square(poss_x[0], poss_y[0]);
            if (board[position.y - 1][position.x]->getColor() == "none") {
                moveList.push_back(sq);
            }
        }

        // Move: diagonal left
        if (validPosition(poss_x[2], poss_y[0])) {
            if ((player == "white" && board[position.y - 1][position.x - 1]->getColor() == "black") ||
                (player == "black" && board[position.y - 1][position.x - 1]->getColor() == "white")) {
                counter++;
                Square sq = Square(poss_x[2], poss_y[0]);
                moveList.push_back(sq);
            }
        }
        // Move: diagonal right
        if (validPosition(poss_x[1], poss_y[0])) {
            if ((player == "white" && board[position.y - 1][position.x + 1]->getColor() == "black") ||
                (player == "black" && board[position.y - 1][position.x + 1]->getColor() == "white")) {
                counter++;
                Square sq = Square(poss_x[1], poss_y[0]);
                moveList.push_back(sq);
            }
        }
    }else {
        int poss_y[2] = {position.y + 1, position.y + 2};
        int poss_x[3] = {position.x, position.x + 1, position.x - 1};

        int counter = 0;

        // Move: forward by 2, TODO: check to make sure pawn is previously unmoved
        // Move: forward by 1
        if (validPosition(poss_x[0], poss_y[1]) && (counter == 0)) {
            counter++;
            Square sq = Square(poss_x[0], poss_y[1]);
            if (board[position.y + 2][position.x]->getName() == '-') {
                moveList.push_back(sq);
            }
        }
        if (validPosition(poss_x[0], poss_y[0])) {
            counter++;
            Square sq = Square(poss_x[0], poss_y[0]);
            if (board[position.y + 1][position.x]->getColor() == "none") {
                moveList.push_back(sq);
            }
        }

        // Move: diagonal left
        if (validPosition(poss_x[2], poss_y[0])) {
            if ((player == "white" && board[position.y + 1][position.x - 1]->getColor() == "black") ||
                (player == "black" && board[position.y + 1][position.x - 1]->getColor() == "white")) {
                counter++;
                Square sq = Square(poss_x[2], poss_y[0]);
                moveList.push_back(sq);
            }
        }
        // Move: diagonal right
        if (validPosition(poss_x[1], poss_y[0])) {
            if ((player == "white" && board[position.y + 1][position.x + 1]->getColor() == "black") ||
                (player == "black" && board[position.y + 1][position.x + 1]->getColor() == "white")) {
                counter++;
                Square sq = Square(poss_x[1], poss_y[0]);
                moveList.push_back(sq);
            }
        }
    }
}

void Pawn::moveTo(Square newPosition) {
    position = newPosition;
}

std::vector<Square> Pawn::getMoves() {
    return moveList;
}

Square Pawn::getPosition() {return position;}


char Pawn::getName() {return piece_name;}
std::string Pawn::getColor(){return player;}
//Pawn &Pawn:: operator= (const Pawn pawn) {
//    this->position = pawn.position;
//    this -> player = pawn.player;
//    this -> piece_name = pawn.piece_name;
//    this -> moveList = pawn.moveList;
//}
