//
// Created by Wayne Stevens on 4/20/18.
//

#ifndef FINAL_PROJECT_QUEEN_H
#define FINAL_PROJECT_QUEEN_H


#include "Piece.h"

class Queen : public Piece {

private:
    Square position;
    std::vector<Square> moveList; // list of possible squares that the piece can move to
    std::string player;
    char piece_name;

public:
    Queen(Square set_position, std::string color); // Constructor
    Queen(std::string color);

    //Member Functions

    void moveTo(Square newPosition);

    void updateMoves(std::vector<std::vector<Piece*> > board); // update the MoveList

    std::vector<Square> getMoves();

    Square getPosition();
    std::string getColor();
    char getName();

};


#endif //FINAL_PROJECT_QUEEN_H
