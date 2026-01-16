// double arrays (m x n) - P. Ahrenkiel

#ifndef _DBL2_
#define _DBL2_

#include <iostream>

#include "arr2.hpp"

namespace arr {

class dbl1;
class bool2;
class uint2;
class dbl2slice;
class dbl2sub;

typedef arr2<double> double_arr2;

//
class dbl2 : public double_arr2 {
private:

public:
	dbl2(const std::size_t nRows = 0, std::size_t nCols = 0, const double* a = NULL);
	
	dbl2(const dbl1& A);
	dbl2(const double_arr2& A);
	dbl2(const dbl2slice& A);
	dbl2(const dbl2sub& A);
	dbl2(const uint2& A);
	
	dbl2 operator+() const;
	dbl2 operator-() const;
	dbl2 operator+(const dbl2& A) const;
	dbl2 operator-(const dbl2& A) const;
	dbl2 operator/(double x) const;
	
	dbl2 operator+=(const dbl2& A);
	dbl2 operator-=(const dbl2& A);
	
	dbl2 operator=(const double& x);
	dbl2 operator*=(double x);
	dbl2 operator/=(double x);
	
	dbl1 operator*(const dbl1& A) const;
	dbl2 operator*(const dbl2& A) const;
	
	friend dbl2 operator*(double x, const dbl2& A);
	friend dbl2 operator*(double x, const dbl2slice& A);
	
	dbl2 pwr(const double x) const;
	dbl2 sqr() const;
	dbl2 sqrt() const;
	
	bool isSquareSymm() const;
	
	dbl2 minor(const std::size_t m, const std::size_t n) const;
	dbl2 T() const;
	dbl2 inv() const;
	dbl1 diag() const;
	
	dbl2 pseudoInvLeft() const;
	dbl2 pseudoInvRight() const;
	dbl2 dampedPseudoInvLeft(double lambda) const;
	dbl2 cofactor() const;
	dbl2 adjugate() const;
	double trace() const;
	double det() const;
	double diagProd() const;
	dbl2 makePivotable(bool& isSingular) const;
	dbl2 upper(bool& isSingular) const;
	dbl2 Householder(const size_t i) const;
	dbl2 Householder(const size_t iRow, const size_t jCol) const;
	dbl2 upperTriang(dbl2& P) const;
	dbl2 upperBidiag(dbl2& U, dbl2& V) const;
	dbl2 tridiag(dbl2& P) const;
	bool PLU(dbl2& P, dbl2& L, dbl2& U) const;
	dbl2 QR(dbl2& Q) const;
	bool diagSymm(dbl2& s, dbl2& v) const;
	dbl2 diagSymm(dbl2& v) const;
	bool SVD(dbl2& u, dbl2& s, dbl2& v) const;
	bool SVDred(dbl2& u, dbl2& s, dbl2& v, double fac) const;
	dbl2 pseudoInv(double fac) const;
	dbl2 rowEschelon() const;
	dbl2 span() const;
	dbl2 nullspace() const;
	
	using double_arr2::operator();
	using double_arr2::icol;
	using double_arr2::irow;
	
	dbl2slice slice(const std::size_t iDim, const std::size_t iIndex);
	dbl2slice row(const std::size_t iRow);
	dbl2slice col(const std::size_t iCol);
	dbl2sub sub(const std::size_t iRow,
							 const std::size_t iCol,
							 const std::size_t nRows,
							 const std::size_t nCols);
	
	dbl2sub operator()(const std::size_t iRow,
											const std::size_t iCol,
											const std::size_t nRows,
											const std::size_t nCols);
	
	double findAngle(const size_t i, const size_t j, double& ang) const;
	double sum() const;
	double sumSqr() const;
	double sumOffDiag() const;
	
	static dbl2 zero(const size_t m, const size_t n);
	static dbl2 ident(const size_t m, const size_t n);
	static dbl2 rot(const size_t iRow, const size_t jCol, double ang, size_t n);
	
	void rotR(const size_t iCol, const size_t jCol, double ang);
	void rotL(const size_t iRow, const size_t jRow, double ang);
	dbl2 zero();
	dbl2 ident();
	
	static bool showOutput;
};

dbl2 pwr(const dbl2& A, const double x);
dbl2 sqr(const dbl2& A);
dbl2 sqrt(const dbl2& A);
} // namespace arr

#endif
