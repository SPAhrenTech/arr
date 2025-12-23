//bool suboolays (m x n) - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "arr.hpp"

namespace arr {

//
bool2::bool2(const bool2sub &A) : bool_arr2(A) {}

//
bool2sub
bool2::sub(const std::size_t iRow, const std::size_t iCol, const std::size_t nRows, const std::size_t nCols) {
		return bool_arr2::sub(iRow, iCol, nRows, nCols);
}

//
bool2sub bool2::operator()(const std::size_t iRow, const std::size_t iCol, const std::size_t nRows,
													 const std::size_t nCols) {
		return sub(iRow, iCol, nRows, nCols);
}

//
void bool2sub::operator=(const bool2 &A) {
		if ((size(0) != A.size(0)) || (size(1) != A.size(1)))return;
		for (std::size_t i = 0; i < size(0); i++)
				for (std::size_t j = 0; j < size(1); j++)
						at(i, j) = A(i, j);
}

//
void bool2sub::operator|=(const bool2 &A) {
		if ((size(0) != A.size(0)) || (size(1) != A.size(1)))return;
		for (std::size_t i = 0; i < size(0); i++)
				for (std::size_t j = 0; j < size(1); j++)
						at(i, j) |= A(i, j);
}

//
void bool2sub::operator&=(const bool2 &A) {
		if ((size(0) != A.size(0)) || (size(1) != A.size(1)))return;
		for (std::size_t i = 0; i < size(0); i++)
				for (std::size_t j = 0; j < size(1); j++)
						at(i, j) &= A(i, j);
}

//
void bool2sub::operator=(const bool &x) {
		for (std::size_t i = 0; i < size(0); i++)
				for (std::size_t j = 0; j < size(1); j++)
						at(i, j) = x;
}
}
