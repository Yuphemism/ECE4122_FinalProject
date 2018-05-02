#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "Rook.h"
#include <iostream>
using namespace std;


//checks if there has been a checkmate
bool checkMate(std::vector<std::vector<Piece*> > b, std::string colorChecked) {
    Piece* checkedKing;

    for(int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j++) {
            if(b[i][j] -> getName() == 'K' || b[i][j] -> getName() == 'k'){
               if(b[i][j] -> getColor() == colorChecked) {
                   checkedKing = b[i][j];
               }
            }
        }
    }
    if(checkedKing -> getMoves().empty()) {
        return true;
    }
    return false;
}


bool check(std::vector<std::vector<Piece*> > b, std::string & colorChecked) {
    bool checked = false;
    std::vector<Piece*> whiteP;
    std::vector<Piece*> blackP;
    Square whiteKLoc;
    Square blackKLoc;
    for(int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j++) {
            // first split up the pieces into their own colors and find the location of the kings
            if(b[i][j] -> getName() == 'K' && b[i][j] -> getColor() == "white") {
                whiteKLoc = b[i][j] -> getPosition();
            } else if(b[i][j] -> getName() == 'k' && b[i][j] -> getColor() == "black") {
                blackKLoc = b[i][j] -> getPosition();
            } else if(b[i][j] -> getName() != '-' && b[i][j] -> getColor() == "white") {
                whiteP.push_back(b[i][j]);
            } else if(b[i][j] -> getName() != '-' && b[i][j] -> getColor() == "black") {
                blackP.push_back(b[i][j]);
            }
        }
    }
    //check if white king is in check
    for(auto &bP : blackP) {
        std::vector<Square> blackPMoves = bP -> getMoves();
        for(int i = 0; i < blackPMoves.size(); i++) {
            if(whiteKLoc == blackPMoves[i]) {
                checked = true;
                colorChecked = "white";
            }
        }
    }
    //check if black king is in check

    for(auto &wP : whiteP) {
        std::vector<Square> whitePMoves = wP -> getMoves();
        for(int i = 0; i < whitePMoves.size(); i++) {
            if(blackKLoc == whitePMoves[i]) {
                checked = true;
                colorChecked = "black";
            }
        }
    }
    return checked;
}

void move(std::vector<std::vector<Piece*> > & b, int init_x, int init_y, int end_x, int end_y, bool & checked, std::string color, std::string & turn) {
    // implement way to escape check
    std::string colorChecked = color;
    bool moved = false;
    Square dest(end_x, end_y);
    Square initial(init_x, init_y);
    cout << b[init_y][init_x] -> getColor();
    if(b[init_y][init_x] -> getColor() != turn){
        cout << "That's not your piece!\n";
        return;
    }
    if(checked) {
        b[init_y][init_x] -> updateMoves(b);
        std::vector<Square> possibleM = b[init_y][init_x] -> getMoves();
        Square dest(end_x, end_y);
        Piece *last = b[end_y][end_x];;
        for(auto &pM : possibleM) {
            if(pM == dest) {
                // testing
                b[init_y][init_x]->moveTo(dest);
                b[end_y][end_x] = b[init_y][init_x];
                b[init_y][init_x] = new Piece(initial, "none");
                moved = true;
                if(turn == "white") {
                    turn = "black";
                }else  {
                    turn = "white";
                }
                // break out of the loop if move is valid
                break;
            }
        }
        checked = check(b, colorChecked);
        if(colorChecked != color) {
            checked = false;
        }
        //if the move would have left him in check revert changes
        if(checked && moved) {
            b[end_y][end_x] -> moveTo(initial);
            b[init_y][init_x] = b[end_y][end_x];
            b[end_y][end_x] = last;
            if(turn == "white") {
                turn = "black";
            }else  {
                turn = "white";
            }
            cout << "You cannot do that because you are in check!\n";
        }
        return;
    }
    //get the move with the possible move set
    b[init_y][init_x] -> updateMoves(b);

    std::vector<Square> possibleMoves = b[init_y][init_x] -> getMoves();
    cout << "# of possible moves: " << possibleMoves.size() << endl;
    moved = false;

    //check if the move is within the set, if not print a statement that lets them know it isn't
    for(auto &pM : possibleMoves) {

        if(pM == dest) {

            Square currentPos = b[init_y][init_x]->getPosition();

            b[init_y][init_x]->moveTo(dest);



            b[end_y][end_x] = b[init_y][init_x];

            b[init_y][init_x] = new Piece(initial, "none");
            moved = true;

            // break out of the loop if move is valid
            break;
        }
    }
    if(!moved) {
        cout << "That is an invalid move.\n";
    } else{
        if(turn == "white") {
            turn = "black";
        }else  {
            turn = "white";
        }
    }
}
bool staleMate(std::vector<std::vector<Piece*> > & b, std::string color) {
    std::vector<Piece *> P;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // first split up the pieces into their own colors
            if (b[i][j]->getName() != '-' && b[i][j]->getColor() == color) {
                P.push_back(b[i][j]);
            }
        }
    }
        for (auto &p : P) {
            if (p->getMoves().size() > 0) {
                return false;
            }
        }
        return true;
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
    bool checked, checkmate = false;
    std::string colorChecked = "none";
    char transform;
    std::string turn = "white";
    while(true) {
        //print out board
        cout << "  0 1 2 3 4 5 6 7\n";
        for(int x = 0; x < 8; x++){
            cout << x << " ";
            for(int y = 0; y < 8; y++) {
                cout << board[x][y]->getName() << ' ';
            }
                cout << "\n";

        }
        cout << "Please input the initial x coordinate: ";
        cin >> init_x;
        cout << "Please input the initial y coordinate: ";
        cin >> init_y;
        board[init_y][init_x] -> updateMoves(board);
        vector<Square> pMA = board[init_y][init_x] -> getMoves();
        for(auto & pM : pMA) {
            cout << "Possible moves; x: " << pM.x << ", y: " << pM.y << endl;
        }
        cout << "Please input the destination x coordinate: ";
        cin >> end_x;
        cout << "Please input the destination y coordinate: ";
        cin >> end_y;
        move(board, init_x, init_y, end_x, end_y, checked, colorChecked, turn);
        cout << "Turn: " << turn << "\n";

        //check if a pawn has made it to the end of the board
        if(board[end_y][end_x] -> getName() == 'p' || board[end_y][end_x] -> getName() == 'P') {
            if (end_y == 0 && board[end_x][end_y] -> getColor() == "white" || end_y == 7 && board[end_x][end_y] -> getColor() == "black" ) {
                cout << "Please choose what piece you would like to transform you pawn into: ";
                cin >> transform;
                if(transform == 'R') {
                    Rook* r = new Rook(board[end_y][end_x] -> getPosition(), board[end_y][end_x] -> getColor());
                    board[end_y][end_x] = r;
                } else if(transform == 'N') {
                    Knight* k = new Knight(board[end_y][end_x] -> getPosition(), board[end_y][end_x] -> getColor());
                    board[end_y][end_x] = k;
                } else if (transform == 'B') {
                    Bishop* b = new Bishop(board[end_y][end_x] -> getPosition(), board[end_y][end_x] -> getColor());
                    board[end_y][end_x] = b;
                } else if (transform == 'Q') {
                    Queen* q = new Queen(board[end_y][end_x] -> getPosition(), board[end_y][end_x] -> getColor());
                    board[end_y][end_x] = q;
                }
            }
        }
        checked = check(board, colorChecked);
        if(checked) {
            checkmate = checkMate(board, colorChecked);
            if(checkmate) {
                if(colorChecked == "white") {
                    cout << "Black has Won";
                } else {
                    cout << "White has won";
                }
                break;
            }
        }

    }

    return 0;
}
