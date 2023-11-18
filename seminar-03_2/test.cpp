#include <iostream>

#include <gtest/gtest.h>

#include "searcher.hpp"

class TestUtils : public ::testing::Test
{
/*
    void SetUp()
    {
        std::cout << "Set up" << std::endl;
    }

    void TearDown()
    {
        std::cout << "Tear down" << std::endl;
    }
*/
};

// TEST_F(<Название класса теста выше>, <название вашего теста>)
TEST_F(TestUtils, test_search)
{
    {
        std::string expected{"Rostov,18"};
        ASSERT_EQ(expected, search("weather", 1));
    }
    {
        std::string expected;
        ASSERT_EQ(expected, search("vk", 70));
    }
}

TEST_F(TestUtils, test_soundex)
{
    //assert(convertTextToSound("Ashcraft") == std::string{"A262"});

    {
        std::string expected{"A261"};
        ASSERT_EQ(expected, convertTextToSound("Ashcraft"));
    }
    {
        std::string expected{"A261"};
        ASSERT_EQ(expected, convertTextToSound("Ashcroft"));
    }
    {
        std::string expected{"0000"};
        ASSERT_EQ(expected, convertTextToSound("MIPT"));
    }

    {
        ASSERT_TRUE(isEqual("Ashcroft", "Ashcraft"));
        ASSERT_FALSE(isEqual("Ashcroft", "Eshcraft"));
    }
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
