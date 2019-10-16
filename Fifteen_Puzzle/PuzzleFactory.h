#pragma once
#include "Puzzle.h"
#include <string>

class PuzzleFactory {
public:

	static Puzzle createRandomPuzzle(int dimension, int maxinput);
	static std::vector<Puzzle> createRandomPuzzle(int numberofPuzzles);
	static Puzzle createManualPuzzle(int dimension, int maxInput);
	static std::vector<Puzzle> ReadConfigurationsFromFile(std::string filename);

private:
	static int getInputedNumber(const Puzzle& puzzle);
	static void generatePuzzle(std::vector<int> numbers, Puzzle& puzzle);
};