#pragma once
#include <cstdint>

/*Original Author: Lykos
  Accessed: 16/10/19
  Online: https://stackoverflow.com/questions/664014/what-integer-hash-function-are-good-that-accepts-an-integer-hash-key/57556517#57556517
  */

class HashUtil
{
public:
	HashUtil();
	~HashUtil();


	 static uint64_t xorshift(const uint64_t& n, int i) {
		return n ^ (n >> i);
	}
	static uint64_t hash(const uint64_t& n) {
		uint64_t p = 0x5555555555555555; // pattern of alternating 0 and 1
		uint64_t c = 17316035218449499591ull;// random uneven integer constant; 
		return c * xorshift(p * xorshift(n, 32), 32);
	}
	static uint64_t arrayHash(int* arrayPointer, int arraySize) {
		uint64_t hashvalue = 0;
		for (int i = 0; i < arraySize; i++) {
			hashvalue += hash(arrayPointer[i] + hash(i));
		}
		return hashvalue;
	}
};


HashUtil::HashUtil()
{
}

HashUtil::~HashUtil()
{
}