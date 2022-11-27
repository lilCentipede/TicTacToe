#include "Algorithm.h"

Algorithm::Algorithm(Board _board,Human _human, AI _ai) : board(_board), human(_human), ai(_ai) {}
Algorithm::Algorithm(const Algorithm& _other) : board(_other.board), human(_other.human), ai(_other.ai) {}


void Algorithm::play() {
	std::pair<int, int> move;
	bool finished = false;
	while (!finished) {
		if (human.isHumansTurn()) {
			move = human.playMove(board);
			if (board.isAWinningMove(move.first, move.second)) {
				finished = true;
				std::cout << "Human won!\n";
			}
			else if (board.isDraw()) {
				finished = true;
				std::cout << "It is a draw!\n";
			}
		} 
		else {
			move = ai.calculateBestMove(board);
			if (board.isAWinningMove(move.first, move.second)) {
				finished = true;
				std::cout << "AI won!\n";
			}
			else if (board.isDraw()) {
				finished = true;
				std::cout << "It is a draw!\n";
			}
		}
		board.printTable();
		human.swapValueOfHumansTurn();
		ai.swapValueOfAIsTurn();
	}
}