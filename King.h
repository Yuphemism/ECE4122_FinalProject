//
// Created by Wayne Stevens on 4/20/18.
//
#include "Piece.h"
#ifndef FINAL_PROJECT_KING_H
#define FINAL_PROJECT_KING_H


class King : public Piece {

private:
    Square position;
    std::vector<Square> moveList; // list of possible squares that the piece can move to
    std::string player;
    char piece_name;

public:
    King(Square set_position, std::string color); // Constructor
    King(std::string color);

    //Member Functions

    void moveTo(Square newPosition);

    void updateMoves(std::vector<std::vector<Piece*> > board); // update the MoveList

    std::vector<Square> getMoves();

    char getName();
    std::string getColor();
    Square getPosition();


};

#endif //FINAL_PROJECT_KING_H
