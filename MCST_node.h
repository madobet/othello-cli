#ifndef MCST_NODE_H
#define MCST_NODE_H

#include<iostream>
#include<math.h>
#include<time.h>
#include"Othello_game.h"

extern double total_time;

class MCST_node {   // the Monte Carlo Search Tree Node
public:
    // game state
    Othello_game *game;

	MCST_node(Othello_game *othello);
    ~MCST_node();

	MCST_node* SearchAndPlay();
	MCST_node* Play(int n);
	MCST_node* Play(int x, int y);
	void BackPropagation(double val);
	void FreeTree();

	//FOT TEST, print out the tree, can be just a number of levels
	void PrintTree(int level, int tatrgetlevel);
	void PrintTree(int level);

private:
    MCST_node *parent;
    std::vector<MCST_node*> child;
    // Monte Carlo Value for the calcutation of UCT
    int v_n;
    double a_n;
    // number of chesses on the curr_position
    int black_n;
    int white_n;

	// get the search time bound
	inline double EstimatTimeLimit(){
		double base = 20;
		double childrenfactor;
		double processfactor;

		int csize = child.size();
		if(csize == 1) return 0;
		if (csize > 10) csize = 10;
		childrenfactor = csize / 2.0;

		int count = black_n + white_n;
		if (count < 32) processfactor = 0;
		else {
			processfactor = (32.0 - count) / 32.0 * 15.0;
		}

		double res = base + childrenfactor + processfactor;
		if(res > 58) res = 58;
		return res;
	}
	int TreePolicy();
	int DefaultPolicy();
	int SearchOnce();
};

#endif