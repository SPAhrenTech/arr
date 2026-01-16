//bool sub arrays (m x n) - P. Ahrenkiel

#ifndef _BOOL2SUB_
#define _BOOL2SUB_

#include <iostream>

#include "arr2sub.hpp"
#include "bool_type.hpp"

namespace arr {
class bool2;

typedef arr2sub<bool_type> bool_arr2sub;

//
class bool2sub : public bool_arr2sub {
private:

public:
		bool2sub(bool2 *A, const std::size_t iRow, const std::size_t iCol, const std::size_t nRows,
						 const std::size_t nCols);

		bool2sub(const bool_arr2sub &A);
		
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
