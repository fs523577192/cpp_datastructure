#include <iostream>
#include <gtest/gtest.h>
#include "../main/Exception.cpp"

class ExceptionTests : public testing::Test {
  protected:
    NS_Utility::Exception  exception0;
};

TEST_F(ExceptionTests, DefaultConstructor) {
    EXPECT_FALSE( (bool) exception0.message );
    EXPECT_EQ( & exception0, exception0.cause );
}
TEST_F(ExceptionTests, MessageConstructor) {
    NS_Utility::Exception  exception1( std::shared_ptr<std::string>(new std::string("test message")) );
    EXPECT_EQ( 0, (*exception1.message).compare("test message") );
    EXPECT_EQ( & exception1, exception1.cause );

    NS_Utility::Exception  exception3( std::shared_ptr<std::string>(new std::string("test full constructor")), &exception1 );
    EXPECT_EQ( 0, (*exception3.message).compare("test full constructor") );
    EXPECT_EQ( & exception1, exception3.cause );
}
TEST_F(ExceptionTests, CauseConstructor) {
    NS_Utility::Exception  exception2(&exception0);
    EXPECT_FALSE( (bool) exception2.message );
    EXPECT_EQ( & exception0, exception2.cause );
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
