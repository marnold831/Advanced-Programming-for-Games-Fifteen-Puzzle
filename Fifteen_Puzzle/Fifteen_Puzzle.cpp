// Fifteen_Puzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PuzzleFactory.h"
#include <fstream>

int main()
{

	Puzzle p = PuzzleFactory::createManualPuzzle(4, 30);
	/*Puzzle p(4,30);

	p.ManualCreation();*/
	Puzzle d(p);
	std::cout << d << std::endl;
	std::ofstream myfile("Configurations.txt");
	if (myfile.is_open()) {
		myfile << p;
		myfile.flush();
		myfile.close();
	}

	
}

