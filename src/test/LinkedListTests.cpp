#include <gtest/gtest.h>
#include "../main/list/LinkedList.cpp"

constexpr t_uint32 ZERO = { 0 };
constexpr t_uint32 ONE = { 1 };
constexpr t_uint32 TWO = { 2 };

class LinkedListTests : public testing::Test {
};

TEST_F(LinkedListTests, EmptyList) {
    LinkedList::UniDirectionalNonCircular<t_uint32> list;
    EXPECT_EQ( ZERO, list.getSize() );
}

TEST_F(LinkedListTests, Prepend) {
    LinkedList::UniDirectionalNonCircular<t_uint32> list;
    EXPECT_TRUE( list.prepend(ZERO) );
    EXPECT_EQ( ONE, list.getSize() );

    EXPECT_TRUE( list.prepend(ONE) );
    EXPECT_EQ( TWO, list.getSize() );

    EXPECT_EQ( ONE, list.getByIndex(ZERO) );
    EXPECT_EQ( ZERO, list.getByIndex(ONE) );
}

TEST_F(LinkedListTests, Append) {
    LinkedList::UniDirectionalNonCircular<t_uint32> list;
    EXPECT_TRUE( list.append(ZERO) );
    EXPECT_EQ( ONE, list.getSize() );

    EXPECT_TRUE( list.append(ONE) );
    EXPECT_EQ( TWO, list.getSize() );

    EXPECT_EQ( ZERO, list.getByIndex(ZERO) );
    EXPECT_EQ( ONE, list.getByIndex(ONE) );
}

TEST_F(LinkedListTests, SetByIndex) {
    LinkedList::UniDirectionalNonCircular<t_uint32> list;
    list.prepend(ZERO);
    list.prepend(ONE);
    EXPECT_TRUE( list.setByIndex(ZERO, TWO) );
    EXPECT_TRUE( list.setByIndex(ONE, ONE) );

    EXPECT_EQ( TWO, list.getByIndex(ZERO) );
    EXPECT_EQ( ONE, list.getByIndex(ONE) );
}

TEST_F(LinkedListTests, InsertByIndex) {
    LinkedList::UniDirectionalNonCircular<t_uint32> list;
    EXPECT_TRUE( list.insertAtIndex(ZERO, TWO) );
    EXPECT_EQ( ONE, list.getSize() );
    EXPECT_TRUE( list.setByIndex(ZERO, TWO) );

    // still insert at the beginning
    EXPECT_TRUE( list.insertAtIndex(ZERO, ONE) );
    EXPECT_EQ( TWO, list.getSize() );
    EXPECT_EQ( ONE, list.getByIndex(ZERO) );
    EXPECT_EQ( TWO, list.getByIndex(ONE) );

    // insert at the end
    constexpr t_uint32 THREE = { 3 };
    EXPECT_TRUE( list.insertAtIndex(TWO, ZERO) );
    EXPECT_EQ( THREE, list.getSize() );
    EXPECT_EQ( ONE, list.getByIndex(ZERO) );
    EXPECT_EQ( TWO, list.getByIndex(ONE) );
    EXPECT_EQ( ZERO, list.getByIndex(TWO) );

    constexpr t_uint32 FOUR = { 4 };
    EXPECT_TRUE( list.insertAtIndex(ONE, THREE) );
    EXPECT_EQ( FOUR, list.getSize() );
    EXPECT_EQ( ONE, list.getByIndex(ZERO) );
    EXPECT_EQ( THREE, list.getByIndex(ONE) );
    EXPECT_EQ( TWO, list.getByIndex(TWO) );
    EXPECT_EQ( ZERO, list.getByIndex(THREE) );
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
//    LinkedList::UniDirectionalNonCircular<t_uint32> list;
//    list.prepend( ZERO );
//    return 0;
}
