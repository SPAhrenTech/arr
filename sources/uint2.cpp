// unsigned int arrays (m x n) - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "uint2.hpp"

namespace arr {

uint2::uint2(const uint_arr2& A) : uint_arr2(A.size(0), A.size(1))
{
    for (size_t i = 0; i < _nRows; i++)
        for (size_t j = 0; j < _nCols; j++)
            at(i, j) = A(i, j);
}

uint2 uint2::minor(std::size_t iRow, std::size_t iCol) const
{
    uint2 res(size(0) - 1, size(1) - 1);
    size_t ip = 0;
    for (size_t i = 0; i < size(1); i++)
        if (i != iRow) {
            size_t jp = 0;
            for (size_t j = 0; j < size(0); j++)
                if (j != iCol) {
                    res(ip, jp) = at(i, j);
                    jp++;
                }
            ip++;
        }

    return res;
}

uint2 uint2::zero(const size_t nRows, const size_t nCols)
{
    uint2 res(nRows, nCols);
    res = 0;
    return res;
}

uint2 uint2::ident(const size_t nRows, const size_t nCols)
{
    uint2 A(nRows, nCols);
    for (size_t i = 0; i < nRows; i++)
        for (size_t j = 0; j < nCols; j++)
            A(i, j) = (i == j) ? 1 : 0;
    return A;
}

} // namespace arr
