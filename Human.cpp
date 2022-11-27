#include "Human.h"

Human::Human(bool _humans_turn, char _mark) : humans_turn(_humans_turn), mark(_mark) {
	currentBestMove = std::make_pair(0, 0);
}

Human::Human(const Human& _other):
	humans_turn(_other.humans_turn),
	mark(_other.mark),
	currentBestMove(_other.currentBestMove)
{}

char Human::getMark() { return mark; }

//not done
std::pair<int,int> Human::playMove(Board& _board) {
	int row = 0;
	int column = 0;
	bool moveChosen = false;
	while (!moveChosen) {
		while
			(( row <= 0 || row > _board.getSize()) ||
			(  column <= 0 || column > _board.getSize())) {
			std::cout << "Write a correct move:\n";
			std::cin >> row >> column;
		}

		if (_board.isPlaceEmpty(row, column)) {
			_board.setPlaceOnBoard(row, column, mark);
			moveChosen = true;
		} 
		else {
			row = 0;
			column = 0;
		}
	}
	return std::make_pair(row, column);
}

bool Human::isHumansTurn() {
	return humans_turn;
}

void Human::swapValueOfHumansTurn() {
	humans_turn = !humans_turn;
}

