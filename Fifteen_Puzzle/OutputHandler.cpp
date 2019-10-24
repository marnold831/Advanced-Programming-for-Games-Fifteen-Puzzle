/* Author: Michael Arnold
   Last Edited: 24/10/19
   Description: Class for printing to various outputs
*/
#include "OutputHandler.h"
#include <iostream>
#include <fstream>
#include <exception>



void OutputHandler::printSolutionPuzzleToFile(std::vector<Puzzle> puzzle, std::string filename)
{
	std::ofstream myFile(filename, std::ofstream::trunc);
	if (!myFile.is_open())
		throw std::runtime_error("Could not open file!");

	myFile << puzzle.size();
	for (auto it : puzzle) {
		outPut(it, myFile);
	}
}

void OutputHandler::printSolutionPuzzleToFile(Puzzle puzzle, std::string filename)
{

	int numberOfPuzzles = 1;
	
	std::ofstream myFile(filename, std::ofstream::trunc);

	if (!myFile.is_open())
		throw std::runtime_error("Could not open file!");

	myFile << numberOfPuzzles << std::endl;
	outPut(puzzle, myFile);
}

void OutputHandler::printConfigurationToFile(Puzzle puzzle, std::string filename)
{
	int numberOfPuzzles = 1;
	std::ofstream myFile(filename);
	if (!myFile.is_open())
		throw std::runtime_error("Could not open file!");
	myFile << numberOfPuzzles << std::endl;
	
	outPut(puzzle, std::cout);
}

void OutputHandler::printConfigurationToFile(std::vector<Puzzle> puzzles, std::string filename)
{
	int numberOfPuzzles = puzzles.size();
	std::ofstream myFile(filename);
	if (!myFile.is_open())
		throw std::runtime_error("Could not open file!");
	myFile << numberOfPuzzles << std::endl;
	for (auto it : puzzles) {

		myFile << it;
		
	}
}

void OutputHandler::printSolutionToScreen(Puzzle puzzle)
{
	int numberOfPuzzles = 1;
	std::cout << numberOfPuzzles << std::endl;
	std::cout << puzzle;
	outPut(puzzle, std::cout);
}

void OutputHandler::printSolutionToScreen(std::vector<Puzzle> puzzles)
{
	int numberOfPuzzles = puzzles.size();
	std::cout << numberOfPuzzles << std::endl;
	for (auto it:puzzles) {
		
		outPut(it, std::cout);
	}
}

void OutputHandler::partialToFile(std::vector<Puzzle> puzzles, std::string filename, int partial)
{
	std::ofstream myFile(filename);
	if (!myFile.is_open())
		throw std::runtime_error("Could not open file!");
	for (auto it : puzzles) {
		myFile << it << std::endl;
		if (it.getDimension() < partial)
			myFile << "dimension to small for partial" << std::endl;
		else {
			myFile << "partial " << partial << ": " << it.calculateSolution(partial);
		}

	}
}


void OutputHandler::outPut(Puzzle puzzle, std::ostream& myFile)
{

	

	myFile << puzzle;
	unsigned long long numberOfRows = puzzle.calculateSolution(puzzle.getDimension());
	myFile << "row = " << numberOfRows << std::endl;
	myFile << "column = " << numberOfRows << std::endl;
	myFile << "reverse row = " << numberOfRows << std::endl;
	myFile << "row column = " << numberOfRows << std::endl;
	myFile << "(total for row and column, including reverse, in this configuration)" << std::endl;
	myFile << "2 = " << puzzle.startingStateSolution(2) << std::endl;
	if (puzzle.getDimension() < 3)
		myFile << "Puzzle to small for partial size" << std::endl;
	else {
		myFile << "3 = " << puzzle.startingStateSolution(3) << std::endl;
	}
	if (puzzle.getDimension() < 4)
		myFile << "Puzzle to small for partial size" << std::endl;
	else {
		myFile << "4 = " << puzzle.startingStateSolution(4) << std::endl;
	}
	
	myFile << "(total for row and column, including reverse, for all valid turns)" << std::endl;
	
	myFile << "2 = " <<  puzzle.calculateSolution(2) << std::endl;

	if (puzzle.getDimension() < 3)
		myFile << "Puzzle to small for partial size" << std::endl;
	else {
		myFile << "3 = " << puzzle.calculateSolution(3) << std::endl;
	}

	if (puzzle.getDimension() < 4)
		myFile << "Puzzle to small for partial size" << std::endl;
	else {
		myFile << "4 = " << puzzle.calculateSolution(4) << std::endl;
	}
	
	
	
	
}