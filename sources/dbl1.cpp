// double arrays (n) - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "mth.hpp"
#include "trg.hpp"

#include "dbl1.hpp"
#include "dbl2slice.hpp"

namespace arr {

dbl1::dbl1(const std::size_t n,const double* ap):
	double_arr1(n, ap)
{
}
	
dbl1::dbl1(const double_arr1& A):
	double_arr1(A.size(), A.data())
{
}

dbl1 dbl1::operator=(const double& x)
{
	return double_arr1::operator=(x);
}

dbl1 dbl1::operator+() const { return *this; }

dbl1 dbl1::operator-() const
{
    dbl1 res(*this);
    for (size_t i = 0; i < size(); ++i)
        res(i) *= -1;
    return res;
}

//
dbl1 dbl1::operator+(const dbl1& A) const
{
    dbl1 res(*this);
    for (size_t i = 0; i < size(); ++i)
        res(i) += A(i);
    return res;
}

//
dbl1 dbl1::operator-(const dbl1& A) const
{
    dbl1 res(*this);
    for (size_t i = 0; i < size(); ++i)
        res(i) -= A(i);
    return res;
}

//
double dbl1::dot(const dbl1& A) const
{
    double res = 0;
    if (size() != A.size()) {
        err = -1;
        return res;
    }
    for (size_t i = 0; i < size(); ++i)
        res += at(i) * A(i);
    return res;
}

dbl1 dbl1::operator+=(const dbl1& A) { return *this = *this + A; }

dbl1 dbl1::operator-=(const dbl1& A) { return *this = *this - A; }

dbl1 dbl1::operator/(double x) const { return (1. / x) * (*this); }

dbl1 dbl1::operator*=(double x) { return *this = x * (*this); }

dbl1 dbl1::operator/=(double x) { return *this = (*this) / x; }

//
double dbl1::sum() const
{
    double res = 0;
    for (size_t i = 0; i < size(); ++i)
        res += at(i);
    return res;
}

//
double dbl1::sumSqr() const
{
    double res = 0;
    for (size_t i = 0; i < size(); ++i)
        res += mth::sqr(at(i));
    return res;
}

//
dbl1 operator*(double x, const dbl1& A)
{
    dbl1 res(A);
    for (size_t i = 0; i < A.size(); ++i)
        res(i) = x * A(i);
    return res;
}

//
double dbl1::mag() const { return ::sqrt(sumSqr()); }

//
bool dbl1::swap(std::size_t i1, std::size_t i2)
{
    if (!((i1 < size() && (i2 < size()))))
        return false;
    double x = (*this)(i1);
    (*this)(i1) = at(i2);
    at(i2) = x;
    return true;
}

//
dbl1 dbl1::sub(std::size_t iRow, std::size_t nRow) const
{
    if (iRow + nRow > size())
        nRow = size() - iRow;
    dbl1 res(nRow);
    for (size_t i = 0; i < nRow; ++i)
        res(i) = at(i + iRow);
    return res;
}

//
dbl1 dbl1::zero(const size_t n)
{
    dbl1 res(n);
    res = 0.;
    return res;
}

//
dbl1 dbl1::pwr(double x) const
{
    dbl1 A(size());
    for (size_t i = 0; i < size(); ++i)
        A(i) = pow(at(i), x);
    return A;
}

dbl1 dbl1::sqr() const { return pwr(2); }

dbl1 dbl1::sqrt() const { return pwr(0.5); }

dbl1 sqr(const dbl1& A) { return A.sqr(); }

dbl1 sqrt(const dbl1& A) { return A.sqrt(); }

dbl1::dbl1(const dbl2slice &A) : double_arr1(A) {}

} // namespace arr
