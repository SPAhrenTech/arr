// bool arrays (m x n)- P. Ahrenkiel

#ifndef _BOOL2_
#define _BOOL2_

#include <iostream>

#ifndef _ARR2_
#include "arr2.hpp"
#endif

namespace arr {
class bool2slice;

class bool2sub;

typedef arr2<bool> bool_arr2;

class bool2 : public bool_arr2 {
private:
	
public:
	bool2(const std::size_t N0 = 0, const std::size_t N1 = 0, const bool *a = NULL) : bool_arr2(N0, N1, a) {}
	bool2(const bool_arr2 &A) : bool_arr2(A.size(0), A.size(1), A.data()) {}
	bool2(const bool2slice &A);
	bool2(const bool2sub &A);
	
	bool2 operator|(const bool2 &b) const;
	
	bool2 operator&(const bool2 &b) const;
	
	bool2 operator=(const bool &x) { return bool_arr2::operator=(x); }
	bool2 &operator|=(const bool2 &b);
	bool2 &operator&=(const bool2 &b);
	
	bool hasTrue() const;
	bool hasFalse() const;
	
	using bool_arr2::operator();
	
	bool2slice slice(const std::size_t iDim, const std::size_t iIndex);
	bool2slice row(const std::size_t iRow);
	bool2slice col(const std::size_t iCol);
	
	using bool_arr2::irow;
	using bool_arr2::icol;
	
	bool2sub sub(const std::size_t iRow, const std::size_t iCol, const std::size_t nRows, const std::size_t nCols);
	
	bool2sub
	operator()(const std::size_t iRow, const std::size_t iCol, const std::size_t nRows, const std::size_t nCols);
	
	friend std::ostream &operator<<(std::ostream &os, const bool2 &A);
	
	static bool2 zero(const size_t m, const size_t n);
	static bool2 ident(const size_t m, const size_t n);
};
}
#endif
