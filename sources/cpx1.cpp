/*
Complex 1-D Arrays - P. Ahrenkiel
*/

#include "tlbx.hpp"

#include "cpx1.hpp"
#include "dbl1.hpp"
#include "error.hpp"

namespace arr {

cpx1::cpx1(const dbl1& A):cpx1(A.size())
{
		for(std::size_t i=0;i<A.size();++i)
			(*this)(i)=A(i);
}

cpx1 cpx1::operator+() const
{
	return *this;
}

cpx1 cpx1::operator-() const
{
	cpx1 res(*this);
	for(std::size_t i=0;i<size();++i)
		res(i) *= -1;
	return res;
}

cpx1 cpx1::operator+(const cpx1 &A) const
{
	cpx1 res(*this);
	for(std::size_t i=0;i<size();++i)
		res(i)+=A(i);
	return res;
}

cpx1 cpx1::operator-(const cpx1 &A) const
{
	cpx1 res(*this);
	for(std::size_t i=0;i<size();++i)
		res(i)-=A(i);
	return res;
}

cpx cpx1::operator*(const cpx1 &A) const
{
	cpx res=0;
	if(size()!=A.size())
	{
		err=-1;
		return res;
	}
	for(std::size_t i=0;i<size();++i)
		res+=(*this)(i)*A(i);
	return res;
}

cpx1 cpx1::operator+=(const cpx1 &A)
{	
	return *this=*this+A;
}

cpx1 cpx1::operator-=(const cpx1 &A)
{	
	return *this=*this-A;
}

cpx1 cpx1::operator/(const cpx &C) const
{
	return (1./C)*(*this);
}

cpx1 cpx1::operator*=(const cpx &C)
{
	return *this=C*(*this);
}

cpx1 cpx1::operator/=(const cpx &C)
{
	return *this=(*this)/C;
}

double cpx1::mag() const
{
	return std::sqrt(magsqr());
}

double cpx1::magsqr() const
{
	double res=0.;
	for(std::size_t i=0;i<size();++i)
		res+=((*this)(i)).magsqr();
	return res;
}

cpx1 cpx1::conj() const
{
	cpx1 A=*this;
	for(std::size_t i=0;i<size();++i)
		A(i)=std::conj(A(i));
	return A;
}	

dbl1 cpx1::Re() const
{
	dbl1 A(size());
	for(std::size_t i=0;i<size();++i)
		A(i)=(*this)(i).Re();
	return A;	
}

dbl1 cpx1::Im() const
{
	dbl1 A(size());
	for(std::size_t i=0;i<size();++i)
		A(i)=(*this)(i).Im();
	return A;	
}

cpx1 operator*(const cpx &C,const cpx1 &A)
{
	cpx1 res(A);
	for(std::size_t i=0;i<A.size();++i)
		res(i)=C*A(i);
	return res;
}

std::ostream& operator<<(std::ostream &os,const cpx1 &A)
{
	for(std::size_t i=0;i<A.size();++i)
	{
		if(i>0)os<<"\t";
		os<<A(i);
	}
	os<<std::endl;
	return os;
}

cpx1 operator*(const cpx &C,const dbl1 &A){return C*cpx1(A);}

}
