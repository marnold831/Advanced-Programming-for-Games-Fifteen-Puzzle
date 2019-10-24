/* Author: Michael Arnold
   Last Edited: 24/10/19
   Description: Class dedicated to creating puzzles in various means or reading from file
*/
#include "PuzzleFactory.h"
#include <random>
#include <chrono>
#include <string>
#include <fstream>
#include <sstream>


typedef std::chrono::high_resolution_clock myclock;

Puzzle PuzzleFactory::createRandomPuzzle(int dimension, int maxInput)
{
	int minNumbersRequired = dimension * dimension - 1;
	int correctMaxInput = 0;

	std::vector<int> possibleNumbers(generatePossibleNumbers(maxInput, minNumbersRequired));
	

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
	int updatedMax = maxInput;
	int index = 0;
	while (true) {
		if (maxInput < (dimension * dimension))
			updatedMax = dimension * dimension;

		int validInput = getInputedNumber(temp, updatedMax);
		temp.grid[index] = validInput;

		index++;
		if (index >= temp.totalNumbers-1) {
			break;
		}

	}
	return temp;
}

bool PuzzleFactory::ReadConfigurationsFromFile(const std::string& filename, std::vector<Puzzle>& puzzles)
{

	std::vector<std::vector<int>> configurations;

	try {

		std::ifstream myfile(filename);

		if (!myfile.is_open())
			throw std::runtime_error("Could not open file!");

		int numConfigurations = 0;
		int counter = 0;
		const char endLine = '\n';
		const char endValue = ' ';
		std::vector<int> currentConfigurations;
		std::string inputHolder;

		std::getline(myfile, inputHolder, endLine);

		if (std::stringstream(inputHolder) >> numConfigurations) {

			std::string rowHolder;

			while (std::getline(myfile, rowHolder, endLine) || counter < numConfigurations) {

				if (rowHolder != "") {

					std::string currentValue;
					int value;
					std::stringstream ss(rowHolder);

					while (std::getline(ss, currentValue, endValue)) {

						if (std::stringstream(currentValue) >> value)
							currentConfigurations.push_back(value);
					}
				}
				else {
					configurations.push_back(currentConfigurations);
					currentConfigurations.clear();
					counter++;
				}
			}
		}

	}
	catch (const std::runtime_error& error) {
		std::cout << error.what();
		configurations.clear();
		return false;
	}

	for (auto it : configurations) {
		int dim = static_cast<int>(std::sqrt(it.size() + 1));
		Puzzle p(dim);
		generatePuzzle(it, p);
		puzzles.push_back(p);
	}
	return true;

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
	if (numbers.back() != 0) 
		puzzle.grid[numbers.size()] = 0;
	
}

std::vector<int> PuzzleFactory::generatePossibleNumbers(const int maxInput, const int minNumbersRequired)
{
	int correctMaxInput = 0;
	if (maxInput < minNumbersRequired)
		correctMaxInput = minNumbersRequired;
	else
		correctMaxInput = maxInput;

	std::vector<int> possibleNumbers(correctMaxInput);
	for (int i = 0; i < possibleNumbers.size(); i++) {
		possibleNumbers[i] = i + 1;
	}
	return possibleNumbers;
}


