#include <iostream>
#include <gtest/gtest.h>
#include "../main/list/ArrayList.cpp"
#include "../main/list/LinkedList.cpp"

constexpr t_uint32 ZERO = { 0 };
constexpr t_uint32 ONE = { 1 };
constexpr t_uint32 TWO = { 2 };

namespace NS_DataStructure {

    template<class T> List<t_uint32>* createList();
    template<> List<t_uint32>* createList<ArrayList<t_uint32>>() {
        return new ArrayList<t_uint32>();
    }
    template<> List<t_uint32>* createList<LinkedList::UniDirectionalNonCircular<t_uint32>>() {
        return new LinkedList::UniDirectionalNonCircular<t_uint32>();
    }

    template<class T>
    class ListTests : public testing::Test {
      protected:
        List<t_uint32>* p_list;

        ListTests() : p_list(createList<T>()) {}
        ~ListTests() override {
            delete this->p_list;
        }
    };

    typedef testing::Types<ArrayList<t_uint32>, LinkedList::UniDirectionalNonCircular<t_uint32>> Implementations;

    TYPED_TEST_SUITE(ListTests, Implementations);

    TYPED_TEST(ListTests, EmptyList) {
        EXPECT_EQ( ZERO, this->p_list->size() );
    }

    TYPED_TEST(ListTests, InsertByIndex) {
        EXPECT_TRUE( this->p_list->add(ZERO, TWO) );
        EXPECT_EQ( ONE, this->p_list->size() );
        EXPECT_TRUE( this->p_list->set(ZERO, TWO) );

        // still insert at the beginning
        EXPECT_TRUE( this->p_list->add(ZERO, ONE) );
        EXPECT_EQ( TWO, this->p_list->size() );
        EXPECT_EQ( ONE, this->p_list->get(ZERO) );
        EXPECT_EQ( TWO, this->p_list->get(ONE) );

        // insert at the end
        constexpr t_uint32 THREE = { 3 };
        EXPECT_TRUE( this->p_list->add(TWO, ZERO) );
        EXPECT_EQ( THREE, this->p_list->size() );
        EXPECT_EQ( ONE, this->p_list->get(ZERO) );
        EXPECT_EQ( TWO, this->p_list->get(ONE) );
        EXPECT_EQ( ZERO, this->p_list->get(TWO) );

        constexpr t_uint32 FOUR = { 4 };
        EXPECT_TRUE( this->p_list->add(ONE, THREE) );
        EXPECT_EQ( FOUR, this->p_list->size() );
        EXPECT_EQ( ONE, this->p_list->get(ZERO) );
        EXPECT_EQ( THREE, this->p_list->get(ONE) );
        EXPECT_EQ( TWO, this->p_list->get(TWO) );
        EXPECT_EQ( ZERO, this->p_list->get(THREE) );
    }

    TYPED_TEST(ListTests, SetByIndex) {
        this->p_list->add(ZERO, ZERO);
        this->p_list->add(ZERO, ONE);
        EXPECT_TRUE( this->p_list->set(ZERO, TWO) );
        EXPECT_TRUE( this->p_list->set(ONE, ONE) );

        EXPECT_EQ( TWO, this->p_list->get(ZERO) );
        EXPECT_EQ( ONE, this->p_list->get(ONE) );
    }

    class LinkedListTests : public testing::Test {
      protected:
        LinkedList::UniDirectionalNonCircular<t_uint32>* getList() {
            return new LinkedList::UniDirectionalNonCircular<t_uint32>();
        }
    };

    TEST_F(LinkedListTests, Prepend) {
        LinkedList::UniDirectionalNonCircular<t_uint32>* p_list = this->getList();
        EXPECT_TRUE( p_list->prepend(ZERO) );
        EXPECT_EQ( ONE, p_list->size() );

        EXPECT_TRUE( p_list->prepend(ONE) );
        EXPECT_EQ( TWO, p_list->size() );

        EXPECT_EQ( ONE, p_list->get(ZERO) );
        EXPECT_EQ( ZERO, p_list->get(ONE) );
    }

    TEST_F(LinkedListTests, Append) {
        LinkedList::UniDirectionalNonCircular<t_uint32>* p_list = this->getList();
        EXPECT_TRUE( p_list->append(ZERO) );
        EXPECT_EQ( ONE, p_list->size() );

        EXPECT_TRUE( p_list->append(ONE) );
        EXPECT_EQ( TWO, p_list->size() );

        EXPECT_EQ( ZERO, p_list->get(ZERO) );
        EXPECT_EQ( ONE, p_list->get(ONE) );
    }

}; // namespace NS_DataStructure

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
