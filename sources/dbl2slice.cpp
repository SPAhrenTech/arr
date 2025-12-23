//double array slices (n) - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "arr.hpp"
#include "mth.hpp"
#include "trg.hpp"

namespace arr {

//
dbl1::dbl1(const dbl2slice &A) : double_arr1(A) {}
dbl2::dbl2(const dbl2slice &A) : double_arr2(A) {}

//
dbl2slice dbl2::slice(const std::size_t iDim, const std::size_t iIndex) { return dbl2slice(this, iDim, iIndex); }
dbl2slice dbl2::row(const std::size_t iIndex) { return dbl2slice(this, 0, iIndex); }
dbl2slice dbl2::col(const std::size_t iIndex) { return dbl2slice(this, 1, iIndex); }

//
dbl2 dbl2slice::operator+() const { return *this; }

//
dbl2 dbl2slice::operator-() const { return -dbl2(*this); }

//
dbl2 dbl2slice::operator+(const dbl2slice &A) const {
	return dbl2(*this) + dbl2(A);
}

//
dbl2 dbl2slice::operator-(const dbl2slice &A) const {
	return dbl2(*this) - dbl2(A);
}

//
dbl2 dbl2slice::operator/(const double x) const {
	return dbl2(*this) / x;
}

//friend
dbl2 operator*(double x, const dbl2slice &A) {
	return x * dbl2(A);
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

}
