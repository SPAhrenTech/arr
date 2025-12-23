//bool array slices (n) - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "arr.hpp"

namespace arr {

//
bool1::bool1(const bool2slice &A) : bool_arr1(A) {}
bool2::bool2(const bool2slice &A) : bool_arr2(A) {}

//
bool2slice bool2::slice(const std::size_t iDim, const std::size_t iIndex) { return bool2slice(this, iDim, iIndex); }
bool2slice bool2::row(const std::size_t iIndex) { return bool2slice(this, 0, iIndex); }
bool2slice bool2::col(const std::size_t iIndex) { return bool2slice(this, 1, iIndex); }

//
bool2 bool2slice::operator|(const bool2slice &A) const {
	return bool2(*this) | bool2(A);
}

//
bool2 bool2slice::operator&(const bool2slice &A) const {
	return bool2(*this) & bool2(A);
}

//
void bool2slice::operator|=(const bool2 &A) {
	switch (dim()) {
		case 0:
			for (std::size_t i = 0; i < size(); i++)
				data()->at(index(), i) |= A(0, i);
			break;
			
		case 1:
			for (std::size_t i = 0; i < size(); i++)
				data()->at(i, index()) |= A(i, 0);
	}
}

//
void bool2slice::operator&=(const bool2 &A) {
	switch (dim()) {
		case 0:
			for (std::size_t i = 0; i < size(); i++)
				data()->at(index(), i) &= A(0, i);
			break;
			
		case 1:
			for (std::size_t i = 0; i < size(); i++)
				data()->at(i, index()) &= A(i, 0);
	}
}

//
void bool2slice::operator=(const bool x) {
	switch (dim()) {
		case 0:
			for (std::size_t i = 0; i < size(); i++)
				data()->at(index(), i) = x;
			break;
			
		case 1:
			for (std::size_t i = 0; i < size(); i++)
				data()->at(i, index()) = x;
	}
	//return *source();
}

}
