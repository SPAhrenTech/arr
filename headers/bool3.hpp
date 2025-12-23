// bool arrays (m x n x p)- P. Ahrenkiel

#ifndef _BOOL3_
#define _BOOL3_

#include <iostream>

#ifndef _ARR2_
#include "arr2.hpp"
#endif

namespace arr {
	typedef arr3<bool> bool_arr3;

	class bool3 : public bool_arr3 {
	private:

	public:
			bool3(const std::size_t N0 = 0, const std::size_t N1 = 0, const std::size_t N2 = 0, const bool *a = NULL)
							: bool_arr3(N0, N1, N2, a) {}

			bool3(const bool_arr3 &A) : bool_arr3(A.size(0), A.size(1), A.size(2), A.source()) {}

			bool3 operator=(const bool &x) { return bool_arr3::operator=(x); }

			bool hasTrue() const;

			bool hasFalse() const;

			using bool_arr3::operator();

			static bool3 zero(const size_t n0, const size_t n1, const size_t n2);

			static bool3 ident(const size_t n0, const size_t n1, const size_t n2);
	};
}

#endif
