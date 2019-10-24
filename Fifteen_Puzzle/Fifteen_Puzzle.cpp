// Fifteen_Puzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PuzzleFactory.h"
#include "PuzzleSolver.h"
#include "OutputHandler.h"
#include <fstream>

int main()
{
	//Puzzle p(PuzzleFactory::createManualPuzzle(4,20));
	//OutputHandler::printConfigurationToFile(p);
	Puzzle d(PuzzleFactory::ReadConfigurationsFromFile("Configuration-File.txt"));
	std::cout << d;
	OutputHandler::printSolutionPuzzleToFile(d);
	

	
	
}

