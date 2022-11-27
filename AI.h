#pragma once
#include <iostream>
#include <assert.h>
#include <limits>
#include <algorithm>
#include "Board.h"
#include "ScoreAndPlace.h"
class AI
{
	bool ais_turn;
	char mark;
	char human_mark;
	std::pair<int, int> currentBestMove;
public:
	AI(bool _ais_turn, char _mark, char _human_mark);
	AI(const AI& _other);

	bool isAIsTurn();
	void swapValueOfAIsTurn();
	std::pair<int, int> calculateBestMove(Board& _board);
	ScoreAndPlace minmax(Board _board,int _row, int _column);
	ScoreAndPlace maxValue(Board _board, int _row, int _column);
	ScoreAndPlace minValue(Board _board, int _row, int _column);
};

