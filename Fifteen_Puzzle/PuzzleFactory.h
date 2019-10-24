/* Author: Michael Arnold
   Last Edited: 24/10/19
   Description: Class dedicated to creating puzzles in various means or reading from file
*/
#pragma once



#include "Puzzle.h"
#include <string>


class PuzzleFactory {
public:

	static Puzzle createRandomPuzzle(int dimension, int maxinput);
	static std::vector<Puzzle> createRandomPuzzle(int numberofPuzzles, int dimension, int maxInput);
	static Puzzle createManualPuzzle(int dimension, int maxInput);
	static bool ReadConfigurationsFromFile(const std::string& filename, std::vector<Puzzle>& puzzles);

private:
	static int getInputedNumber(const Puzzle& puzzle, int maxInput);
	static void generatePuzzle(const std::vector<int>& numbers, Puzzle& puzzle);

	static std::vector<int> generatePossibleNumbers(const int maxInput, const int minNumbersRequired );
	

};

