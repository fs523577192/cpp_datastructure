#include <gtest/gtest.h>
#include "../main/typeAlias.hpp"

class TypeAliasTests : public testing::Test {
};

TEST_F(TypeAliasTests, Int32) {
    t_int32 n = { -1 };
    EXPECT_EQ( 4, sizeof(t_int32) );
    EXPECT_EQ( 4, sizeof(n) );

    EXPECT_TRUE( n == -1 );
    EXPECT_TRUE( n < 0 );
    EXPECT_TRUE( n <= 0 );
    EXPECT_TRUE( (n += 1) == 0 );
    EXPECT_FALSE( n < 0 );
    EXPECT_TRUE( n <= 0 );
    EXPECT_FALSE( n > 0 );
    EXPECT_TRUE( n >= 0 );

    EXPECT_TRUE( (n -= 1) == -1 );

    EXPECT_TRUE( (n += 2) == 1 );
    EXPECT_TRUE( n > 0 );
    EXPECT_TRUE( n >= 0 );
}

TEST_F(TypeAliasTests, UInt32) {
    t_uint32 n = { 0 };
    EXPECT_EQ( 4, sizeof(t_uint32) );
    EXPECT_EQ( 4, sizeof(n) );

    EXPECT_TRUE( n == 0 );
    EXPECT_FALSE( n < 0 );
    EXPECT_TRUE( n <= 0 );
    EXPECT_FALSE( n > 0 );
    EXPECT_TRUE( n >= 0 );

    EXPECT_TRUE( (n += 1) == 1 );
    EXPECT_TRUE( n > 0 );
    EXPECT_TRUE( n >= 0 );
}

TEST_F(TypeAliasTests, Int64) {
    t_int64 n = { -1L };
    EXPECT_EQ( 8, sizeof(t_int64) );
    EXPECT_EQ( 8, sizeof(n) );

    EXPECT_TRUE( n == -1L );
    EXPECT_TRUE( n < 0L );
    EXPECT_TRUE( n <= 0L );
    EXPECT_TRUE( (n += 1L) == 0L );
    EXPECT_FALSE( n < 0L );
    EXPECT_TRUE( n <= 0L );
    EXPECT_FALSE( n > 0L );
    EXPECT_TRUE( n >= 0L );

    EXPECT_TRUE( (n -= 1L) == -1L );

    EXPECT_TRUE( (n += 2L) == 1L );
    EXPECT_TRUE( n > 0L );
    EXPECT_TRUE( n >= 0L );
}

TEST_F(TypeAliasTests, UInt64) {
    t_uint64 n = { 0 };
    EXPECT_EQ( 8, sizeof(t_uint64) );
    EXPECT_EQ( 8, sizeof(n) );

    EXPECT_TRUE( n == 0L );
    EXPECT_FALSE( n < 0L );
    EXPECT_TRUE( n <= 0L );
    EXPECT_FALSE( n > 0L );
    EXPECT_TRUE( n >= 0L );

    EXPECT_TRUE( (n += 1L) == 1L );
    EXPECT_TRUE( n > 0L );
    EXPECT_TRUE( n >= 0L );
}
