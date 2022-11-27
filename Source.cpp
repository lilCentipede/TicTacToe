#include <iostream>
#include "Algorithm.h"

int main() {
	std::string whoPlaysFirst;
	std::cout<<"Who should play first? Write Human or AI\n";
	std::cin >> whoPlaysFirst;

	while (whoPlaysFirst != "Human" && whoPlaysFirst != "AI") {
		std::cout << "Write Human or AI\n";
		std::cin >> whoPlaysFirst;
	}
	bool firstHuman;
	if (whoPlaysFirst == "Human")
		firstHuman = true;
	else
		firstHuman = false;

	Board b('*',3);
	Human human(firstHuman, 'X');
	AI ai(!firstHuman, 'O',human.getMark());
	Algorithm algorithm(b, human, ai);
	algorithm.play();

	return 0;
}