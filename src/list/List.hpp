#ifndef H_List
#define H_List

#include "../Collection.hpp"

namespace NS_DataStructure {

    template<typename E> M_declare_interface_with_base(List, Collection)

        M_interface_method E get(t_int32 index) M_end_interface_method

    M_end_interface
};

#endif // H_List
