#include <string>
#include "Square.h"
#include <vector>

#ifndef PIECE_H
#define PIECE_H

class Piece {
protected:
		Square current_position;
        std::vector<Square> moveList; // list of possible squares that the piece can move to
		std::string player;


	public:
		Piece(Square set_position, std::string color); // Constructor
        Piece();
//		~Piece();

        //************ Member Functions ****************
        // move piece position of piece
        void moveTo(Square current_position);

        // validates that x,y pair on the board
        bool validPosition(int x_val, int y_val);

        // get list of potential moves
    std::vector<Square> getMoves();

        // update the list of squares the piece can move to
        void updateMoves();

        char getName();


};
#endif
