/* Copyright (c) 2023 Big Ladder Software LLC. All rights reserved.
 * See the LICENSE file for additional terms and conditions. */

// Standard
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

// vendor
#include <gtest/gtest.h>

#include "arr.hpp"
#include "mth.hpp"
#include "trg.hpp"

/*
 *
 */
TEST(arrTest, first_test)
{

	arr::darr2 M=arr::darr2::zero(5,6);
	for(std::size_t i=0;i<M.size(0);++i)
		for(std::size_t j=0;j<M.size(1);++j)
			M(i,j)=mth::rndom();
	
	//cout<<M.rowEschelon()<<"\n";
	
	arr::darr2 V;
	arr::darr2 S=(M*M.T()).diagSymm(V);
	
	EXPECT_EQ(S(1,2), 0.) << "not symmetric";
	//M(1,0,1,3)=0.;
	//cout<<M<<"\n";
	/*
	for(size_t i=0;i<M.size(0);i++)
	{
		M.row(i)=i;
		darr1 C=M.row(i);

		std::cout<<"M:\n"<<M<<"\n";
		std::cout<<"C:\n"<<C<<"\n";
	}
	
	cout<<M.icol();
	*/

}
