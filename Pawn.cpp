//
// Created by Wayne Stevens on 4/21/18.
//

#include "Pawn.h"
Pawn::Pawn(Square square, std::string color) : position(square), player(color) {};


void Pawn::updateMoves() {
    // knight can at most move to eight different locations in an "L" shape form
    // These are the possible X values and Y values that the new square can take
    int poss_y[2] = {position.y + 1, position.y + 2};
    int poss_x[3] = {position.x, position.x + 1, position.x - 1};

    int counter = 0;

    // Move: forward by 2, TODO: check to make sure pawn is previously unmoved
    if(validPosition(poss_y[1],poss_x[0]) && (counter == 0) ) {
        counter++;
        Square sq = Square(poss_x[0], poss_y[1]);
        moveList.push_back(sq);
    }

    // Move: forward by 1
    if(validPosition(poss_y[0],poss_x[0])) {
        counter++;
        Square sq = Square(poss_x[0], poss_y[0]);
        moveList.push_back(sq);
    }

    // Move: diagonal left
    if(validPosition(poss_y[0],poss_x[2])) {
        counter++;
        Square sq = Square(poss_x[2], poss_y[0]);
        moveList.push_back(sq);
    }

    // Move: diagonal right
    if(validPosition(poss_y[0],poss_x[1])) {
        counter++;
        Square sq = Square(poss_x[1], poss_y[0]);
        moveList.push_back(sq);
    }

}

void Pawn::moveTo(Square newPosition) {
    position = newPosition;
}

std::vector<Square> Pawn::getMoves() {
    return moveList;
}

Square Pawn::getPosition() {return position;}


char Pawn::getName() {return 'P';}

//Pawn &Pawn:: operator= (const Pawn pawn) {
//    this->position = pawn.position;
//    this -> player = pawn.player;
//    this -> piece_name = pawn.piece_name;
//    this -> moveList = pawn.moveList;
//}
