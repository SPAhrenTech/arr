/* Copyright (c) 2023 Big Ladder Software LLC. All rights reserved.
 * See the LICENSE file for additional terms and conditions. */

// Standard
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

// vendor
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../headers/arr.hpp"

/*
 *
 */
TEST(arrTest, first_test)
{

    arr::darr1 xV(3);
    int i = 0;
    for (auto &x: xV)
        x=++i;

}
