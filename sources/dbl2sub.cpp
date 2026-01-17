//double sub arrays (m x n) - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "mth.hpp"
#include "trg.hpp"

#include "dbl1.hpp"
#include "dbl2.hpp"
#include "dbl2sub.hpp"

namespace arr {


dbl2sub::dbl2sub(dbl2 *A, const std::size_t iRow, const std::size_t iCol,
	const std::size_t nRows, const std::size_t nCols):
	double_arr2sub(A, iRow, iCol, nRows, nCols) {}

dbl2sub::dbl2sub(const double_arr2sub &A):double_arr2sub(A) {}

dbl2 dbl2sub::operator+() const
{
	return dbl2(*this);
}

//
dbl2 dbl2sub::operator-() const
{
	return -dbl2(*this);
}

//
dbl2 dbl2sub::operator+(const dbl2sub &A) const
{
	return dbl2(*this)+dbl2(A);
}

//
dbl2 dbl2sub::operator-(const dbl2sub &A) const
{
	return dbl2(*this)-dbl2(A);
}

//
dbl2 dbl2sub::operator/(const double x) const
{
	return dbl2(*this)/x;
}

//
dbl2 operator*(double x,const dbl2sub &A)
{
	return x*dbl2(A);
}

//
void dbl2sub::operator=(const dbl2 &A)
{
	if((size(0)!=A.size(0))||(size(1)!=A.size(1)))return;
	for(std::size_t i=0;i<_nRows;i++)
		for(std::size_t j=0;j<_nCols;j++)
			at(i,j)=A(i,j);
}

void dbl2sub::operator+=(const dbl2 &A)
{
	if((size(0)!=A.size(0))||(size(1)!=A.size(1)))return;
	for(std::size_t i=0;i<_nRows;i++)
		for(std::size_t j=0;j<_nCols;j++)
			at(i,j)+=A(i,j);
}

void dbl2sub::operator-=(const dbl2 &A)
{
	*this+=-A;
}

void dbl2sub::operator*=(const double x)
{
	for(std::size_t i=0;i<_nRows;i++)
		for(std::size_t j=0;j<_nCols;j++)
			at(i,j)*=x;
}

void dbl2sub::operator/=(const double x)
{
	*this*=1./x;
}

dbl2 dbl2sub::pwr(const double x) const
{
	dbl2 A(_nRows,_nCols);
	for(std::size_t i=0;i<_nRows;i++)
		for(std::size_t j=0;j<_nCols;j++)
			A(i,j)=pow(at(i,j),x);
	return A;
}

//
void dbl2sub::operator=(const double &x)
{
	for(std::size_t i=0;i<_nRows;i++)
		for(std::size_t j=0;j<_nCols;j++)
			at(i,j)=x;
}
}
