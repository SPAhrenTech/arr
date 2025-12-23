//bool array slices (n) - P. Ahrenkiel

#ifndef _BOOL2SLICE_
#define _BOOL2SLICE_

#include <iostream>

#ifndef _ARR2SLICE_
#include "arr2slice.hpp"
#endif

namespace arr {
class bool2;

typedef arr2slice<bool> bool_arr2slice;

//
class bool2slice : public bool_arr2slice {
private:
	
public:
	bool2slice(bool2 *A, const std::size_t iDim, const std::size_t iIndex) : bool_arr2slice(A, iDim, iIndex) {}
	bool2slice(const bool_arr2slice &A) : bool_arr2slice(A.data(), A.dim(), A.index()) {}
	
	bool2 operator|(const bool2slice &A) const;
	bool2 operator&(const bool2slice &A) const;
	
	void operator=(const bool2 &A);
	void operator|=(const bool2 &A);
	void operator&=(const bool2 &A);
	void operator|=(const bool x);
	void operator&=(const bool x);
	void operator=(const bool x);
	
	bool hasTrue() const;	
	bool hasFalse() const;
};
}
#endif
