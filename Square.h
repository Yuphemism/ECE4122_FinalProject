//
// Created by Wayne Stevens on 4/11/18.
//
#include <iostream>

#ifndef SQUARE_H
#define SQUARE_H


class Square {

//private:


public:
    int x, y;
    //Constructor
    Square();
    Square(int x_coord, int y_coord);

    //Operators
    Square & operator = (const Square & square);
    bool operator== (const Square & Rsquare) const;
    bool operator!= (const Square & Rsquare) const;

};


#endif //SQUARE_H
