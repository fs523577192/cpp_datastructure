#include "Iterable.hpp"

#ifndef H_Collection
#define H_Collection

namespace NS_DataStructure {

    template<typename E> M_declare_interface_with_base(Collection, Iterable)

        M_interface_method t_uint32 size() M_end_interface_method

        M_interface_method t_boolean contains(E element) M_end_interface_method

    M_end_interface
};

#endif // H_Collection
