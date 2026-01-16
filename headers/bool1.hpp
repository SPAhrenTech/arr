//bool arrays (n) - P. Ahrenkiel

#ifndef _BOOL1_
#define _BOOL1_

#include <iostream>

#include "arr1.hpp"
#include "bool_type.hpp"

namespace arr {

class bool2slice;

typedef arr1<bool_type> bool_arr1;

class bool1 : public bool_arr1
{
private:

public:
	bool1(const std::size_t N0 = 0, const bool *b = NULL);
	
	bool1(const bool_arr1 &A);

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

