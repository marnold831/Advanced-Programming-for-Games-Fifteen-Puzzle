#pragma once


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include "MathUtil.h"


enum class direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Puzzle {
public:
	
	Puzzle()noexcept;
	Puzzle(int dimension)noexcept;
	Puzzle(const Puzzle& puzzle)noexcept;
	Puzzle(const Puzzle&& puzzle) noexcept;
	~Puzzle();

	Puzzle& operator=(const Puzzle& puzzle)noexcept;
	Puzzle& operator=(const Puzzle&& puzzle) noexcept;

	void swap(int swapPos); // Checks valid move
	bool move(direction dir);
	bool puzzleAfterMove(direction dir, Puzzle& puzzle) const;
	int calculateContinousRows(int partialSize) const;

	int getStartPos() const;
	int getDimension() const { return dimension; }
	uint64_t getHash() const;
	int getZeroPos() const { return zeroPos; }

	friend std::ostream& operator<< (std::ostream& os, const Puzzle& puzzle);

private:

	unsigned int indexGrid(int x, int y)const ;
	
	typedef int* iterator;
	iterator begin() const  { return grid; }
	iterator end()const  { return grid + totalNumbers; }

	int* grid;
	int dimension;
	int totalNumbers;
	int zeroPos;

	friend class PuzzleFactory;
};
