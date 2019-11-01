#ifndef OTHELLO_GAME_H
#define OTHELLO_GAME_H

#include <iostream>
#include <vector>
#include <random>
#include <memory.h>

#define BOARD_LEN 8
#define BOARD_SIZE 64

// class that record a possibile playing position 
// along with the number of chesses that should be reversed in each direction if the position is played
class One_move {    // One possible move
public:
    One_move(int pos, const int* rev_n ):move_pos(pos) {
        for( int i = 0; i < BOARD_LEN; i++) rev_n_of_dir[i] = rev_n[i];
    }
    // where to put the piece
    const int move_pos;
    // how many pieces of competitor at each direction will be reversed
    // when put piece at move_pos
    int rev_n_of_dir[BOARD_LEN] = {};
};

class Othello_game {
public:
    enum Game_type {
        PVP,
        PVE
    };
	Othello_game();
	
	// parameters that record the state of a position on the curr_position
	// or the state of the game
	static const int BLACK;
	static const int WHITE;
	static const int EMPTY;
	static const int DRAW;
	static const int PLAYING;
    static const int INVALID;
	static const int DIRSET[8][2];

    const Game_type game_type;

    // all possible next moves
    std::vector<One_move> moves_set;

    static inline int Posof(int x, int y) {  return x * 8 + y; }
    static inline int Xof(int pos) {  return pos >> 3; }
    static inline int Yof(int pos) {  return pos % 8;  }

    inline int WhosRound() { return curr_round; }
    inline int GameStatus() { return game_status; }
    inline int PieceColorAt(int x, int y) {
        if(x < BOARD_LEN && y < BOARD_LEN)
            return curr_position[Posof(x,y)];
        return INVALID;
    }

    // 打印当前盘面
    int ShowBoard();
    int Move(int pos);
    int Move(One_move move_obj);
    // Move the curr_position randomly
    int RandMove();

private:
    // the player of the current game
	int curr_round;     // 执子状态：黑方还是白方？

    // state of the curr_position
    // BLACK / WHITE / PLAYING / DRAW
    //  黑胜  / 白胜   / 对局中   / 平局
    // BLACK or WHITE means the game is over and the winner is BLACK or WHITE
    int game_status;

	// state of each position
	// BLACK / WHITE / EMPTY
    // Position 局面,棋盘落子状态，每个格子对应三种状态中一种
	int curr_position[64] = {};

    // update the moves_set
	void UpdateMovesSet();
};

#endif