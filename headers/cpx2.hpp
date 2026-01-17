/*
Arrays: Rank 2- P. Ahrenkiel
*/

#ifndef _CPX2
#define _CPX2

#include "arr2.hpp"
#include "cpx.hpp"

namespace arr {

class cpx1;

typedef arr2<cpx> cpx_arr2;

class cpx2:public cpx_arr2
{
private:
	
public:

	cpx2(const std::size_t nRows=0, std::size_t nCols=0, const cpx* a=NULL):
		cpx_arr2(nRows, nCols, a){}
	cpx2():cpx_arr2(){}
	cpx2(const cpx_arr2 &A):cpx_arr2(A){}

	cpx2 operator+() const;
	cpx2 operator-() const;
	cpx2 operator+(const cpx2 &A) const;
	cpx2 operator-(const cpx2 &A) const;
	cpx2 operator+=(const cpx2 &A);
	cpx2 operator-=(const cpx2 &A);

	cpx2 operator/(cpx x) const;
	cpx2 operator*=(cpx x);
	cpx2 operator/=(cpx x);

	cpx2 operator/(double x) const;
	cpx2 operator*=(double x);
	cpx2 operator/=(double x);

	cpx1 operator*(const cpx1 &A) const;
	cpx2 operator*(const cpx2 &A) const;

	friend cpx2 operator*(double x,const cpx2 &A);
	friend cpx2 operator*(cpx C,const cpx2 &A);

	//cpx2 transpose() const{return transpose();}//override
	cpx2 inverse() const;
	cpx2 diagonal() const;
	cpx2 pseudoinverse_left() const;
	cpx2 pseudoinverse_right() const;
	cpx2 damped_pseudoinverse_left(double lambda) const;
	cpx2 minor(std::size_t m,std::size_t n) const;
	cpx2 cofactor() const;
	cpx2 adjugate() const;
	cpx det() const;

	friend std::ostream& operator<<(std::ostream &os,const cpx2 &A);
};

} // namespace arr
#endif
