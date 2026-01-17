//double array slices (n) - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "mth.hpp"
#include "trg.hpp"

#include "dbl1.hpp"
#include "dbl2.hpp"
#include "dbl2slice.hpp"

namespace arr {

dbl2slice::dbl2slice(dbl2 *A, const std::size_t iDim, const std::size_t iIndex):
	double_arr2slice(A, iDim, iIndex) {}

dbl2slice::dbl2slice(const double_arr2slice &A):double_arr2slice(A) {}


dbl2 dbl2slice::operator+() const { return *this; }

dbl2 dbl2slice::operator-() const { return -dbl2(*this); }

dbl2 dbl2slice::operator+(const dbl2slice &A) const {
	return dbl2(*this) + dbl2(A);
}

dbl2 dbl2slice::operator-(const dbl2slice &A) const {
	return dbl2(*this) - dbl2(A);
}

dbl2 dbl2slice::operator/(const double x) const {
	return dbl2(*this) / x;
}


//
void dbl2slice::operator=(const dbl2 &A) {
	switch (dim()) {
		case 0:
			for (std::size_t i = 0; i < size(); i++)
				data()->at(index(), i) = A(0, i);
			break;
			
		case 1:
			for (std::size_t i = 0; i < size(); i++)
				data()->at(i, index()) = A(i, 0);
	}
	//return *source();
}

//
void dbl2slice::operator+=(const dbl2 &A) {
	switch (dim()) {
		case 0:
			for (std::size_t i = 0; i < size(); i++)
				data()->at(index(), i) += A(0, i);
			break;
			
		case 1:
			for (std::size_t i = 0; i < size(); i++)
				data()->at(i, index()) += A(i, 0);
	}
	//return *source();
}

//
void dbl2slice::operator-=(const dbl2 &A) { *this += -A; }

//
void dbl2slice::operator*=(const double x) {
	switch (dim()) {
		case 0:
			for (std::size_t i = 0; i < size(); i++)
				data()->at(index(), i) *= x;
			break;
			
		case 1:
			for (std::size_t i = 0; i < size(); i++)
				data()->at(i, index()) *= x;
	}
	//return *source();
}

//
void dbl2slice::operator/=(const double x) { *this = (*this) / x; }

//
void dbl2slice::operator=(const double x) {
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

//
double dbl2slice::mag() { return dbl1(*this).mag(); }
double dbl2slice::magsqr() { return dbl1(*this).mag(); }

//
dbl1 dbl2slice::pwr(const double x) const {
	dbl1 A(size());
	for (std::size_t i = 0; i < size(); i++)
		A(i) = pow(at(i), x);
	return A;
}

dbl1 dbl2slice::sqr() const { return pwr(2.); }
dbl1 dbl2slice::sqrt() const { return pwr(0.5); }

//friend
dbl2 operator*(double x, const dbl2slice &A) {
	return x * dbl2(A);
}

//friend
std::ostream &operator<<(std::ostream &os, const dbl2slice &A)
{
	return os << dbl2(A);
}

}
