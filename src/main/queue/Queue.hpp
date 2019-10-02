#ifndef H_Queue
#define H_Queue

#include "../common.hpp"

namespace NS_DataStructure {

    template<typename E> M_declare_interface_with_base_2(Queue, ProvideOfQueue<E>, ConsumerOfQueue<E>)

    M_end_interface
};

#endif // H_Queue
