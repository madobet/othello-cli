cmake_minimum_required(VERSION 3.14)
project(MCST_Othello_CLI)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MCST_Othello_CLI
        main.cpp
        MCST_node.cpp
        MCST_node.h
        Othello_game.cpp
        Othello_game.h)
