#pragma once
#include <iostream>
#include <assert.h>
#include "Board.h"

class Human
{
	bool humans_turn;
	char mark;
	std::pair<int,int> currentBestMove;
public:
	Human(bool _humans_turn, char _mark);
	Human(const Human& _other);

	std::pair<int,int> playMove(Board& _board);
	bool isHumansTurn();
	void swapValueOfHumansTurn();
	char getMark();
};

