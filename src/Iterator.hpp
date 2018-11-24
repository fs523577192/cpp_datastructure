#ifndef H_Iterator
#define H_Iterator

#include "common.hpp"

namespace NS_DataStructure {

    template<typename E> M_declare_interface(Iterator)

        M_interface_method boolean hasNext() M_end_interface_method

        M_interface_method E next() M_end_interface_method

    M_end_interface
};

#endif // H_Iterator
