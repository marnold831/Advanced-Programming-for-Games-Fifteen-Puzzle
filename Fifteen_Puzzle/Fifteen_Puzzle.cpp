// Fifteen_Puzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PuzzleFactory.h"
#include <fstream>

int main()
{
	Puzzle p(PuzzleFactory::createRandomPuzzle(4, 20));

	//std::cout << p << std::endl;

	//
	std::ofstream myfile("Configurations.txt");
	if (myfile.is_open()) {
		myfile << p;
	}
	std::cout << p << std::endl;


	////

	//std::string s = "configurations.txt";
	Puzzle d = PuzzleFactory::ReadConfigurationsFromFile("configurationkls.txt");
	//Puzzle d();
	//std::cout << d;
	
	

	
	
}

