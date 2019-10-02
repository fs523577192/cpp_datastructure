#include <iostream>
#include "../main/Exception.cpp"

int main() {
    NS_Utility::Exception  exception0;
    if ( exception0.message.get() ) {
        std::cerr << "exception0.message is not null" << std::endl;
        return 1;
    }
    if ( exception0.cause != & exception0 ) {
        std::cerr << "exception0.cause is not &exception0" << std::endl;
        return 1;
    }

    NS_Utility::Exception  exception1( std::shared_ptr<std::string>(new std::string("test message")) );
    if ( (*exception0.message).compare("test message") != 0 ) {
        std::cerr << "exception1.cause is not \"test message\"" << std::endl;
        return 1;
    }
    if ( exception1.cause != & exception1 ) {
        std::cerr << "exception1.cause is not &exception1" << std::endl;
        return 1;
    }

    NS_Utility::Exception  exception2(&exception0);
    if ( exception2.message.get() ) {
        std::cerr << "exception2.message is not null" << std::endl;
        return 1;
    }
    if ( exception2.cause != & exception0 ) {
        std::cerr << "exception2.cause is not &exception0" << std::endl;
        return 1;
    }

    NS_Utility::Exception  exception3( std::shared_ptr<std::string>(new std::string("test full constructor")), &exception1 );
    if ( (*exception3.message).compare("test full constructor") != 0 ) {
        std::cerr << "exception3.message is not null" << std::endl;
        return 1;
    }
    if ( exception3.cause != & exception1 ) {
        std::cerr << "exception3.cause is not &exception1" << std::endl;
        return 1;
    }

    return 0;
}
