//
// Created by Wayne Stevens on 4/20/18.
//

#include "Queen.h"
Queen::Queen(Square square, std::string color) {
    position = square;
    player = color;
    if(color == "white" || color == "White" || color == "WHITE" || color == "w" || color == "W") {
        piece_name = 'Q';
    } else {
        piece_name = 'q';
    }
}

Queen::Queen(std::string color) {
    player = color;
    if(color == "white" || color == "White" || color == "WHITE" || "w" || "W") {
        position = Square(3, 7);
        piece_name = 'Q';
    } else {
        position = Square(3, 0);
        piece_name = 'q';
    }
}

void Queen::updateMoves(std::vector<std::vector<Piece*> > board) {
    // These are the possible X values and Y values that the new square can take

    bool stopN, stopNE, stopE, stopSE, stopS, stopSW, stopW, stopNW = false;
    moveList.clear();
    for(int i = 1; i < 8; i++) {
        int poss_x[2] = {position.x + i, position.x - i};
        int poss_y[2] = {position.y + i, position.y - i};

        // check to see if potential row and column pair is valid
        if(validPosition(poss_x[0], poss_y[0])&&!stopN) {
            if(board[poss_y[0]][poss_x[0]] -> getColor() == player) {
                stopN = true;
            } else if(board[poss_y[0]][poss_x[0]] -> getColor() != "none") {
                moveList.push_back(Square(poss_x[0], poss_y[0]));
                stopN = true;
            }
            if(!stopN) {
                moveList.push_back(Square(poss_x[0], poss_y[0]));
            }
        }
        if(validPosition(poss_x[0], poss_y[1])&&!stopNE) {
            if(board[poss_y[1]][poss_x[0]] -> getColor() == player) {
                stopNE = true;
            } else if(board[poss_y[1]][poss_x[0]] -> getColor() != "none") {
                moveList.push_back(Square(poss_x[0], poss_y[1]));
                stopNE = true;
            }
            if(!stopNE) {
                moveList.push_back(Square(poss_x[0], poss_y[1]));
            }

        }
        if(validPosition(poss_x[1], poss_y[0])&&!stopE) {
            if(board[poss_y[0]][poss_x[1]] -> getColor() == player) {
                stopE = true;
            } else if(board[poss_y[0]][poss_x[1]] -> getColor() != "none") {
                moveList.push_back(Square(poss_x[1], poss_y[0]));
                stopE = true;
            }
            if(!stopE) {
                moveList.push_back(Square(poss_x[1], poss_y[0]));
            }

        }
        if(validPosition(poss_x[1], poss_y[1])&&!stopSE) {
            if(board[poss_y[1]][poss_x[1]] -> getColor() == player) {
                stopSE = true;
            } else if(board[poss_y[1]][poss_x[1]] -> getColor() != "none") {
                moveList.push_back(Square(poss_x[1], poss_y[1]));
                stopSE = true;
            }
            if(!stopSE) {
                moveList.push_back(Square(poss_x[1], poss_y[1]));
            }
        }
        if(validPosition(poss_x[0], position.y)&&!stopS) {
            if(board[position.y][poss_x[0]] -> getColor() == player) {
                stopS = true;
            } else if(board[position.y][poss_x[0]] -> getColor() != "none") {
                moveList.push_back(Square(poss_x[0], position.y));
                stopS = true;
            }
            if(!stopS) {
                moveList.push_back(Square(poss_x[0], position.y));
            }

        }
        if(validPosition(poss_x[1], position.y)&&!stopSW) {
            if(board[position.y][poss_x[1]] -> getColor() == player) {
                stopSW = true;
            } else if(board[position.y][poss_x[1]] -> getColor() != "none") {
                moveList.push_back(Square(poss_x[1], position.y));
                stopSW = true;
            }
            if(!stopSW) {
                moveList.push_back(Square(poss_x[1], position.y));
            }

        }
        if(validPosition(position.x, poss_y[0])&&!stopW) {
            if(board[poss_y[0]][position.x] -> getColor() == player) {
                stopW = true;
            } else if(board[poss_y[0]][position.x] -> getColor() != "none") {
                moveList.push_back(Square(position.x, poss_y[0]));
                stopW = true;
            }
            if(!stopW) {
                moveList.push_back(Square(position.x, poss_y[0]));
            }

        }
        if(validPosition(position.x, poss_y[1])&&!stopNW) {
            if(board[poss_y[1]][position.x] -> getColor() == player) {
                stopNW = true;
            } else if(board[poss_y[1]][position.x] -> getColor() != "none") {
                moveList.push_back(Square(position.x, poss_y[1]));
                stopNW = true;
            }
            if(!stopNW) {
                moveList.push_back(Square(position.x, poss_y[1]));
            }
        }
    }

}

void Queen::moveTo(Square newPosition) {
    position = newPosition;
}

std::vector<Square> Queen::getMoves() {
    return moveList;
}

Square Queen::getPosition() {return position;}
std::string Queen::getColor(){return player;}
char Queen::getName() {return piece_name;}
