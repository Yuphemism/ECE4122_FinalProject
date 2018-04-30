#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "Rook.h"
#include <iostream>
using namespace std;

void move(std::vector<std::vector<Piece*> > b, int init_x, int init_y, int end_x, int end_y, bool checked) {
    Square initial(init_x, init_y);
    Square dest(end_x, end_y);
    if(checked &&b[init_x][init_y] -> getName() != 'K') {
        cout << "You must move your King out of check!\n";
    } else {
        //get the move with the possible move set
        b[init_x][init_y]->updateMoves();
        cout << b[init_x][init_y]->getName() << "\n";
        std::vector<Square> possibleMoves = b[init_x][init_y]->getMoves();
        bool moved = false;
        //check if the move is within the set, if not print a statement that lets them know it isn't
        for (auto &pM : possibleMoves) {
            if (pM == dest) {
                b[init_x][init_y]->moveTo(dest);
                b[end_x][end_y] = b[init_x][init_y];
                b[init_x][init_y] = new Piece(initial, "none");
                moved = true;
            }
        }
        if(checked) {
            checked = false;
        }
        if (!moved) {
            cout << "That is an invalid move.\n";
        }
    }
}

//checks if there has been a checkmate
bool checkMate(std::vector<std::vector<Piece*> > b, std::string colorChecked) {
    King* checkedKing;
    for(int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j++) {
            if(b[i][j] -> getName() == 'K' && b[i][j] -> getColor() == colorChecked) {
                checkedKing = (King*)b[i][j];
            }
        }
    }
    if((checkedKing -> getMoves()).size() == 0) {
        return true;
    }
    return false;
}

//checks if there has been a check
bool check(std::vector<std::vector<Piece*> > b, std::string colorChecked) {
    bool checked = false;
    std::vector<Piece*> whiteP;
    std::vector<Piece*> blackP;
    Square whiteKLoc;
    Square blackKLoc;
    for(int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j++) {
            // first split up the pieces into their own colors and find the location of the kings
            if(b[i][j] -> getName() == 'K' && b[i][j] -> getColor() == "white") {
                whiteKLoc = b[i][j] -> getPos();
            } else if(b[i][j] -> getName() == 'K' && b[i][j] -> getColor() == "black") {
                blackKLoc = b[i][j] -> getPos();
            } else if(b[i][j] -> getName() != '-' && b[i][j] -> getColor() == "white") {
                whiteP.push_back(b[i][j]);
            } else if(b[i][j] -> getName() != '-' && b[i][j] -> getColor() == "black") {
                blackP.push_back(b[i][j]);
            }
        }
    }
    //check if white king is in check
    for(auto &bP : blackP) {
        std:vector<Square> blackPMoves = bP -> getMoves();
        for(int i = 0; i < blackPMoves.size(); i++) {
            if(whiteKLoc == blackPMoves[i]) {
                checked = true;
                colorChecked = "white";
            }
        }
    }
    //check if black king is in check
    for(auto &bP : whiteP) {
        std::vector<Square> whitePMoves = bP -> getMoves();
        for(int i = 0; i < whitePMoves.size(); i++) {
            if(blackKLoc == whitePMoves[i]) {
                checked = true;
                colorChecked = "black";
            }
        }
    }
    return checked;
}
int main () {
    
// initialize board
    bool checked = false;
    bool checkMated = false;
    std::string c;
    std::string colorChecked = "none";
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
            } else if((y == 0 || y == 7) && x == 4){
                //Kings
                King* king = new King(Square(x, y), c);
                board[y].push_back(king);
            } else {
                Pawn* pawn = new Pawn(Square(x, y), c);
                board[y].push_back(pawn);
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
        move(board, init_x, init_y, end_x, end_y, checked);
        checked = check(board, colorChecked);
        checkMated = checkMate(board, colorChecked);
        if(checkMated) {
            if(colorChecked == "white") {
                cout << "Black Wins!\n";
            } else {
                cout << "White Wins!\n";
            }
        }
    }

    return 0;
}
