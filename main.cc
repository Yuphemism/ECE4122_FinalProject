#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "BoardSq.h"
#include "Pawn.h"
#include "Rook.h"
using namespace std;

int main () {
    //instantiate Board 8x8
    Piece board[8, 8];
    SetupBoard();
    while(){
        
    }
    return 0;
}

void SetupBoard(std_string ) {
    //Pawns
    for(int i = 0; i < 8; i++) {
        board[i, 1] = new Pawn(i, 1, 'b');
        board[i, 6] = new Pawn(i, 6, 'w');
    }
    
    //Rooks
    board[0][0] = new Rook(0, 0, 'b');
    board[7][0] = new Rook(7, 0, 'b');
    board[0][7] = new Rook(0, 7, 'w');
    board[7][7] = new Rook(7, 7, 'w');
    
    //Knights
    board[1][0] = new Knight(1, 0, 'b');
    board[6][0] = new Knight(6, 0, 'b');
    board[1][7] = new Knight(1, 7, 'w');
    board[6][7] = new Knight(6, 7, 'w');
    
    //Bishops
    board[2][0] = new Bishop(2, 0, 'b');
    board[5][0] = new Bishop(5, 0, 'b');
    board[2][7] = new Bishop(2, 7, 'w');
    board[5][7] = new Bishop(5, 7, 'w');
    
    //Queens
    board[3][0] = new Queen(3, 0, 'b');
    board[4][7] = new Queen(4, 7, 'w');
    
    //Kings
    board[4][0] = new King(4, 0, 'b');
    board[3][7] = new King(3, 7, 'w');
}
