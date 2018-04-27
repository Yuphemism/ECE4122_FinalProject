#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "BoardSq.h"
#include "Pawn.h"
#include "Rook.h"
using namespace std;

int main () {
    Pawn b(Square(1,4), "white");
    b.updateMoves();
    cout << "Pawn at " << b.getPosition().x << "," << b.getPosition().y << endl;
    for(Square s : b.getMoves()){
        cout << s.x << "," << s.y << endl;
    }
    b.moveTo(Square(1,4));
    b.updateMoves();
    cout << "Pawn at " << b.getPosition().x << "," << b.getPosition().y << endl;
    for(Square s : b.getMoves()){
        cout << s.x << "," << s.y << endl;
    }





//    Square sq1(1,4);
//    Square sq2(3,5);
//    Knight n(sq1,"black");
////    Knight n2("black");
//    Bishop b(Square(5,7), "white");
//    Queen q("white");
//
//    n.updateMoves();
//
//    cout<< "Knight\n";
//    for(Square s : n.getMoves()){
//        std::cout<< s.x << ", "<< s.y<<"\n";
//    }
//
//    n.moveTo(sq2);
//    n.updateMoves();
//
//    cout<<"Knight after move\n";
//
//    for(Square s : n.getMoves()){
//        std::cout<< s.x << ", "<< s.y<<"\n";
//    }
//
//    cout<< "Bishop\n";
//    b.updateMoves();
//    for(Square s : b.getMoves()){
//        std::cout<< s.x << ", "<< s.y<<"\n";
//    }
//    b.moveTo(Square(6,6));
//
//    cout << "Bishop after Move" << endl;
//
//    b.updateMoves();
//    for(Square s : b.getMoves()){
//        std::cout<< s.x << ", "<< s.y<<"\n";
//    }
//
//    cout<< "Queen\n";
//    q.updateMoves();
//    for(Square s : q.getMoves()){
//        std::cout<< s.x << ", "<< s.y<<"\n";
//    }
//// initialize board
//    //BoardSq  board[8][8];
//
//    Bishop *white_bishops;
//    Piece * board;
//    for (int i=0; i < 8; i++) {
//        Square sq(1,i);
//        //white_bishops[i] = new Pawn(sq,"white");
//    }
//
////    for(int i = 0; i < 8; i++) {
////        if( i == 1 ) {
////            for (int j = 0; j < 8; j++) {
////
////                board[i][j].updateSQ(white_pawns[j]);
////                cout<< "board square content \n";
////                cout<< board[1][j].getPiece()<<"\n";
////            }
////        }
////    }
////
////   cout<< "board square content";
////   for(int i =0; i < 8; i++) {
////       cout<< board[1][i].getPiece()<<"\n";
////       delete board[1][i].piece_type;
////   }
//

    return 0;
}