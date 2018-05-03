#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "Rook.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
std::string spaceW = "                                             ";
std::string spaceB = "#############################################";
std::string pawnWW = "    _       (_)      | |      |_|            ";
std::string pawnWB = "############(_)######| |######|_|############";
std::string rookWW = "           [`'`']    |  |     |__|           ";
std::string rookWB = "###########[`'`']####|  |#####|__|###########";
std::string knightWW = "           \\`~'/    (o o}     \\ / \\     \"    ";
std::string knightWB = "###########\\`~'/####(o o}#####\\ / \\#####\"####";
std::string bishopWW = "           '\\v/`    (o 0}     (_)            ";
std::string bishopWB = "###########'\\v/`####(o 0}#####(_)############";
std::string queenWW = "   ___     /\\*/\\   /(o o}\\    (_)            ";
std::string queenWB = "###___#####/\\*/\\###/(o o}\\####(_)############";
std::string kingWW = "           |`+'|    (o o}     (_)            ";
std::string kingWB = "###########|`+'|####(o o}#####(_)############";
std::string pawnBW = "    _       (:)      |:|      |:|            ";
std::string pawnBB = "############(:)######|:|######|:|############";
std::string rookBW = "           [`'`']    |::|     |::|           ";
std::string rookBB = "###########[`'`']####|::|#####|::|###########";
std::string knightBW = "           \\`.'/    (o:o}     \\:/:\\     \"    ";
std::string knightBB = "###########\\`.'/####(o:o}#####\\ / \\#####\"####";
std::string bishopBW = "           ':v:`    (o:0}     (:)            ";
std::string bishopBB = "###########':v:`####(o:0}#####(:)############";
std::string queenBW = "   ___     /\\:/\\   /(o:o}\\    (:)            ";
std::string queenBB = "###___#####/\\:/\\###/(o:o}\\####(:)############";
std::string kingBW = "           |:+:|    (o:o}     (:)            ";
std::string kingBB = "###########|:+:|####(o:o}#####(:)############";






bool check(std::vector<std::vector<Piece*> > b, std::string & colorChecked) {
    bool checked = false;
    std::vector<Piece*> whiteP;
    std::vector<Piece*> blackP;
    Square whiteKLoc;
    Square blackKLoc;
    for(int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j++) {
            // first split up the pieces into their own colors and find the location of the kings
            if(b[i][j] -> getName() == 'K') {
                whiteKLoc = b[i][j] -> getPosition();
            } else if(b[i][j] -> getName() == 'k') {
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
        bP -> updateMoves(b);
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
        wP -> updateMoves(b);
        std::vector<Square> whitePMoves = wP -> getMoves();
        for(auto & pM : whitePMoves) {
            if(blackKLoc == pM) {
                checked = true;
                colorChecked = "black";
            }
        }
    }
    return checked;
}
//checks if there has been a checkmate
bool checkMate(std::vector<std::vector<Piece*> > b, std::string & colorChecked) {
    Piece* checkedKing;

    std::vector<Piece*> pieces;
    for(int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j++) {
            if(b[i][j] -> getName() != '-' && b[i][j] -> getColor() == colorChecked){
                pieces.push_back(b[i][j]);
            }
        }
    }
    bool canMove = false;
    std::string color = colorChecked;
    for(auto & p : pieces) {
        p -> updateMoves(b);
        std::vector<Square> moves = p -> getMoves();
        for(auto & m : moves) {
            Piece * last = b[m.y][m.x];
            Square initial = p -> getPosition();
            b[initial.y][initial.x]-> moveTo(m);
            b[m.y][m.x] = b[initial.y][initial.x];
            b[initial.y][initial.x] = new Piece(initial, "none");

            canMove = check(b, color);
            color = colorChecked;

            //revert changes
            b[m.y][m.x]-> moveTo(initial);
            b[initial.y][initial.x] = b[m.y][m.x];
            b[m.y][m.x] = last;
            if(!canMove) {
                return false;
            }
        }

    }
    return true;
}

void convert(char row, int y1, int & x, int & y2){
    y2 = abs(y1 - 8);
    if(row == 'A'){x = 0;}
    if(row == 'B'){x = 1;}
    if(row == 'C'){x = 2;}
    if(row == 'D'){x = 3;}
    if(row == 'E'){x = 4;}
    if(row == 'F'){x = 5;}
    if(row == 'G'){x = 6;}
    if(row == 'H'){x = 7;}

}
void convert( int x, int y2, char & row, int & y1){
    y1 = abs(y2 - 8);
    if(x == 0){row = 'A';}
    if(x == 1){row = 'B';}
    if(x == 2){row = 'C';}
    if(x == 3){row = 'D';}
    if(x == 4){row = 'E';}
    if(x == 5){row = 'F';}
    if(x == 6){row = 'G';}
    if(x == 7){row = 'H';}


}
void move(std::vector<std::vector<Piece*> > & b, int init_x, int init_y, int end_x, int end_y, bool & checked, std::string color, std::string & turn) {
    // implement way to escape check
    std::string colorChecked = color;
    bool moved = false;
    Square dest(end_x, end_y);
    Square initial(init_x, init_y);
    Piece *last = b[end_y][end_x];;
    if(b[init_y][init_x] -> getColor() != turn){
        cout << "That's not your piece!\n";
        return;
    }
    if(checked) {
        b[init_y][init_x] -> updateMoves(b);
        std::vector<Square> possibleM = b[init_y][init_x] -> getMoves();
        Square dest(end_x, end_y);
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
    moved = false;

    //check if the move is within the set, if not print a statement that lets them know it isn't
    for(auto &pM : possibleMoves) {

        if(pM == dest) {

            Square currentPos = b[init_y][init_x]->getPosition();

            b[init_y][init_x]->moveTo(dest);



            b[end_y][end_x] = b[init_y][init_x];
            std::string color;
            b[init_y][init_x] = new Piece(initial, "none");
            moved = true;
            bool dM = check(b, color);
            //if you moved into check move back
            if(dM && color == turn){
                b[end_y][end_x] -> moveTo(initial);
                b[init_y][init_x] = b[end_y][end_x];
                b[end_y][end_x] = last;
                moved = false;
            }

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
std::string tile(int x, int y, char name){
    bool w = (x + y)%2 == 0;
    if(name == '-' && w) {
        return spaceW;
    }else if(name == '-' && !w) {
        return spaceB;
    }else if(name == 'p'){
        if(w) {
            return pawnBW;
        }else{
            return pawnBB;
        }
    }else if(name == 'P'){
        if(w) {
            return pawnWW;
        }else{
            return pawnWB;
        }
    }else if(name == 'r'){
        if(w) {
            return rookBW;
        }else{
            return rookBB;
        }
    }else if(name == 'R'){
        if(w) {
            return rookWW;
        }else{
            return rookWB;
        }
    }else if(name == 'n'){
        if(w) {
            return knightBW;
        }else{
            return knightBB;
        }
    }else if(name == 'N'){
        if(w) {
            return knightWW;
        }else{
            return knightWB;
        }
    }else if(name == 'b'){
        if(w) {
            return bishopBW;
        }else{
            return bishopBB;
        }
    }else if(name == 'B'){
        if(w) {
            return bishopWW;
        }else{
            return bishopWB;
        }
    }else if(name == 'q'){
        if(w) {
            return queenBW;
        }else{
            return queenBB;
        }
    }else if(name == 'Q'){
        if(w) {
            return queenWW;
        }else{
            return queenWB;
        }
    }else if(name == 'k'){
        if(w) {
            return kingBW;
        }else{
            return kingBB;
        }
    }else if(name == 'K'){
        if(w) {
            return kingWW;
        }else{
            return kingWB;
        }
    }
}
void displayBoard(std::vector<std::vector<Piece*> > & b){
    std::string board;
    std::string letters = "                 _        _        _        __       __       _             \n";
    letters = letters +   "       /\\       |_)      /        | \\      |_       |_       /        |_|   \n";
    letters = letters +   "      /--\\      |_)      \\_       |_/      |__      |        \\_?      | |   \n\n";
    board = board + letters;
    for(int i = 0; i < 8; i++){
        std::string tile1 =  tile(0, i, b[i][0] ->getName());
        std::string tile2 =  tile(1, i, b[i][1] ->getName());
        std::string tile3 =  tile(2, i, b[i][2] ->getName());
        std::string tile4 =  tile(3, i, b[i][3] ->getName());
        std::string tile5 =  tile(4, i, b[i][4] ->getName());
        std::string tile6 =  tile(5, i, b[i][5] ->getName());
        std::string tile7 =  tile(6, i, b[i][6] ->getName());
        std::string tile8 =  tile(7, i, b[i][7] ->getName());
        if(i == 0){
            board = board + "    ";
        }else if(i == 1){
            board = board + "    ";
        }else if(i == 2){
            board = board + "    ";
        }else if(i == 3){
            board = board + "    ";
        }else if(i == 4){
            board = board + "    ";
        }else if(i == 5){
            board = board + "    ";
        }else if(i == 6){
            board = board + "    ";
        }else if(i == 7){
            board = board + "    ";
        }else if(i == 9){
            board = board + "    ";
        }
        for(int j = 0; j < 9; j++){board = board + tile1[j];}
        for(int j = 0; j < 9; j++){board = board + tile2[j];}
        for(int j = 0; j < 9; j++){board = board + tile3[j];}
        for(int j = 0; j < 9; j++){board = board + tile4[j];}
        for(int j = 0; j < 9; j++){board = board + tile5[j];}
        for(int j = 0; j < 9; j++){board = board + tile6[j];}
        for(int j = 0; j < 9; j++){board = board + tile7[j];}
        for(int j = 0; j < 9; j++){board = board + tile8[j];}
        board = board + "\n";
        if(i == 0){
            board = board + " _  ";
        }else if(i == 1){
            board = board + " __ ";
        }else if(i == 2){
            board = board + "    ";
        }else if(i == 3){
            board = board + " _  ";
        }else if(i == 4){
            board = board + "  . ";
        }else if(i == 5){
            board = board + " _  ";
        }else if(i == 6){
            board = board + " _  ";
        }else if(i == 7){
            board = board + "    ";
        }else if(i == 9){
            board = board + "    ";
        }
        for(int j = 9; j < 18; j++){board = board + tile1[j];}
        for(int j = 9; j < 18; j++){board = board + tile2[j];}
        for(int j = 9; j < 18; j++){board = board + tile3[j];}
        for(int j = 9; j < 18; j++){board = board + tile4[j];}
        for(int j = 9; j < 18; j++){board = board + tile5[j];}
        for(int j = 9; j < 18; j++){board = board + tile6[j];}
        for(int j = 9; j < 18; j++){board = board + tile7[j];}
        for(int j = 9; j < 18; j++){board = board + tile8[j];}
        board = board + "\n";
        if(i == 0){
            board = board + "(_) ";
        }else if(i == 1){
            board = board + "  / ";
        }else if(i == 2){
            board = board + " /  ";
        }else if(i == 3){
            board = board + "|_  ";
        }else if(i == 4){
            board = board + " /| ";
        }else if(i == 5){
            board = board + " _) ";
        }else if(i == 6){
            board = board + "  ) ";
        }else if(i == 7){
            board = board + " /| ";
        }else if(i == 9){
            board = board + "    ";
        }
        for(int j = 18; j < 27; j++){board = board + tile1[j];}
        for(int j = 18; j < 27; j++){board = board + tile2[j];}
        for(int j = 18; j < 27; j++){board = board + tile3[j];}
        for(int j = 18; j < 27; j++){board = board + tile4[j];}
        for(int j = 18; j < 27; j++){board = board + tile5[j];}
        for(int j = 18; j < 27; j++){board = board + tile6[j];}
        for(int j = 18; j < 27; j++){board = board + tile7[j];}
        for(int j = 18; j < 27; j++){board = board + tile8[j];}
        board = board + "\n";
        if(i == 0){
            board = board + "(_) ";
        }else if(i == 1){
            board = board + " /  ";
        }else if(i == 2){
            board = board + "(_) ";
        }else if(i == 3){
            board = board + " _) ";
        }else if(i == 4){
            board = board + "'-| ";
        }else if(i == 5){
            board = board + " _) ";
        }else if(i == 6){
            board = board + "/_  ";
        }else if(i == 7){
            board = board + "  | ";
        }else if(i == 9){
            board = board + "    ";
        }
        for(int j = 27; j < 36; j++){board = board + tile1[j];}
        for(int j = 27; j < 36; j++){board = board + tile2[j];}
        for(int j = 27; j < 36; j++){board = board + tile3[j];}
        for(int j = 27; j < 36; j++){board = board + tile4[j];}
        for(int j = 27; j < 36; j++){board = board + tile5[j];}
        for(int j = 27; j < 36; j++){board = board + tile6[j];}
        for(int j = 27; j < 36; j++){board = board + tile7[j];}
        for(int j = 27; j < 36; j++){board = board + tile8[j];}
        board = board + "\n";
        if(i == 0){
            board = board + "    ";
        }else if(i == 1){
            board = board + "    ";
        }else if(i == 2){
            board = board + "    ";
        }else if(i == 3){
            board = board + "    ";
        }else if(i == 4){
            board = board + "    ";
        }else if(i == 5){
            board = board + "    ";
        }else if(i == 6){
            board = board + "    ";
        }else if(i == 7){
            board = board + "    ";
        }else if(i == 9){
            board = board + "    ";
        }
        for(int j = 36; j < 45; j++){board = board + tile1[j];}
        for(int j = 36; j < 45; j++){board = board + tile2[j];}
        for(int j = 36; j < 45; j++){board = board + tile3[j];}
        for(int j = 36; j < 45; j++){board = board + tile4[j];}
        for(int j = 36; j < 45; j++){board = board + tile5[j];}
        for(int j = 36; j < 45; j++){board = board + tile6[j];}
        for(int j = 36; j < 45; j++){board = board + tile7[j];}
        for(int j = 36; j < 45; j++){board = board + tile8[j];}
        board = board + "\n";
    }
    cout << board << "\n";
}

int main () {
// Welcome
cout << "***********************************************\n";
cout << " ________ .__\n";
cout << "\\_   ___ \\|  _|__   ____   ______ ______\n";
cout << "/    \\  \\/|  |  \\_/ __ \\ /  ___//  ___/\n";
cout << "\\     \\___|   Y  \\  ___/ \\___ \\ \\___ \\\n";
cout << " \\______  /___|  /\\___  >____  >____  >\n";
cout << "        \\/     \\/     \\/     \\/     \\/\n\n";
cout << "***********************************************\n\n";
cout << "By James Yu, Jordan Harvey-Morgan, Ransom Contant, Wayne Stevens, and Yufei\n\n";

cout << "Black is on Top and White is on the Bottom\n\n";


// initialize board

    std::string c;
    std::string boardDisplay;
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
        std::string instruction;
    int init_x, init_y, end_x, end_y;
    bool checked, checkmate = false;
    std::string colorChecked = "none";
    char transform;
    std::string turn = "white";
    int size;
    vector<Square> pMA;
    while(true) {
        cout << "\n\nIt's " << turn << "'s turn\n\n";
        displayBoard(board);
        if(checkmate) {
            cout << "Checkmate!";
            if(colorChecked == "white") {
                cout << " Black has Won!" << std::flush;
                while(true){};
            } else {
                cout << " White has Won!" << std::flush;
                while(true){};
            }
        }else if (checked){
            cout << "Check!\n";
        }
        do {
        cout << "Select Your Piece: ";
        cin >> instruction;
        std::string::size_type sz;
        convert(instruction[0], instruction[1] - 48, init_x, init_y);

            board[init_y][init_x]->updateMoves(board);
            pMA = board[init_y][init_x]->getMoves();
            size = pMA.size();
            if(size == 0){
                cout << "You can't move that piece!\n";
            }
        }while(size == 0);
        cout << "Possible moves: ";
        for(auto & pM : pMA) {
            char a;
            int b;
            convert(pM.x, pM.y, a, b);
            cout << a <<  b << ", ";
        }
        cout << "\nSelect Your Destination: ";
        cin >> instruction;
        convert(instruction[0], instruction[1] - 48, end_x, end_y);

        move(board, init_x, init_y, end_x, end_y, checked, colorChecked, turn);

        //check if a pawn has made it to the end of the board
        if(board[end_y][end_x] -> getName() == 'p' || board[end_y][end_x] -> getName() == 'P') {
            if (end_y == 0 && board[end_y][end_x] -> getColor() == "white" || end_y == 7 && board[end_y][end_x] -> getColor() == "black" ) {
                cout << "Please choose what piece you would like to transform you pawn into(Q, R, N, or B): ";
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
        }

    }

    return 0;
}
