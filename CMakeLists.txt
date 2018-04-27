cmake_minimum_required(VERSION 3.9)
project(Final_Project)

set(CMAKE_CXX_STANDARD 11)

add_executable(Final_Project
        main.cc
        Piece.cc
        Piece.h Square.cpp Square.h Knight.cpp Knight.h Bishop.cpp Bishop.h Queen.cpp Queen.h King.cpp King.h Pawn.cpp Pawn.h Rook.cpp Rook.h)
