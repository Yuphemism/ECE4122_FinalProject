#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "Rook.h"
#include <iostream>
using namespace std;

void move(std::vector<std::vector<Piece*> > b, int init_x, int init_y, int end_x, int end_y) {
    Square initial(init_x, init_y);
    Square dest(end_x, end_y);
    
    //get the move with the possible move set
    b[init_x][init_y] -> updateMoves();
    std::vector<Square> possibleMoves = b[init_x][init_y] -> getMoves();
    bool moved = false;
    //check if the move is within the set, if not print a statement that lets them know it isn't
    for(auto &pM : possibleMoves) {
        if(pM == dest) {
            b[init_x][init_y] -> moveTo(dest);
            b[end_x][end_y] = b[init_x][init_y];
            b[init_x][init_y] = new Piece(initial, "none");
        }
    }
    if(!moved) {
        cout << "That is an invalid move.\n";
    }
}

int main () {
    
// initialize board
    
    std::string c;
    std::vector<std::vector<Piece*> > board;
    for(int y = 0; y < 8; y++)
    {
        
        if(y < 2) {
            c = "black";
        } else {
            c = "white";
        }
        
        board.push_back( std::vector<Piece*>() );
        for(int x = 0; x < 8; x++)
        {
            //fill the inbetween rows with pieces that are represented with the char -
            if(y > 1 && y < 6){
                Piece* space = new Piece(Square(x, y), "none");
                board[y].push_back(space);
            }  else if((y == 0 || y == 7) && (x == 1 || x == 6)){
                //knights
                Knight* knight = new Knight(Square(x, y), c);
                board[y].push_back(knight);
            } else if((y == 0 || y == 7) && (x == 0 || x == 7)){
                //rooks
                Rook* rook = new Rook(Square(x, y), c);
                board[y].push_back(rook);
            } else if((y == 0 || y == 7) && (x == 2 || x == 5)){
                //Bishops
                Bishop* bishop = new Bishop(Square(x, y), c);
                board[y].push_back(bishop);
            } else if((y == 0 || y == 7) && x == 3){
                //Queens
                Queen* queen = new Queen(Square(x, y), c);
                board[y].push_back(queen);
            } else {
                //Kings
                King* king = new King(Square(x, y), c);
                board[y].push_back(king);
            }
            
        }
    }
    
//Play the game
    int init_x, init_y, end_x, end_y;
    while(true) {
        //print out board
        for(int y = 0; y < 8; y++){
            for(int x = 0; x < 8; x++){
                cout << board[y][x] -> getName();
            }
            cout << "\n";
        }
        cout << "Please input the initial x coordinate: ";
        cin >> init_x;
        cout << "Please input the initial y coordinate: ";
        cin >> init_y;
        cout << "Please input the destination x coordinate: ";
        cin >> end_x;
        cout << "Please input the destination y coordinate: ";
        cin >> end_y;
        move(board, init_x, init_y, end_x, end_y);
    }

    return 0;
}
