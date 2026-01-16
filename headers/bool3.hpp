// bool arrays (m x n x p)- P. Ahrenkiel

#ifndef _BOOL3_
#define _BOOL3_

#include <iostream>

#include "arr3.hpp"
#include "bool_type.hpp"

namespace arr {

	typedef arr3<bool_type> bool_arr3;

	class bool3 : public bool_arr3 {
	private:

	public:
			bool3(const std::size_t N0 = 0, const std::size_t N1 = 0, const std::size_t N2 = 0, const bool *b = NULL);

			bool3(const bool_arr3 &A);

			bool3 operator=(const bool &x);

			bool hasTrue() const;

			bool hasFalse() const;

			using bool_arr3::operator();

			static bool3 zero(const size_t n0, const size_t n1, const size_t n2);

			static bool3 ident(const size_t n0, const size_t n1, const size_t n2);
	};
}

#endif
