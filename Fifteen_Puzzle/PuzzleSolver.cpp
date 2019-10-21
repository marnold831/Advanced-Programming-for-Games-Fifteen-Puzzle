#include "PuzzleSolver.h"



void PuzzleSolver::controller(const Puzzle& p, std::vector< uint64_t>& hashes, std::vector<Puzzle>& allStates)
{
	bool firstTry = hashes.size() == 0;

	uint64_t hash = p.getHash();
	bool alreadyVisited = std::find(hashes.begin(), hashes.end(), hash) != hashes.end();
	if (alreadyVisited)
	{
		return;
	}

	hashes.push_back(hash);
	allStates.push_back(p);

	//code breaks when trying second direction from strating state
	if (!firstTry && p.getZeroPos() == p.getDimension() * p.getDimension() - 1)
		return;

	Puzzle temp;

	if (p.puzzleAfterMove(direction::UP, temp))
	{
		controller(temp, hashes, allStates);
	}

	if (p.puzzleAfterMove(direction::DOWN, temp))
	{
		controller(temp, hashes, allStates);
	}

	if (p.puzzleAfterMove(direction::LEFT, temp))
	{
		controller(temp, hashes, allStates);
	}

	if (p.puzzleAfterMove(direction::RIGHT, temp))
	{
		controller(temp, hashes, allStates);
	}

	//controller(p.move(direction::UP), hashes, allStates);
	//controller(p, direction::DOWN, hashes, allStates);
	//controller(p, direction::LEFT, hashes, allStates);
	//controller(p, direction::RIGHT, hashes, allStates);
}

std::vector<Puzzle> PuzzleSolver::GetValidTurns(const std::vector<Puzzle>& allstates)
{
	std::vector<Puzzle> validTurns;
	for (auto it : allstates) {
		if (it.getZeroPos() == it.getStartPos())
			validTurns.push_back(it);
	}
	return validTurns;
}

int PuzzleSolver::FindContinousRows(const std::vector<Puzzle>& allStates)
{
	int numberOfContinousRows =0;
	for (auto it : allStates) {
		numberOfContinousRows += it.calculateContinousRows(true);
		numberOfContinousRows += it.calculateContinousRows(false);
	}

	return numberOfContinousRows;
}



bool PuzzleSolver::checkHashExists(uint64_t hash, const std::vector<uint64_t>& hashes)
{
	return std::find(hashes.begin(), hashes.end(), hash) != hashes.end();

}
