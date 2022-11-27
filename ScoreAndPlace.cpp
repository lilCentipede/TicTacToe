#include "ScoreAndPlace.h"

ScoreAndPlace::ScoreAndPlace(int _score, std::pair<int, int> _place) : score(_score), place(_place) {}
ScoreAndPlace::ScoreAndPlace(const ScoreAndPlace& _other): score(_other.score), place(_other.place) {}

std::string ScoreAndPlace::scoreToString(int _score) {
	switch (_score) {
	case HUMAN_WINS:
		return "HUMAN WINS";
		break;
	case AI_WINS:
		return "AI WINS";
		break;
	case DRAW:
		return "DRAW";
		break;
	default:
		return "UNRECOGNIZED";
	}
}

