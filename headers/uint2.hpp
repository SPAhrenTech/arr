//usigned int arrays (m x n) - P. Ahrenkiel

#ifndef _UINT2_
#define _UINT2_

#include <iostream>
#include "arr2.hpp"

namespace arr {
typedef arr2<std::size_t> uint_arr2;

class dbl2;

class uint2 : public uint_arr2 {
private:

public:
	uint2(const std::size_t N0 = 0, const std::size_t N1 = 0, const std::size_t *ap = NULL):
		uint_arr2(N0,N1,ap) {}

	uint2(const uint_arr2 &A);

	uint2 minor(const std::size_t iRow, const std::size_t iCol) const;

	dbl2 operator+() const;

	dbl2 operator-() const;

	dbl2 operator+(const dbl2 &A) const;

	dbl2 operator-(const dbl2 &A) const;

	uint2 operator=(const std::size_t &x) { return uint_arr2::operator=(x); }

	static uint2 zero(const size_t nRows, const size_t nCols);

	static uint2 ident(const size_t nRows, const size_t nCols);

	uint2 zero() { return *this = uint2::zero(size(0), size(1)); }

	uint2 ident() { return *this = uint2::ident(size(0), size(1)); }
};
}

#endif
