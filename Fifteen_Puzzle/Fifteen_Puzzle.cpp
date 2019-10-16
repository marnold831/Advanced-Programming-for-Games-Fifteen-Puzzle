// Fifteen_Puzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PuzzleFactory.h"
#include <fstream>

int main()
{
	Puzzle p(PuzzleFactory::createRandomPuzzle(4, 20));
	//Puzzle p = PuzzleFactory::createRandomPuzzle(4, 20);
	//std::cout << p;
	//Puzzle d = PuzzleFactory::createManualPuzzle(4, 20);
	//std::cout << d;

	
	std::vector<Puzzle> puzzles = PuzzleFactory::createRandomPuzzle(12, 4, 20);

	for (auto it : puzzles) {
		std::cout << it;
		std::cout << "" << std::endl;
	}
	
}

