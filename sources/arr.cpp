// arrays - P. Ahrenkiel

#include "arr.hpp"

namespace arr {

int arr_err = 0;

//
int check_arr_err()
{
    int res = arr_err;
    arr_err = 0;
    return res;
}

//
void clear_arr_err() { arr_err = 0; }

} // namespace arr
