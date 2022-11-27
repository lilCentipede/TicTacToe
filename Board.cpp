#include "Board.h"


Board::Board(char _empty_symbol, int _size) : empty_symbol(_empty_symbol), size(_size), filledPlaces(0) {
	for(int i = 0; i < size; i++) {
		std::vector<char> vec;
		for (int j = 0; j < size; j++) {
			vec.push_back(empty_symbol);
		}
		table.push_back(vec);
	}
	max_depth = size * size + 1;
}
Board::Board(char _empty_symbol, int _size, std::vector<std::vector<char>> _table) : empty_symbol(_empty_symbol), size(_size), table(_table) {
	filledPlaces = 0;
	for (int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if (table[i][j] != empty_symbol)
				filledPlaces++;
		}
	}
	max_depth = size * size + 1;
}
Board::Board(const Board& _other):
	empty_symbol(_other.empty_symbol),
	size(_other.size),
	filledPlaces(_other.filledPlaces),
	table(_other.table),
	max_depth(_other.max_depth)
{}
void Board::setPlaceOnBoard(int _row, int _column,char _symbol) {
	assert(1 <=_row && _row <= size && 1 <= _column && _column <= size);
	int x = _row - 1, y = _column - 1;
	table[x][y] = _symbol;
	filledPlaces++;
}

char Board::getPlaceOnBoard(int _row, int _column) {
	assert(1 <= _row && _row <= size && 1 <= _column && _column <= size);
	int x = _row - 1, y = _column - 1;
	return table[x][y];
}

int Board::getSize() {
	return size;
}
int Board::getMaxDepth() {
	return max_depth;
}
char Board::getEmptySymbol() {
	return empty_symbol;
}
bool Board::isPlaceEmpty(int _row, int _column) {
	assert(1 <= _row && _row <= size && 1 <= _column && _column <= size);
	int x = _row - 1, y = _column - 1;
	return table[x][y] == empty_symbol;
}

bool Board::isAWinningMove(int _row, int _column) {
	assert(1 <= _row && _row <= size && 1 <= _column && _column <= size);
	int x = _row - 1, y = _column - 1;
	char mark = table[x][y];
	bool result = true;

	if (checkForRow(_row, mark))
		return true;
	if (checkForColumn(_column, mark))
		return true;
	if (x == y && checkForMainDiagonal(mark))
		return true;
	if ((x + y == size - 1) && checkForReverseDiagonal(mark))
		return true;

	return false;

}
//should follow after isAWinningMove
bool Board::isDraw() {
	return filledPlaces == size*size;
}

void Board::printTable() {
	std::cout << "-------------------\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << table[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << "-------------------\n";
}
bool Board::checkForRow(int _row, char mark) {
	int x = _row - 1;
	for (int j = 0; j < size; j++) {
		if (table[x][j] != mark)
			return false;
	}
	return true;
}

bool Board::checkForColumn(int _column, char mark) {
	int y = _column - 1;
	for (int i = 0; i < size; i++) {
		if (table[i][y] != mark)
			return false;
	}
	return true;
}

bool Board::checkForMainDiagonal(char mark) {
	for (int k = 0; k < size; k++) {
		if (table[k][k] != mark)
			return false;
	}
	return true;
}
bool Board::checkForReverseDiagonal(char mark) {
	for (int k = 0; k < size; k++) {
		if (table[k][size - k - 1] != mark)
			return false;
	}
	return true;
}