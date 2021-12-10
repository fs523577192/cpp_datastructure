#include <gtest/gtest.h>
#include "../main/list/LinkedList.cpp"

constexpr t_uint32 ZERO = { 0 };
constexpr t_uint32 ONE = { 1 };
constexpr t_uint32 TWO = { 2 };

namespace NS_DataStructure {

    class LinkedListTests : public testing::Test {
    };

    TEST_F(LinkedListTests, EmptyList) {
        LinkedList::UniDirectionalNonCircular<t_uint32> list;
        EXPECT_EQ( ZERO, list.size() );
    }

    TEST_F(LinkedListTests, Prepend) {
        LinkedList::UniDirectionalNonCircular<t_uint32> list;
        EXPECT_TRUE( list.prepend(ZERO) );
        EXPECT_EQ( ONE, list.size() );

        EXPECT_TRUE( list.prepend(ONE) );
        EXPECT_EQ( TWO, list.size() );

        EXPECT_EQ( ONE, list.get(ZERO) );
        EXPECT_EQ( ZERO, list.get(ONE) );
    }

    TEST_F(LinkedListTests, Append) {
        LinkedList::UniDirectionalNonCircular<t_uint32> list;
        EXPECT_TRUE( list.append(ZERO) );
        EXPECT_EQ( ONE, list.size() );

        EXPECT_TRUE( list.append(ONE) );
        EXPECT_EQ( TWO, list.size() );

        EXPECT_EQ( ZERO, list.get(ZERO) );
        EXPECT_EQ( ONE, list.get(ONE) );
    }

    TEST_F(LinkedListTests, SetByIndex) {
        LinkedList::UniDirectionalNonCircular<t_uint32> list;
        list.prepend(ZERO);
        list.prepend(ONE);
        EXPECT_TRUE( list.set(ZERO, TWO) );
        EXPECT_TRUE( list.set(ONE, ONE) );

        EXPECT_EQ( TWO, list.get(ZERO) );
        EXPECT_EQ( ONE, list.get(ONE) );
    }

    TEST_F(LinkedListTests, InsertByIndex) {
        LinkedList::UniDirectionalNonCircular<t_uint32> list;
        EXPECT_TRUE( list.add(ZERO, TWO) );
        EXPECT_EQ( ONE, list.size() );
        EXPECT_TRUE( list.set(ZERO, TWO) );

        // still insert at the beginning
        EXPECT_TRUE( list.add(ZERO, ONE) );
        EXPECT_EQ( TWO, list.size() );
        EXPECT_EQ( ONE, list.get(ZERO) );
        EXPECT_EQ( TWO, list.get(ONE) );

        // insert at the end
        constexpr t_uint32 THREE = { 3 };
        EXPECT_TRUE( list.add(TWO, ZERO) );
        EXPECT_EQ( THREE, list.size() );
        EXPECT_EQ( ONE, list.get(ZERO) );
        EXPECT_EQ( TWO, list.get(ONE) );
        EXPECT_EQ( ZERO, list.get(TWO) );

        constexpr t_uint32 FOUR = { 4 };
        EXPECT_TRUE( list.add(ONE, THREE) );
        EXPECT_EQ( FOUR, list.size() );
        EXPECT_EQ( ONE, list.get(ZERO) );
        EXPECT_EQ( THREE, list.get(ONE) );
        EXPECT_EQ( TWO, list.get(TWO) );
        EXPECT_EQ( ZERO, list.get(THREE) );
    }
}; // namespace NS_DataStructure

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
//    LinkedList::UniDirectionalNonCircular<t_uint32> list;
//    list.prepend( ZERO );
//    return 0;
}
