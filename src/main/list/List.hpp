#ifndef H_List
#define H_List

#include "../Collection.hpp"

namespace NS_DataStructure {

    template<typename E> M_declare_interface_with_base(List, Collection<E>)

        /**
         *
         */
        M_interface_method E get(t_uint32 const index) M_end_interface_method

        /**
         *
         */
        M_interface_method t_boolean set(t_uint32 const index, E const element) M_end_interface_method

        /**
         *
         */
        M_interface_method t_boolean add(t_uint32 const index, E const element) M_end_interface_method

    M_end_interface
};

#endif // H_List
