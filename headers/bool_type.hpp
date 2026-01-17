//bool arrays (n) - P. Ahrenkiel

#ifndef _BOOL_TYPE_
#define _BOOL_TYPE_

#include <iostream>

#include "arr1.hpp"

namespace arr {

using bool_type=char;

inline bool_type bool_true=static_cast<bool_type>(true);
inline bool_type bool_false=static_cast<bool_type>(false);

}

#endif

