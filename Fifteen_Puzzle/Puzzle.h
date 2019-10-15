#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Puzzle {
public:
	
	Puzzle(int dimension, int maxInput);
	~Puzzle();
	void ManualCreation();
	friend std::ostream& operator<< (std::ostream& os, const Puzzle& puzzle);
	Puzzle(const Puzzle& puzzle);

private:
	int* grid;

	unsigned int dimension;
	int totalNumbers;
	int minInput = 1;
	int maxInput;

	unsigned int indexGrid(int x, int y)const ;
	int getInputedNumber();

	typedef int* iterator;
	iterator begin() const  { return grid; }
	iterator end()const  { return grid + totalNumbers; }

	friend class PuzzleFactory;
};