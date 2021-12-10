#ifndef H_Iterable
#define H_Iterable

#include "Iterator.hpp"

namespace NS_DataStructure {

    template<typename E> M_declare_interface(Iterable)

        M_interface_method Iterator<E>* iterator() M_end_interface_method

    M_end_interface
};

#endif // H_Iterable
