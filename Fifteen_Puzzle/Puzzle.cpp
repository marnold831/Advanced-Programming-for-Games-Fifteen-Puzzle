#include "Puzzle.h"
#include <numeric>
#include <algorithm>
#include <iomanip>

Puzzle::Puzzle() noexcept : grid(nullptr), dimension(0), totalNumbers(0), zeroPos(0)
{

}

Puzzle::Puzzle(int dimension) noexcept  : dimension(dimension), totalNumbers(dimension*dimension), zeroPos(dimension*dimension-1)  {
	grid = new int[dimension * dimension]{0};
	
}

Puzzle::Puzzle(const Puzzle& puzzle) noexcept {
	*this = puzzle;
}

Puzzle::Puzzle(const Puzzle&& puzzle) noexcept
{
	*this = puzzle;
}

Puzzle::~Puzzle() {
	delete[] grid;
}

Puzzle& Puzzle::operator=(const Puzzle& puzzle) noexcept {
	this->dimension = puzzle.dimension;
	this->grid = new int[this->dimension * this->dimension];
	this->totalNumbers = puzzle.totalNumbers;
	this->zeroPos = puzzle.zeroPos;
	std::copy(puzzle.grid, puzzle.grid + puzzle.totalNumbers + 1, this->grid);

	return *this;
}

Puzzle& Puzzle::operator=(const Puzzle&& puzzle) noexcept
{
	return *this;
}


void Puzzle::swap(int swapPos)
{

	if ((swapPos > dimension * dimension) || (swapPos < 0)) {
		std::cerr << "Error! Tried to swap out of range" << std::endl;
		return;
	}

	int temp = grid[swapPos];
	grid[swapPos] = grid[zeroPos];
	grid[zeroPos] = temp;
	zeroPos = swapPos;

}

bool Puzzle::move(direction dir)
{
	switch (dir)
	{
	case direction::UP:
		if ((zeroPos - (int)dimension) < 0)
			return false;
		swap(zeroPos - dimension);
		return true;
	case direction::DOWN:
		if (zeroPos + dimension >= totalNumbers)
			return false;
		swap(zeroPos + dimension);
		return true;
	case direction::LEFT:
		if (zeroPos % dimension == 0)
			return false;
		swap(zeroPos -1);
		return true;
	case direction::RIGHT:
		if ((zeroPos + 1) % dimension == 0)
			return false;
		swap(zeroPos + 1);
		return true;
	default:
		return false;
	}
}

bool Puzzle::puzzleAfterMove(direction dir, Puzzle& puzzle) const
{
	puzzle = *this;
	return puzzle.move(dir);
}

int Puzzle::calculateContinousRows(int partialSize) const
{
	// Optimisation:
	// Loop over all rows
	// For each  Row
	// Loop from start of row to start of row + dimension
	// Each row, check current greater than previous

	if (partialSize > dimension)
		return;

	int numberOfSolutions = 0;
	std::vector<int> puzzleNumbers;

	for (int i = 0; i < totalNumbers-1; i++) {
		puzzleNumbers.push_back(grid[i]);
	}

	std::sort(puzzleNumbers.begin(), puzzleNumbers.end());
	std::vector<int> potentialPattern(dimension);

	for (int i = 0; i < totalNumbers - (dimension-1); i++) {

		std::copy(puzzleNumbers.begin()+ i, puzzleNumbers.end() +i + dimension, potentialPattern.begin());

		if (potentialPattern.at(0) + (dimension-1) == potentialPattern.at(dimension - 1)) {

			int numberOfPotentailRows = ((dimension - partialSize) + 1) * (dimension - 1) + (dimension - partialSize);

			numberOfSolutions += numberOfPotentailRows * MathUtil::factorial((totalNumbers - dimension) / 2); // TODO check the factorial apsect for when calculating partial rows
		}

	}

	/*int patternMatches = 0;
	std::vector<int> row;
	for (int i = 0; i < dimension; i++) {
		row.resize(dimension);
		for (int j = 0; j < dimension; j++) {
			row[j] = grid[(dimension * i) + j];
		}
		std::vector<int> pattern(dimension);
		if (ascending)
			std::generate(pattern.begin(), pattern.end(), [n = row[0]]() mutable {return n++; });
		else
			std::generate(pattern.begin(), pattern.end(), [n = row[0]]() mutable {return n--; });

		if (std::equal(row.begin(), row.end(), pattern.begin()))
			patternMatches++;
		row.clear();
	}*/


	
	
	return numberOfSolutions;
}


int Puzzle::getStartPos() const
{
	return indexGrid(dimension - 1, dimension - 1);
}


uint64_t Puzzle::getHash() const
{
	return MathUtil::arrayHash(grid, totalNumbers);
}


unsigned int Puzzle::indexGrid(int x, int y) const  {
	return x + dimension * y;
}

std::ostream& operator<< (std::ostream& os, const Puzzle& puzzle) {
	for (int y = 0; y < puzzle.dimension; y++) {
		for (int x = 0; x < puzzle.dimension; x++) {
			os << std::left;
			os << std::setw(5);
			
			os << puzzle.grid[puzzle.indexGrid(x, y)];
		}
		os << std::endl;
	
	}
	return os;
}