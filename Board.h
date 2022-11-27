#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
class Board
{
	char empty_symbol;
	int size;
	int filledPlaces;
	std::vector<std::vector<char>> table;
	bool checkForRow(int _row, char mark);
	bool checkForColumn(int _column,char mark);
	bool checkForMainDiagonal(char mark);
	bool checkForReverseDiagonal(char mark);
public:
	Board(char _empty_symbol, int _size);
	Board(char _empty_symbol, int _size, std::vector<std::vector<char>> _table);
	Board(const Board& _other);
	void setPlaceOnBoard(int _row, int _column, char _symbol);
	char getPlaceOnBoard(int _row, int _column);
	void printTable();
	int getSize();
	char getEmptySymbol();
	bool isPlaceEmpty(int _row, int _column);
	bool isAWinningMove(int _row, int _column);
	bool isDraw();
};

