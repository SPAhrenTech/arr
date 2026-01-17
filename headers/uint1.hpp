//unsigned int arrays (n) - P. Ahrenkiel

#ifndef _UINT1_
#define _UINT1_

#include <iostream>

#include "arr1.hpp"

namespace arr {

class dbl1;

typedef unsigned int uint;
typedef arr1<uint> uint_arr1;

class uint1 : public uint_arr1 {
private:

public:
	uint1(const std::size_t n = 0, const uint *a = NULL) : uint_arr1(n, a) {}
	uint1(const uint_arr1 &A);
	uint1(const dbl1 &A);
	uint1 operator=(const uint &x);
};

}

#endif
