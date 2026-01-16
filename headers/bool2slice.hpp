//bool array slices (n) - P. Ahrenkiel

#ifndef _BOOL2SLICE_
#define _BOOL2SLICE_

#include <iostream>

#include "arr2slice.hpp"
#include "bool_type.hpp"

namespace arr {

class bool2;

typedef arr2slice<bool_type> bool_arr2slice;

//
class bool2slice : public bool_arr2slice {
private:
	
public:
	bool2slice(bool2 *A, const std::size_t iDim, const std::size_t iIndex);
	bool2slice(const bool_arr2slice &A);
	
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
