#include "AI.h"

AI::AI(bool _ais_turn, char _mark, char _human_mark) : ais_turn(_ais_turn), mark(_mark), human_mark(_human_mark) {
	currentBestMove = std::make_pair(0, 0);
}
AI::AI(const AI& _other): 
	ais_turn(_other.ais_turn),
	mark(_other.mark),
	human_mark(_other.human_mark),
	currentBestMove(_other.currentBestMove)
{}

bool AI::isAIsTurn() {
	return ais_turn;
}
void AI::swapValueOfAIsTurn() {
	ais_turn = !ais_turn;
}


//the first step of the AI
std::pair<int, int> AI::calculateBestMove(Board& _board) {
	std::pair<int, int> bestMove;
	int v = INT_MAX;
	for (int row = 1; row <= _board.getSize(); row++) {
		for (int column = 1; column <= _board.getSize(); column++) {
			if (_board.isPlaceEmpty(row, column)) {
				ScoreAndPlace result = minmax(_board, row, column);
				int candidateValue = result.getScore();
				if (v > candidateValue) {
					v = candidateValue;
					bestMove = std::make_pair(row,column);
				}
			}
		}
	}
	_board.setPlaceOnBoard(bestMove.first, bestMove.second, mark);
	return bestMove;
}

ScoreAndPlace AI::minmax(Board _board, int _row, int _column) {
	_board.setPlaceOnBoard(_row, _column, mark);
	return maxValue(_board, _row, _column);

}
//best for Human
ScoreAndPlace AI::maxValue(Board _board, int _row, int _column) {
	if (_board.isAWinningMove(_row, _column)) {
		return ScoreAndPlace(ScoreAndPlace::AI_WINS, std::make_pair(_row,_column));
	} 
	else if (_board.isDraw()) {
		return ScoreAndPlace(ScoreAndPlace::DRAW, std::make_pair(_row, _column));
	}
	std::pair<int, int> bestMove;
	int v = INT_MIN;
	for (int row = 1; row <= _board.getSize(); row++) {
		for (int column = 1; column <= _board.getSize(); column++) {
			if (_board.isPlaceEmpty(row, column)) {
				Board new_board(_board);
				new_board.setPlaceOnBoard(row, column, human_mark);
				ScoreAndPlace candidate( minValue(new_board, row, column) );
				int valueCandidate = candidate.getScore();
				if (v < valueCandidate) {
					v = valueCandidate;
					bestMove = candidate.getPlace();
				}
			}
		}
	}
	return ScoreAndPlace(v, bestMove);
}
//best for AI
ScoreAndPlace AI::minValue(Board _board, int _row, int _column) {
	if (_board.isAWinningMove(_row, _column)) {
		return ScoreAndPlace(ScoreAndPlace::HUMAN_WINS, std::make_pair(_row, _column));
	}
	else if (_board.isDraw()) {
		return ScoreAndPlace(ScoreAndPlace::DRAW, std::make_pair(_row, _column));
	}
	std::pair<int, int> bestMove;
	int v = INT_MAX;
	for (int row = 1; row <= _board.getSize(); row++) {
		for (int column = 1; column <= _board.getSize(); column++) {
			if (_board.isPlaceEmpty(row, column)) {
				Board new_board(_board);
				new_board.setPlaceOnBoard(row, column, mark);
				ScoreAndPlace candidate( maxValue(new_board, row, column) );
				int valueCandidate = candidate.getScore();
				if (v > valueCandidate) {
					v = valueCandidate;
					bestMove = candidate.getPlace();
				}
			}
		}
	}
	return ScoreAndPlace(v, bestMove);
}