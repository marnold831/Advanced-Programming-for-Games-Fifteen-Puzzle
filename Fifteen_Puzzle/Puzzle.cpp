#include "Puzzle.h"
#include <iomanip>

Puzzle::Puzzle(int dimension): dimension(dimension), totalNumbers(dimension*dimension-1){
	grid = new int[dimension * dimension]{0};
	
}

Puzzle::~Puzzle() {
	delete[] grid;
}

Puzzle& Puzzle::operator=(const Puzzle& puzzle){
	this->dimension = puzzle.dimension;
	this->grid = new int[this->dimension * this->dimension];
	this->totalNumbers = puzzle.totalNumbers;
	this->hash = puzzle.hash;
	std::copy(puzzle.grid, puzzle.grid + puzzle.totalNumbers + 1, this->grid);

	return *this;
}

Puzzle& Puzzle::operator=(const Puzzle&& puzzle)
{
	return *this;
}

Puzzle::Puzzle(const Puzzle& puzzle) {
	*this = puzzle;
}

Puzzle::Puzzle(const Puzzle&& puzzle)
{
	*this = puzzle;
}


unsigned int Puzzle::indexGrid(int x, int y) const  {
	return x + dimension * y;
}

std::ostream& operator<< (std::ostream& os, const Puzzle& puzzle) {
	for (int y = 0; y < puzzle.dimension; y++) {
		for (int x = 0; x < puzzle.dimension; x++) {
			os << std::left << std::setw(5) << puzzle.grid[puzzle.indexGrid(x, y)];
		}
		os << std::endl;

	}
	return os;
}