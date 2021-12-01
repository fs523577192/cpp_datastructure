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
    list.prepend( ZERO );
    EXPECT_EQ( ONE, list.getSize() );

    list.prepend( ONE );
    EXPECT_EQ( TWO, list.getSize() );
}

TEST_F(LinkedListTests, Append) {
    LinkedList::UniDirectionalNonCircular<t_uint32> list;
    list.append( ZERO );
    EXPECT_EQ( ONE, list.getSize() );

    list.append( ONE );
    EXPECT_EQ( TWO, list.getSize() );
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
//    LinkedList::UniDirectionalNonCircular<t_uint32> list;
//    list.prepend( ZERO );
//    return 0;
}
