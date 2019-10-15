#pragma once
#include <iostream>
#include <vector>

class Puzzle {
public:

	Puzzle(int dimension, int maxInput);
	void ManualCreation();
	friend std::ostream& operator<< (std::ostream& os, const Puzzle& puzzle);


private:
	int* grid;
	unsigned int dimension;
	int totalNumbers;
	int minInput = 1;
	int maxInput;

	unsigned int indexGrid(int x, int y)const ;
	int getInputedNumber();

	typedef int* iterator;
	iterator begin() { return grid; }
	iterator end() { return grid + totalNumbers; }

};