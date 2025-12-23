//bool sub arrays (m x n) - P. Ahrenkiel

#ifndef _BOOL2SUB_
#define _BOOL2SUB_

#include <iostream>

#ifndef _ARR2SUB_
#include "arr2sub.hpp"
#endif

namespace arr {
class bool2;

typedef arr2sub<bool> bool_arr2sub;

//
class bool2sub : public bool_arr2sub {
private:

public:
		bool2sub(bool2 *A, const std::size_t iRow, const std::size_t iCol, const std::size_t nRows,
						 const std::size_t nCols) : bool_arr2sub(A, iRow, iCol, nRows, nCols) {}

		bool2sub(const bool_arr2sub &A) : bool_arr2sub(A.data(), A.index(0), A.index(1), A.size(0), A.size(1)) {}

		bool2 operator|(const bool2sub &A) const;

		bool2 operator&(const bool2sub &A) const;

		void operator=(const bool2 &A);

		void operator|=(const bool2 &A);

		void operator&=(const bool2 &A);

		void operator=(const bool &x);

		bool hasTrue() const;

		bool hasFalse() const;
};
}

#endif
