#include "PuzzleFactory.h"

Puzzle PuzzleFactory::createManualPuzzle(int dimension, int maxInput)
{

	Puzzle temp(dimension, maxInput);
	int index = 0;
	while (true) {

		int validInput = getInputedNumber(temp);
		temp.grid[index] = validInput;

		index++;
		if (index >= temp.totalNumbers) {
			break;
		}

	}
	return temp;
}

int PuzzleFactory::getInputedNumber(const Puzzle& puzzle)
{
	while (true) {
		int currentInput = 0;

		std::cout << "Enter a number between 1 and " << puzzle.maxInput << " that has not been entered previously" << std::endl;
		std::cin >> currentInput;

		if (currentInput < puzzle.minInput || currentInput > puzzle.maxInput) {
			std::cout << "Number is out of range of 1 to " << puzzle.maxInput << std::endl;
			continue;
		}

		bool foundMatched = false;

		if (std::none_of(puzzle.begin(), puzzle.end(), [currentInput](int i) { return i == currentInput; })) {
			return currentInput;
		}

		std::cout << "Number has been entered previously" << std::endl;
	}

}
