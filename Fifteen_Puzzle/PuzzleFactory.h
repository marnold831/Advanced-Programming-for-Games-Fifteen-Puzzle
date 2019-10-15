#pragma once
#include "Puzzle.h"
#include <string>

class PuzzleFactory {
public:

	static Puzzle createRandomPuzzle();
	static std::vector<Puzzle> createRandomPuzzle(int numberofPuzzles);
	static Puzzle createManualPuzzle(int dimension, int maxInput);
	static std::vector<Puzzle> ReadConfigurationsFromFile(std::string filename);

private:
	static int getInputedNumber(const Puzzle& puzzle);
};