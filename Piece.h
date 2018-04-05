/**********************************
ECE 4122 Final Project - 4/5/2018
**********************************/
//Includes
#include <string>
#include "Board.h"

class Piece
{
public:
	std::string color;
	int x, y;
	Piece(int X, int Y, std:string Color);
	void canMove();
};