// Fifteen_Puzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Puzzle.h"
#include <fstream>

int main()
{
	Puzzle p(4,30);
	p.ManualCreation();
	std::cout << p << std::endl;
	std::ofstream myfile("Configurations.txt");
	if (myfile.is_open()) {
		myfile << p;
		myfile.flush();
		myfile.close();
	}

	
}

