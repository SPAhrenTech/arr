// unit test
#include "unit-test.hpp"

#include "arr.hpp"

/*
 * arr tests
 */
TEST(arrTest, general)
{
    {
        arr::dbl1 d({1., 2., 3.});

        auto root_d=sqrt(d);

        EXPECT_EQ(root_d.size(), 3);
        EXPECT_EQ(root_d(2), sqrt(3.));
    }

  
}
