#pragma once
#include <iostream>
class ScoreAndPlace {
private:
	int score;
	std::pair<int, int> place;
public:
	static const int HUMAN_WINS = 1;
	static const int AI_WINS = -1;
	static const int DRAW = 0;
	ScoreAndPlace(int _score, std::pair<int, int> _place);
	ScoreAndPlace(const ScoreAndPlace& _other);

	static std::string scoreToString(int _score);
	int getScore() { return score; }
	int getRow() { return place.first; }
	int getColumn() { return place.second; }
	std::pair<int, int> getPlace() { return place; }
};