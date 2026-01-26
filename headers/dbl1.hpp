// double arrays (n) - P. Ahrenkiel

#ifndef _DBL1_
#define _DBL1_

#include <iostream>

#include "arr1.hpp"

namespace arr {

class dbl2;
class dbl2slice;

typedef arr1<double> double_arr1;

//
class dbl1 : public double_arr1 {
private:
public:
	dbl1(const std::size_t n=0,const double* ap=NULL);
	dbl1(const double_arr1& A);
	dbl1(const dbl2slice& A);
	
	dbl1 operator+() const;
	dbl1 operator-() const;
	dbl1 operator+(const dbl1& A) const;
	dbl1 operator-(const dbl1& A) const;
	
	dbl1 operator=(const double& x);
	dbl1 operator+=(const dbl1& A);
	dbl1 operator-=(const dbl1& A);
	dbl1 operator/=(double x);
	dbl1 operator*=(double x);
	
	dbl1 pwr(double x) const;
	dbl1 sqr() const;
	dbl1 sqrt() const;
	
	double dot(const dbl1& A) const;
	
	dbl1 operator/(double x) const;
	
	bool swap(std::size_t i1, std::size_t i2);
	dbl1 sub(std::size_t i, std::size_t n) const;
	
	double mag() const;
	double sum() const;
	double sumSqr() const;
	dbl1 norm() const { return (*this) / mag(); }
	
	friend dbl1 norm(const dbl1& A) { return A.norm(); }
	friend double mag(const dbl1& A) { return A.mag(); }
	friend double sumSqr(const dbl1& A) { return A.sumSqr(); }
	friend dbl1 operator*(double x, const dbl1& A);
	
	// predef
	dbl2 T() const;
	dbl2 diag() const;
	
	static dbl1 zero(const size_t n);
	
	dbl2 operator*(const dbl2& A) const;
};

dbl1 pwr(const dbl1& A, const double x);
dbl1 sqr(const dbl1& A);
dbl1 sqrt(const dbl1& A);
} // namespace arr

#endif
