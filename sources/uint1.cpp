// usigned int arrays (n) - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "dbl1.hpp"
#include "uint1.hpp"

namespace arr {

uint1::uint1(const uint_arr1& A) : uint_arr1(A.size())
{
    for (size_t i = 0; i < size(); i++)
        at(i) = A(i);
}

uint1::uint1(const dbl1& A)
{
    resize(A.size());
    for (size_t i = 0; i < size(); i++)
        at(i) = A(i);
}

uint1 uint1::operator=(const uint &x)
{
	return uint_arr1::operator=(x);
}

} // namespace arr
