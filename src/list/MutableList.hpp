#ifndef H_MutableList
#define H_MutableList

#include "List.hpp"

namespace NS_DataStructure {

    template<typename E> M_declare_interface_with_base(MutableList, List)

        M_interface_method void set(t_int32 index, E element) M_end_interface_method

        /**
         * Insert the element at the specified index
         * The index of the inserted element will be the input parameter "index"
         * @param index where the element will be inserted
         * @param element the element to be inserted
         */
        M_interface_method void insert(t_int32 index, E element) M_end_interface_method

        /**
         * Append the element to the tail of the list (after the last element in the list)
         * @param element the element to be appended
         */
        M_interface_method void append(E element) M_end_interface_method

    M_end_interface
};

#endif // H_MutableList
