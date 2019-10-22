#include "PuzzleFactory.h"
#include <random>
#include <chrono>
#include <string>
#include <fstream>


typedef std::chrono::high_resolution_clock myclock;

Puzzle PuzzleFactory::createRandomPuzzle(int dimension, int maxInput)
{
	int minNumbersRequired = dimension * dimension - 1;
	int correctMaxInput = 0;

	if (maxInput < minNumbersRequired)
		correctMaxInput = minNumbersRequired;
	else
		correctMaxInput = maxInput;

	std::vector<int> possibleNumbers(correctMaxInput);
	for (int i = 0; i < possibleNumbers.size(); i++) {
		possibleNumbers[i] = i+1;
	}

	/* -Seed Example 
	   -http://www.cplusplus.com/reference/random/mersenne_twister_engine/seed/
	   -Accessed 16/10/19
	 */
	myclock::time_point now = myclock::now();
	myclock::duration d = myclock::now() - now;
	unsigned seed = (unsigned int)d.count();


	auto rng = std::mt19937{};
	rng.seed(seed);
	std::shuffle(std::begin(possibleNumbers), std::end(possibleNumbers), rng);

	possibleNumbers.resize(minNumbersRequired);

	Puzzle p(dimension);

	generatePuzzle(possibleNumbers, p);
	
	return p;
}

std::vector<Puzzle> PuzzleFactory::createRandomPuzzle(int numberofPuzzles, int dimension, int maxInput)
{
	std::vector<Puzzle> puzzles;
	puzzles.reserve(numberofPuzzles);
	
	int index = 0;
	while (index < numberofPuzzles) {
		bool check = false;

		Puzzle temp = createRandomPuzzle(dimension, maxInput);

		if (std::none_of(puzzles.begin(), puzzles.end(), [temp](const Puzzle& p) { return p.getHash() == temp.getHash(); })) {
			check = true;
		}
		if (check) {
			puzzles.push_back(temp);
			index++;
		}
	}
	return puzzles;
}

Puzzle PuzzleFactory::createManualPuzzle(int dimension, int maxInput)
{

	Puzzle temp(dimension);
	int index = 0;
	while (true) {

		int validInput = getInputedNumber(temp, maxInput);
		temp.grid[index] = validInput;

		index++;
		if (index >= temp.totalNumbers-1) {
			break;
		}

	}
	return temp;
}

Puzzle PuzzleFactory::ReadConfigurationsFromFile(const std::string& filename)
{
	std::ifstream myfile(filename);

	if (!myfile.is_open())
		throw std::exception("oops");

	std::vector<int> numbers;
	int temp = -1;
	while (!myfile.eof()) {
		myfile >> temp;
		if (temp == 0) {
			break;
		}
		numbers.push_back(temp);
	}
	
	int dim = static_cast<int>(std::sqrt(numbers.size() + 1));
    Puzzle p(dim);
	generatePuzzle(numbers, p);
	return p;
}

int PuzzleFactory::getInputedNumber(const Puzzle& puzzle, int maxInput)
{
	int minInput = 0;
	while (true) {
		int currentInput = 0;

		std::cout << "Enter a number between 1 and " <<maxInput << " that has not been entered previously" << std::endl;
		std::cin >> currentInput;

		if (currentInput < minInput || currentInput > maxInput) {
			std::cout << "Number is out of range of 1 to " << maxInput << std::endl;
			continue;
		}

		bool foundMatched = false;

		if (std::none_of(puzzle.begin(), puzzle.end(), [currentInput](int i) { return i == currentInput; })) {
			return currentInput;
		}

		std::cout << "Number has been entered previously" << std::endl;
	}

}

void PuzzleFactory::generatePuzzle(const std::vector<int>& numbers, Puzzle& puzzle)
{
	for (int i = 0; i < numbers.size(); i++) {
		puzzle.grid[i] = numbers[i];
	}
	puzzle.grid[numbers.size()] = 0;
}
