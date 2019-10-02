#ifndef H_ProviderOfQueue
#define H_ProviderOfQueue

#include "../common.hpp"

namespace NS_DataStructure {

    template<typename E> M_declare_interface(ProviderOfQueue)

        /**
         * Provide an element to the queue
         * @param element  the element to be added to the queue
         */
        M_interface_method void provide(E element) M_end_interface_method

    M_end_interface
};

#endif // H_ProviderOfQueue
