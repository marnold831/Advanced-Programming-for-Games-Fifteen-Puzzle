/* Author: Michael Arnold
   Last Edited: 24/10/19
   Description: Class to store puzzle member fields and the relative functions to act on those fields
*/
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
	this->grid = new int[dimension * dimension];
	this->totalNumbers = puzzle.totalNumbers;
	this->zeroPos = puzzle.zeroPos;
	std::copy(puzzle.grid, puzzle.grid + puzzle.totalNumbers + 1, this->grid);

	return *this;
}

Puzzle& Puzzle::operator=(const Puzzle&& puzzle) noexcept
{
	return *this;
}


unsigned long long Puzzle::calculateSolution(int partialSize) const
{


	if (partialSize > dimension)
		return 0;

	unsigned long long numberOfSolutions = 0;
	std::vector<int> puzzleNumbers;

	for (int i = 0; i < totalNumbers-1; i++) {
		puzzleNumbers.push_back(grid[i]);
	}

	std::sort(puzzleNumbers.begin(), puzzleNumbers.end());


	for (int i = 0; i < (totalNumbers -1) - (partialSize-1); i++) {

		

		if (puzzleNumbers.at(i) + (partialSize-1) == puzzleNumbers.at(i + (partialSize - 1))) {

			int numberOfPotentailRows = ((dimension - partialSize) + 1) * (dimension - 1) + (dimension - partialSize);

			numberOfSolutions += numberOfPotentailRows * MathUtil::factorial(((totalNumbers-1) - partialSize))/2; 
		}

	}

	
	
	return numberOfSolutions;
}

unsigned long long Puzzle::startingStateSolution(int partialSize) const
{
	unsigned long long totalSolutions = 0;
	totalSolutions += SolveAtStartRow(partialSize);	
	totalSolutions += SolveAtStartColumns(partialSize);
	
	return totalSolutions;
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

unsigned long long Puzzle::SolveAtStartColumns(int partialSize) const
{
	unsigned long long numberOfSolutions = 0;
	for (int i = 0; i < dimension; i++) { //looping coloumns
		for (int j = 0; j <= dimension - partialSize; j++) { //looping Rows
			int posA = j * dimension + i;
			bool continuousCol = true;
			bool continuousReverse = true;
			for (int k = 1; k < partialSize; k++) {

				if (grid[posA] + k != grid[posA + (dimension * (k))])
					continuousCol = false;
				if(grid[posA] != grid[posA + (dimension * (k))] + k)
					continuousReverse = false;
			
			}
			if (continuousCol)
				numberOfSolutions++;
			if (continuousReverse)
				numberOfSolutions++;

		}

	}

	return numberOfSolutions;
}



unsigned long long Puzzle::SolveAtStartRow(int partialSize) const
{
	unsigned long long numberOfSolutions = 0;

	for (int j = 0; j < dimension; j++) {

		for (int i = 0; i <= dimension - partialSize; i++) {
			int posA = j * dimension + i;
			bool continuousRow = true;
			bool continuousReverse = true;
			for (int k = 1; k < partialSize; k++) {

				if (grid[posA] + k != grid[posA + k])
					continuousRow = false;

				if (grid[posA] != grid[posA + k] + k)
					continuousReverse = false;
			}
			if (continuousRow)
				numberOfSolutions++;
			if (continuousReverse)
				numberOfSolutions++;
		}
	}
	
	return numberOfSolutions;
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