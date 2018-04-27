#include <string>
#include "Square.h"
#include <vector>

#ifndef PIECE_H
#define PIECE_H

class Piece {
protected:
		int x, y;
        std::vector<Square> moveList; // list of possible squares that the piece can move to
		std::string player;


	public:
		Piece(int x, int y, std::string color); // Constructor
        Piece();

        //************ Member Functions ****************
        // move piece position of piece
        void moveTo(int x, int y);

        // validates that x,y pair on the board
        bool validPosition(int x_val, int y_val);

        // get list of potential moves
        virtual std::vector<Square> getMoves() = 0;

        // update the list of squares the piece can move to
		virtual void updateMoves() = 0;

        virtual char getName() = 0;


};
#endif
