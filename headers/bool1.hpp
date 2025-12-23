//bool arrays (n) - P. Ahrenkiel

#ifndef _BARR1_
#define _BARR1_

#include <iostream>

#ifndef _ARR1_
#include "arr1.hpp"
#endif

namespace arr {
class bool2slice;

typedef arr1<bool> bool_arr1;

class bool1 : public bool_arr1
{
private:

public:
	bool1(const std::size_t N0 = 0, const bool *a = NULL) : bool_arr1(N0, a) {}

	bool1(const bool_arr1 &A) : bool_arr1(A.size(), A.data()) {}

	bool1(const bool2slice &A);

	bool1 operator=(const bool &x) { return bool_arr1::operator=(x); }

	friend std::ostream &operator<<(std::ostream &os, const bool1 &A);

	static bool1 zero(const size_t n);

	bool1 operator|(const bool1 &b) const;

	bool1 operator&(const bool1 &b) const;

	bool1 &operator|=(const bool1 &b);

	bool1 &operator&=(const bool1 &b);

	bool hasTrue() const;

	bool hasFalse() const;
};
}

#endif

