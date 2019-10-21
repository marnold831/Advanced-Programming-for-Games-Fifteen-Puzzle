#pragma once

#include "Puzzle.h"

class PuzzleSolver {
public:

	static void controller(const Puzzle& p, std::vector< uint64_t>& hashes, std::vector<Puzzle>& allStates);
	static std::vector<Puzzle> GetValidTurns(const std::vector<Puzzle>& allstates);
	static int FindContinousRows(const std::vector<Puzzle>& allStates);
private:
	
	static bool checkHashExists(uint64_t hash, const std::vector< uint64_t>& hashes);
};


