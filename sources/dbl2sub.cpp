//double sub arrays (m x n) - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "arr.hpp"
#include "mth.hpp"
#include "trg.hpp"

namespace arr {

//
dbl2::dbl2(const dbl2sub &A):double_arr2(A){}

//
dbl2sub dbl2::sub(const std::size_t iRow,const std::size_t iCol,const std::size_t nRows,const std::size_t nCols)
{
	return double_arr2::sub(iRow,iCol,nRows,nCols);
}

//
dbl2sub dbl2::operator()(const std::size_t iRow,const std::size_t iCol,const std::size_t nRows,const std::size_t nCols)
{
	return sub(iRow,iCol,nRows,nCols);
}

//
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
	for(std::size_t i=0;i<m_nRows;i++)
		for(std::size_t j=0;j<m_nCols;j++)
			at(i,j)=A(i,j);
}

//
void dbl2sub::operator+=(const dbl2 &A)
{
	if((size(0)!=A.size(0))||(size(1)!=A.size(1)))return;
	for(std::size_t i=0;i<m_nRows;i++)
		for(std::size_t j=0;j<m_nCols;j++)
			at(i,j)+=A(i,j);
}

//
void dbl2sub::operator-=(const dbl2 &A)
{
	*this+=-A;
}

//
void dbl2sub::operator*=(const double x)
{
	for(std::size_t i=0;i<m_nRows;i++)
		for(std::size_t j=0;j<m_nCols;j++)
			at(i,j)*=x;
}

//
void dbl2sub::operator/=(const double x)
{
	*this*=1./x;
}

//
dbl2 dbl2sub::pwr(const double x) const
{
	dbl2 A(m_nRows,m_nCols);
	for(std::size_t i=0;i<m_nRows;i++)
		for(std::size_t j=0;j<m_nCols;j++)
			A(i,j)=pow(at(i,j),x);
	return A;
}

//
void dbl2sub::operator=(const double &x)
{
	for(std::size_t i=0;i<m_nRows;i++)
		for(std::size_t j=0;j<m_nCols;j++)
			at(i,j)=x;
}
}
