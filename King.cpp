//
// Created by Wayne Stevens on 4/20/18.
//

#include "King.h"
King::King(Square square, std::string color) {
    position = square;
    player = color;
    if(color == "white" || color == "White" || color == "WHITE" || color == "w" || color == "W") {
        piece_name = 'K';
    } else {
        piece_name = 'k';
    }
}

King::King(std::string color) {
    player = color;
    if(color == "white" || color == "White" || color == "WHITE" || "w" || "W") {
        position = Square(4, 7);
        piece_name = 'K';
    } else {
        position = Square(4, 0);
        piece_name = 'k';
    }
}


void King::moveTo(Square newPosition) {
    position = newPosition;
}

void King::updateMoves(std::vector<std::vector<Piece*>> &board) {
    // These are the possible X values and Y values that the new square can take
    moveList.clear();
   

    int poss_x[2] = {position.x + 1, position.x - 1};
    int poss_y[2] = {position.y + 1, position.y - 1};

    // check to see if potential row and column pair is valid
    if(validPosition(poss_x[0], poss_y[0])) {
        if(board[poss_x[0]][poss_y[0]]->getName() == '-' || board[poss_x[0]][poss_y[0]]->getPlayer() != player)
            moveList.push_back(Square(poss_x[0], poss_y[0]));
    }
    if(validPosition(poss_x[0], poss_y[1])) {
        if(board[poss_x[0]][poss_y[1]]->getName() == '-' || board[poss_x[0]][poss_y[1]]->getPlayer() != player)
            moveList.push_back(Square(poss_x[0], poss_y[1]));
    }
    if(validPosition(poss_x[1], poss_y[0])) {
        if(board[poss_x[1]][poss_y[0]]->getName() == '-' || board[poss_x[1]][poss_y[0]]->getPlayer() != player)
            moveList.push_back(Square(poss_x[1], poss_y[0]));
    }
    if(validPosition(poss_x[1], poss_y[1])) {
        if(board[poss_x[1]][poss_y[1]]->getName() == '-' || board[poss_x[1]][poss_y[1]]->getPlayer() != player)
            moveList.push_back(Square(poss_x[1], poss_y[1]));
    }
    if(validPosition(poss_x[0], position.y)) {
        if(board[poss_x[0]][position.y]->getName() == '-' || board[poss_x[0]][position.y]->getPlayer() != player)
            moveList.push_back(Square(poss_x[0], position.y));
    }
    if(validPosition(poss_x[1], position.y)) {
        if(board[poss_x[1]][position.y]->getName() == '-' || board[poss_x[1]][position.y]->getPlayer() != player)
            moveList.push_back(Square(poss_x[1], position.y));
    }
    if(validPosition(position.x, poss_y[0])) {
        if(board[position.x][poss_y[0]]->getName() == '-' || board[position.x][poss_y[0]]->getPlayer() != player)
            moveList.push_back(Square(position.x, poss_y[0]));
    }
    if(validPosition(position.x, poss_y[1])) {
        if(board[position.x][poss_y[1]]->getName() == '-' || board[position.x][poss_y[1]]->getPlayer() != player)
            moveList.push_back(Square(position.x, poss_y[1]));
    }
    

}

Square King::getPosition() {return position;}


std::vector<Square> King::getMoves() {
    return moveList;
}

char King::getName() {return piece_name;}
