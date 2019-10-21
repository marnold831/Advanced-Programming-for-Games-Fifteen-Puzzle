// Fifteen_Puzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PuzzleFactory.h"
#include "PuzzleSolver.h"
#include <fstream>

int main()
{
	Puzzle p(PuzzleFactory::createRandomPuzzle(2, 5));
	
	std::cout << "Starting Puzzle \n" << p << "--------"<< std::endl;;
	
	std::vector<uint64_t> hashes;
	std::vector<Puzzle> allStates;

	PuzzleSolver::controller(p, hashes, allStates);
	std::vector<Puzzle> validTurns(PuzzleSolver::GetValidTurns(allStates));

	for (auto it : validTurns) {
		std::cout << it << std::endl;
	}

	std::cout << PuzzleSolver::FindContinousRows(validTurns);

	
	

	
	
}

