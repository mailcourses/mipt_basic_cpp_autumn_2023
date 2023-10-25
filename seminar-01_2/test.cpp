#include <iostream>

#include <gtest/gtest.h>

#include "utils.hpp"

class TestUtils : public ::testing::Test
{
    void SetUp()
    {
        std::cout << "Set up" << std::endl;
    }

    void TearDown()
    {
        std::cout << "Tear down" << std::endl;
    }
};

TEST_F(TestUtils, test_replace_spaces)
{
    {
        std::string expected{"hello%world"};
        ASSERT_EQ(expected, replace_spaces("hello world"));
    }
    {
        std::string expected{""};
        ASSERT_EQ(expected, replace_spaces(""));
    }
    {
        std::string expected{"%%%"};
        ASSERT_EQ(expected, replace_spaces("%%%"));
    }
}

TEST_F(TestUtils, test_dummy)
{
}

/*
 * ./test_bin arg1 arg2 -o test
 * argc = 5
 * argv[0] == "./test_bin"
 * argv[1] == "arg1"
 * argv[2] == "arg2"
 * argv[3] == "-o"
 * argv[4] == "test"
 */
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
