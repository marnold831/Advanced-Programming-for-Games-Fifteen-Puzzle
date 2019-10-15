#include "Puzzle.h"
#include <vector>
#include <iomanip>


Puzzle::Puzzle(int dimension, int maxInput): dimension(dimension), totalNumbers(dimension*dimension-1), maxInput(maxInput){
	grid = new int[dimension * dimension]{0};
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

			for (int i = 0; i < totalNumbers; i++) {
				if (currentInput != grid[i])continue;

				std::cout << "Number has been entered previously" << std::endl;
				foundMatched = true;
				break;
			}

			if (!foundMatched)
				return currentInput;
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