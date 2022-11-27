#pragma once
#include "Board.h"
#include "Human.h"
#include "AI.h"
class Algorithm
{
private:
	Board board;
	Human human;
	AI ai;
public:
	Algorithm(Board _board,Human _human, AI _ai);
	Algorithm(const Algorithm& _other);
	void play();


};

