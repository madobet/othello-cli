#include<iostream>
#include<stdlib.h>
#include<time.h>

#include"Othello_game.h"
#include"MCST_node.h"


using namespace std;
double total_time = 0.0;
int main() {
	char c;
	int a, b;
	bool firsthand;
	Othello_game* othello = new Othello_game();
    othello->ShowBoard();
	MCST_node *mtree=  new MCST_node(othello);
	std::cout << "AI先手请输入1，后手输入0" << std::endl;
	std::cin >> firsthand;
	int COMPUTER = Othello_game::WHITE;
	if(firsthand)
		COMPUTER = Othello_game::BLACK;
	srand(time(0));
	while (mtree->game->GameStatus() == Othello_game::PLAYING) {
		if (mtree->game->WhosRound() == COMPUTER) {
			mtree = mtree->SearchAndPlay();
		}
		else {

	//		srand(time(0));
	//		mtree = mtree->Play(rand() % mtree->game->moves_set.size());
            std::cout << "行号：" << std::endl;
			std::cin >> a;
			if (a < 0 || a > 7) {
			    std::cout << "无效行号，自动洛子" << std::endl;
				srand(time(0));
				mtree = mtree->Play(rand() % mtree->game->moves_set.size());
			}
			else {
			    std::cout << "列号：" << std::endl;
				std::cin >> b;
                std::cout << "选中了第 " << a << " 行 " << b << " 列" << endl;
				mtree = mtree->Play(a, b);
			}
		}
        mtree->game->ShowBoard();
	}
	if (mtree->game->GameStatus() == Othello_game::WHITE) {
		std::cout << "白棋胜!" << std::endl;
	}
	else if (mtree->game->GameStatus() == Othello_game::BLACK) {
		std::cout << "黑棋胜!" << std::endl;
	}else {
		std::cout << "平局!" << std::endl;
	}
	std::cin >> c;
	/*
	while (1) {
		cin >> c;
		if (c == 'p') {
			game->RandMove(); game->ShowBoard();
			game = new Othello_game(*game);
			mtree->FreeTree();
			mtree = new MCST_node(game);
		}
		else if (c == 's'){
			mtree->SearchOnce();
			mtree->PrintTree(0);
		}
	}
	*/
}
