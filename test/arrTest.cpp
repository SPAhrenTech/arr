// unit test
#include "unit-test.hpp"

#include "mth.hpp"

#include "arr.hpp"

/*
 * arr tests
 */
TEST(arrTest, dbl1)
{
	arr::dbl1 d({1., 2., 3.});

	auto root_d=sqrt(d);

	EXPECT_EQ(root_d.size(), 3);
	EXPECT_EQ(root_d(2), sqrt(3.));
}

TEST(arrTest, dbl2)
{
	arr::dbl2 d2({{4,5,6},{1,7,2,3}});
	EXPECT_EQ(d2.size(0), 2);
	EXPECT_EQ(d2.size(1), 3);
	
	arr::dbl2 M=arr::dbl2::zero(5,6);
	for(std::size_t i=0;i<M.size(0);++i)
		for(std::size_t j=0;j<M.size(1);++j)
			M(i,j)=mth::random();
	
	auto rowEschM=M.rowEschelon();
	EXPECT_EQ(rowEschM(0,0), 1.);
	EXPECT_EQ(rowEschM(1,0), 0.);
	EXPECT_EQ(rowEschM(1,1), 1.);
	
	arr::dbl2 V;
	arr::dbl2 S=(M*M.T()).diagSymm(V);
	EXPECT_EQ(S(0,1), 0.);
}

