#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

class Puzzle {
public:
	
	Puzzle(int dimension);
	~Puzzle();
	
	friend std::ostream& operator<< (std::ostream& os, const Puzzle& puzzle);
	Puzzle& operator=(const Puzzle& puzzle);
	Puzzle& operator=(const Puzzle&& puzzle);
	Puzzle(const Puzzle& puzzle);
	Puzzle(const Puzzle&& puzzle);

private:

	unsigned int indexGrid(int x, int y)const ;
	
	typedef int* iterator;
	iterator begin() const  { return grid; }
	iterator end()const  { return grid + totalNumbers; }

	int* grid;
	unsigned int dimension;
	int totalNumbers;
	uint64_t hash;

	friend class PuzzleFactory;
};