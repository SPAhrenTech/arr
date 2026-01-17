//bool arrays (m x n) - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "bool2.hpp"
#include "bool2slice.hpp"

namespace arr {

bool2::bool2(const std::size_t N0,const std::size_t N1,const bool *b):
	bool_arr2(N0, N1, reinterpret_cast<const bool_type*>(b)){}

	
bool2::bool2(const bool_arr2 &A):bool_arr2(A.size(0), A.size(1), A.data()){}

bool2::bool2(const bool2slice &A):bool_arr2(A){}

//static
bool2 bool2::zero(const std::size_t m, const std::size_t n)
{
	bool2 res(m, n);
	res = false;
	return res;
}

//static
bool2 bool2::ident(const std::size_t m, const std::size_t n) {
	bool2 A(m, n);
	for (size_t i = 0; i < m; i++)
		for (size_t j = 0; j < n; j++)
			A(i, j) = (i == j) ? true : false;
	return A;
}

bool2 bool2::operator=(const bool &x)
{
	return bool_arr2::operator=(x);
}

bool2 bool2::operator|(const bool2 &b) const {
	size_t nRows = std::min(_nRows, b.size(0));
	size_t nCols = std::min(_nCols, b.size(1));
	bool2 res = (_nRows < b.size(0)) ? b : *this;
	for (size_t i = 0; i < nRows; i++)
		for (size_t j = 0; j < nCols; j++)
			res(i, j) = at(i, j) || b(i, j);
	return res;
}

//
bool2 bool2::operator&(const bool2 &b) const {
	size_t nRows = std::min(_nRows, b.size(0));
	size_t nCols = std::min(_nCols, b.size(1));
	bool2 res = (_nRows > b.size(0)) ? b : *this;
	for (size_t i = 0; i < nRows; i++)
		for (size_t j = 0; j < nCols; j++)
			res(i) = at(i, j) && b(i, j);
	return res;
}

//
bool2 &bool2::operator|=(const bool2 &b) {
	return *this = (*this) | b;
}

//
bool2 &bool2::operator&=(const bool2 &b) {
	return *this = (*this) & b;
}

//
bool bool2::hasTrue() const {
	for (size_t i = 0; i < _nRows; i++)
		for (size_t j = 0; j < _nCols; j++)
			if (at(i, j))return true;
	return false;
}

//
bool bool2::hasFalse() const {
	for (size_t i = 0; i < _nRows; i++)
		for (size_t j = 0; j < _nCols; j++)
			if (!at(i, j))return true;
	return false;
}

//friend
std::ostream &operator<<(std::ostream &os, const bool2 &A) {
	std::cout << "(";
	for (size_t i = 0; i < A._nRows; i++)
		for (size_t j = 0; j < A._nCols; j++) {
			if (i > 0)std::cout << "\t";
			if (A(i, j))std::cout << "T";
			else std::cout << "F";
		}
	std::cout << ")";
	return os;
}

bool2slice bool2::slice(const std::size_t iDim, const std::size_t iIndex)
{
	return bool2slice(this, iDim, iIndex);
}

bool2slice bool2::row(const std::size_t iIndex)
{
	return bool2slice(this, 0, iIndex);
}

bool2slice bool2::col(const std::size_t iIndex)
{
	return bool2slice(this, 1, iIndex);
}


}
