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
			uint64_t thisIndexExponent = uint64_t(rint(pow(16, i)));
			hashvalue += arrayPointer[i] * thisIndexExponent;
		}
		return hashvalue;
	}

	static int factorial(int n) {
		int factorial = 1;
		for (int i = n; i >= 1; i--) {
			factorial *= i;
		}
		return factorial;
	}
};



#endif // !HASHUTIL_H




