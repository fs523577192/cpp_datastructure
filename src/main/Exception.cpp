#ifndef H_Exception
#define H_Exception

#include "common.hpp"

namespace NS_Utility {

    class Exception {
        public: const String message;
        public: const Exception* cause;

        public: Exception(): message() {
            this->cause = this;
        }

        public: Exception(Exception* cause): message() {
            this->cause = cause;
        }

        public: Exception(String message): message(message) {
            this->cause = this;
        }

        public: Exception(String message, Exception* cause): message(message) {
            this->cause = cause;
        }

        public: ~Exception() {
            this->cause = nullptr;
        }
    };
};

#endif // H_Exception
