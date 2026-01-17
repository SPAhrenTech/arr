//bool arrays (n) - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "bool1.hpp"
#include "bool2slice.hpp"

namespace arr {

bool1::bool1(const std::size_t N0, const bool *b):
	bool_arr1(N0, reinterpret_cast<const bool_type*>(b))
{}

bool1::bool1(const bool_arr1 &A) : bool_arr1(A()) {}
	
bool1::bool1(const bool2slice &A) : bool_arr1(A) {}

bool1 bool1::zero(const std::size_t n) {
		bool1 res(n);
		res = false;
		return res;
}

//
bool1 bool1::operator|(const bool1 &b) const {
		size_t n = std::min(size(), b.size());
		bool1 res = (size() < b.size()) ? b : *this;
		for (size_t i = 0; i < n; i++)
				res(i) = at(i) || b(i);
		return res;
}

//
bool1 bool1::operator&(const bool1 &b) const {
		size_t n = std::min(size(), b.size());
		bool1 res = (size() > b.size()) ? b : *this;
		for (size_t i = 0; i < n; i++)
				res(i) = at(i) && b(i);
		return res;
}

//
bool1 &bool1::operator|=(const bool1 &b) {
		return *this = (*this) | b;
}

//
bool1 &bool1::operator&=(const bool1 &b) {
		return *this = (*this) & b;
}

//
bool bool1::hasTrue() const {
		for (size_t i = 0; i < size(); i++)
				if (at(i))return true;
		return false;
}

//
bool bool1::hasFalse() const {
		for (size_t i = 0; i < size(); i++)
				if (!at(i))return true;
		return false;
}

//friend
std::ostream &operator<<(std::ostream &os, const bool1 &A) {
		std::cout << "(";
		for (size_t i = 0; i < A.size(); ++i) {
				if (i > 0)std::cout << "\t";
				if (A(i))std::cout << "T";
				else std::cout << "F";
		}
		std::cout << ")";
		return os;
}
}
