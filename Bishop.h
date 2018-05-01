//
// Created by Wayne Stevens on 4/19/18.
//
#include "Piece.h"

#ifndef FINAL_PROJECT_BISHOP_H
#define FINAL_PROJECT_BISHOP_H


class Bishop : public Piece {
private:
    Square position;
    std::vector<Square> moveList; // list of possible squares that the piece can move to
    std::string player;
    char piece_name;

public:
    Bishop(Square set_position, std::string color); // Constructor
//    Bishop(std::string color);

    //Member Functions

    void moveTo(Square newPosition);

    void updateMoves(std::vector<std::vector<Piece*> > board); // update the MoveList

    std::vector<Square> getMoves();

    char getName();

    Square getPosition();
    std::string getColor();


};


#endif //FINAL_PROJECT_BISHOP_H
