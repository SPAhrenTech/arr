//array slices (n) - P. Ahrenkiel

#ifndef _DBL2SLICE_
#define _DBL2SLICE_

#include <iostream>

#ifndef _ARR2SLICE_
#include "arr2slice.hpp"
#endif

namespace arr {
class dbl2;

typedef arr2slice<double> double_arr2slice;

//
class dbl2slice : public double_arr2slice {
private:

public:
	dbl2slice(dbl2 *A, const std::size_t iDim, const std::size_t iIndex) : double_arr2slice(A, iDim, iIndex) {}

	dbl2slice(const double_arr2slice &A) : double_arr2slice(A.data(), A.dim(), A.index()) {}

	dbl2 operator+() const;

	dbl2 operator-() const;

	dbl2 operator+(const dbl2slice &A) const;

	dbl2 operator-(const dbl2slice &A) const;

	void operator=(const dbl2 &A);

	void operator+=(const dbl2 &A);

	void operator-=(const dbl2 &A);

	dbl2 operator/(const double x) const;

	void operator*=(const double x);

	void operator/=(const double x);

	void operator=(const double x);

	dbl1 pwr(const double x) const;

	dbl1 sqr() const;

	dbl1 sqrt() const;

	double mag();

	double magsqr();

	friend dbl2 operator*(double x, const dbl2slice &A);

	friend std::ostream &operator<<(std::ostream &os, const dbl2slice &A) { return os << dbl2(A); }
};

dbl1 pwr(const dbl2slice &A, const double x);
dbl1 sqr(const dbl2slice &A);
dbl1 sqrt(const dbl2slice &A);

double mag(const dbl2slice &A);

double magsqr(const dbl2slice &A);
}

#endif
