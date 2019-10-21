#pragma once
#ifndef MATHUTIL_H
#define MATHUTIL_H

#include <cstdint>

/*Original Author: Lykos
  Accessed: 16/10/19
  Online: https://stackoverflow.com/questions/664014/what-integer-hash-function-are-good-that-accepts-an-integer-hash-key/57556517#57556517
  */

class MathUtil
{
public:


	static uint64_t arrayHash(int* arrayPointer, int arraySize) {
		uint64_t hashvalue = 0;
		for (int i = 0; i < arraySize; i++) {
			hashvalue += arrayPointer[i] * pow(16, i);
		}
		return hashvalue;
	}

	static int factorial(int n) {
		int factorial = 0;
		for (int i = 0; i <= n; i++) {
			factorial *= i;
		}
		return factorial;
	}
};



#endif // !HASHUTIL_H




