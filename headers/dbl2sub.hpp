//double sub arrays (m x n) - P. Ahrenkiel

#ifndef _DBL2SUB_
#define _DBL2SUB_

#include <iostream>

#ifndef _ARR2SUB_
#include "arr2sub.hpp"
#endif

namespace arr {
class dbl2;

typedef arr2sub<double> double_arr2sub;

//
class dbl2sub : public double_arr2sub {
private:

public:
		dbl2sub(dbl2 *A, const std::size_t iRow, const std::size_t iCol, const std::size_t nRows,
						 const std::size_t nCols) : double_arr2sub(A, iRow, iCol, nRows, nCols) {}

		dbl2sub(const double_arr2sub &A) : double_arr2sub(A.data(), A.index(0), A.index(1), A.size(0), A.size(1)) {}

		dbl2 operator+() const;

		dbl2 operator-() const;

		dbl2 operator+(const dbl2sub &A) const;

		dbl2 operator-(const dbl2sub &A) const;

		void operator=(const dbl2 &A);

		void operator+=(const dbl2 &A);

		void operator-=(const dbl2 &A);

		dbl2 operator/(const double x) const;

		void operator*=(const double x);

		void operator/=(const double x);

		void operator=(const double &x);

		dbl2 pwr(const double x) const;
		dbl2 sqr();
		dbl2 sqrt();
};

dbl2 pwr(const dbl2sub &A, const double x);
dbl2 sqr(const dbl2sub &A);
dbl2 sqrt(const dbl2sub &A);
}

#endif
