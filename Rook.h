//
// Created by Wayne Stevens on 4/21/18.
//
#include "Piece.h"
#include "Square.h"

#ifndef FINAL_PROJECT_ROOK_H
#define FINAL_PROJECT_ROOK_H


class Rook : public Piece {

private:
    Square position;
    std::vector<Square> moveList; // list of possible squares that the piece can move to
    std::string player;
    char piece_name;

public:
    Rook(Square set_position, std::string color); // Constructor
    Rook(std::string color);

    //Member Functions

    void moveTo(Square newPosition);

    void updateMoves(std::vector<std::vector<Piece*>> &board); // update the MoveList

    std::vector<Square> getMoves();

    char getName();

    Square getPosition();
};


#endif //FINAL_PROJECT_ROOK_H
