//
// Created by Wayne Stevens on 4/19/18.
//
// Knight Piece which is a subclass of Piece

#include "Piece.h"

#ifndef FINAL_PROJECT_KNIGHT_H
#define FINAL_PROJECT_KNIGHT_H

class Knight : public Piece {
protected:
    Square position;
    std::vector<Square> moveList;
    std::string player;
    char piece_name;

public:
//    Knight(std::string color);
    Knight(Square set_position, std::string color);

    void moveTo(Square newPosition);
    void updateMoves(std::vector<std::vector<Piece*> > board);
    std::vector<Square> getMoves();
    char getName();
    Square getPosition();
    std::string getColor();
};

#endif //FINAL_PROJECT_KNIGHT_H
