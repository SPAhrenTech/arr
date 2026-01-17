//bool array slices (n) - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "bool2.hpp"
#include "bool2slice.hpp"

namespace arr {

bool2slice::bool2slice(bool2 *A, const std::size_t iDim, const std::size_t iIndex):
	bool_arr2slice(A, iDim, iIndex)
{}

bool2slice::bool2slice(const bool_arr2slice &A):
	bool_arr2slice(A)
{}

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
}

}
