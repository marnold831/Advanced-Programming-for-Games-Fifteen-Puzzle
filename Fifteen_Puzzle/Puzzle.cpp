#include "Puzzle.h"
#include <iomanip>


Puzzle::Puzzle(int dimension, int maxInput): dimension(dimension), totalNumbers(dimension*dimension-1), maxInput(maxInput){
	grid = new int[dimension * dimension]{0};
	
}

Puzzle::~Puzzle() {
	delete[] grid;
}

Puzzle::Puzzle(const Puzzle& puzzle) {
	this->maxInput = puzzle.maxInput;
	this->minInput = puzzle.minInput;
	this->grid = new int[puzzle.totalNumbers];
	this->dimension = puzzle.dimension;
	this->totalNumbers = puzzle.totalNumbers;
	std::copy(puzzle.grid, puzzle.grid + puzzle.totalNumbers, this->grid);
}

void Puzzle::ManualCreation(){
	std::vector<int> enteredNumber = std::vector<int>(15);
	int index = 0;
	while (true) {
		
		int validInput = getInputedNumber();
		grid[index] = validInput;
		//enteredNumber.push_back(validInput);
		index++;
		if (index >= totalNumbers) {
			break;
		}
		
	}
}

int Puzzle::getInputedNumber() {
	while (true) {
		int currentInput = 0;

			std::cout << "Enter a number between 1 and " << maxInput << " that has not been entered previously" << std::endl;
			std::cin >> currentInput;

			if (currentInput < minInput || currentInput > maxInput) {
				std::cout << "Number is out of range of 1 to " << maxInput << std::endl;
				continue;
			}

			bool foundMatched = false;

			if (std::none_of(begin(), end(), [currentInput](int i) { return i == currentInput; })) {
				return currentInput;
			}

			std::cout << "Number has been entered previously" << std::endl;
		}

		
}

unsigned int Puzzle::indexGrid(int x, int y) const  {
	return x + dimension * y;
}

std::ostream& operator<< (std::ostream& os, const Puzzle& puzzle) {
	for (int y = 0; y < puzzle.dimension; y++) {
		for (int x = 0; x < puzzle.dimension; x++) {
			os << std::left << std::setw(5) << puzzle.grid[puzzle.indexGrid(x, y)];
		}
		os << std::endl;

	}
	return os;
}