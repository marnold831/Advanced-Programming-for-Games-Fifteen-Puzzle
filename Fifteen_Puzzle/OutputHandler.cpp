#include "OutputHandler.h"
#include <iostream>
#include <fstream>
#include <exception>

void OutputHandler::printSolutionPuzzleToFile(Puzzle puzzle)
{
	int numberOfPuzzles = 1;
	std::ofstream myFile("Solution-File.txt");
	if (!myFile.is_open())
		throw std::runtime_error("Could not open file!");
	myFile << numberOfPuzzles << "\n";
	myFile << puzzle;
	int numberOfRows = puzzle.calculateContinousRows(puzzle.getDimension());
	myFile << "row = " << numberOfRows << std::endl;
	myFile << "column = " << numberOfRows << std::endl;
	myFile << "reverse row = " << numberOfRows << std::endl;
	myFile << "row column = " << numberOfRows << std::endl;

}

void OutputHandler::printConfigurationToFile(Puzzle puzzle)
{
	int numberOfPuzzles = 1;
	std::ofstream myFile("Configuration-File.txt");
	if (!myFile.is_open())
		throw std::runtime_error("Could not open file!");
	myFile << numberOfPuzzles << "\n";
	myFile << puzzle;
}
