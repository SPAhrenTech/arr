//bool arrays (m x n) - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "bool3.hpp"

namespace arr {

bool3::bool3(const std::size_t N0, const std::size_t N1, const std::size_t N2, const bool *b):
	bool_arr3(N0, N1, N2, reinterpret_cast<const bool_type*>(b))
{}

bool3::bool3(const bool_arr3 &A):
	bool_arr3(A.size(0), A.size(1), A.size(2), A.data())
{}
		
bool3 bool3::operator=(const bool &x)
{
	return bool_arr3::operator=(x);
}

//static
bool3 bool3::zero(const std::size_t n0, const std::size_t n1, const std::size_t n2) {
		bool3 res(n0, n1, n2);
		res = false;
		return res;
}

//static
bool3 bool3::ident(const std::size_t n0, const std::size_t n1, const std::size_t n2) {
		bool3 A(n0, n1, n2);
		for (size_t i = 0; i < n0; ++i)
				for (size_t j = 0; j < n1; ++j)
						for (size_t k = 0; k < n2; ++k)
								A(i, j, k) = ((i == j) && (i == k)) ? true : false;
		return A;
}

//
bool bool3::hasTrue() const {
		for (size_t i = 0; i < _n0; ++i)
				for (size_t j = 0; j < _n1; ++j)
						for (size_t k = 0; k < _n2; ++k)
								if (at(i, j, k))return true;
		return false;
}

//
bool bool3::hasFalse() const {
		for (size_t i = 0; i < _n0; ++i)
				for (size_t j = 0; j < _n1; ++j)
						for (size_t k = 0; k < _n2; ++k)
								if (!at(i, j, k))return true;
		return false;
}

}
