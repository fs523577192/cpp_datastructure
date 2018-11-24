#ifndef H_MutableList
#define H_MutableList

#include "List.hpp"

namespace NS_DataStructure {

    template<typename E> M_declare_interface_with_base(MutableList, List<E>)

        M_interface_method void set(t_int32 index, E element) M_end_interface_method

        /**
         * Insert the element at the specified index
         * The index of the inserted element will be the input parameter "index"
         * @param index where the element will be inserted
         * @param element the element to be inserted
         */
        M_interface_method void insert(t_int32 index, E element) M_end_interface_method

        /**
         * default implementation
         */
        public: void insertAll(t_int32 index, Iterable<E> iterable) {
            for (Iterator<E> iterator = iterable.iterator(); iterator.hasNext(); index += 1) {
                insert(index, iterator.next());
            }
        }

        /**
         * Append the element to the tail of the list (after the last element in the list)
         * @param element the element to be appended
         */
        M_interface_method void append(E element) M_end_interface_method

        /**
         * default implementation
         */
        public: void appendAll(Iterable<E> iterable) {
            for (Iterator<E> iterator = iterable.iterator(); iterator.hasNext(); ) {
                append(iterator.next());
            }
        }

        M_interface_method void remove(t_int32 index) M_end_interface_method

        /**
         * default implementation
         */
        public: void removeRange(t_int32 beginIndex, t_int32 endIndex) {
            for (t_int32 index = endIndex - 1; index >= beginIndex; index -= 1) {
                remove(index);
            }
        }

    M_end_interface
};

#endif // H_MutableList
