#pragma once



#include "Puzzle.h"
#include <string>


class PuzzleFactory {
public:

	static Puzzle createRandomPuzzle(int dimension, int maxinput);
	static std::vector<Puzzle> createRandomPuzzle(int numberofPuzzles, int dimension, int maxInput);
	static Puzzle createManualPuzzle(int dimension, int maxInput);
	static Puzzle ReadConfigurationsFromFile(const std::string& filename);

private:
	static int getInputedNumber(const Puzzle& puzzle, int maxInput);
	static void generatePuzzle(const std::vector<int>& numbers, Puzzle& puzzle);


};

