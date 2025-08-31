#include "MySolution1.hpp"
#include <gtest/gtest.h>

TEST(MySolution1Test, PositiveNumber) {
    Solution solution;
    EXPECT_EQ(solution.myAtoi("42"), 42);
}

TEST(MySolution1Test, NegativeNumber) {
    Solution solution;
    EXPECT_EQ(solution.myAtoi("-42"), -42);
}

TEST(MySolution1Test, LeadingWhitespace) {
    Solution solution;
    EXPECT_EQ(solution.myAtoi("   42"), 42);
}

TEST(MySolution1Test, TrailingCharacters) {
    Solution solution;
    EXPECT_EQ(solution.myAtoi("42abc"), 42);
}

TEST(MySolution1Test, Overflow) {
    Solution solution;
    EXPECT_EQ(solution.myAtoi("2147483648"), INT_MAX);
}

TEST(MySolution1Test, Underflow) {
    Solution solution;
    EXPECT_EQ(solution.myAtoi("-2147483649"), INT_MIN);
}

TEST(MySolution1Test, EmptyString) {
    Solution solution;
    EXPECT_EQ(solution.myAtoi(""), 0);
}

TEST(MySolution1Test, InvalidCharacters) {
    Solution solution;
    EXPECT_EQ(solution.myAtoi("abc42"), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}