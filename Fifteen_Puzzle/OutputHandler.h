/* Author: Michael Arnold
   Last Edited: 24/10/19
   Description: Class for printing to various outputs
*/
#pragma once
#include "Puzzle.h"


class OutputHandler {

public:
	static void printSolutionPuzzleToFile(std::vector<Puzzle> puzzle, std::string filename);
	static void printSolutionPuzzleToFile(Puzzle puzzle, std::string filename);
	static void printConfigurationToFile(Puzzle puzzle, std::string filename);
	static void printConfigurationToFile(std::vector<Puzzle> puzzles, std::string filename);

	static void printSolutionToScreen(Puzzle puzzle);
	static void printSolutionToScreen(std::vector<Puzzle> puzzles);
	static void partialToFile(std::vector<Puzzle> puzzles, std::string filename, int partial);

private:
	static void outPut(Puzzle puzzle, std::ostream& myFile);

};