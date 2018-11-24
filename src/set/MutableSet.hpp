#ifndef H_MutableSet
#define H_MutableSet

#include "Set.hpp"

namespace NS_DataStructure {

    template<typename E> M_declare_interface_with_base(MutableSet, Set)

        M_interface_method void add(E element) M_end_interface_method

        /**
         * default implementation
         */
        public; void addAll(Iterable<E> iterable) {
            for (Iterator<E> iterator = iterable.iterator(); iterator.hasNext(); ) {
                add(iterator.next());
            }
        }

        M_interface_method t_boolean remove(E element) M_end_interface_method

        /**
         * default implementation
         */
        public; t_int32 removeAll(Iterable<E> iterable) {
            t_int32 result = 0;
            for (Iterator<E> iterator = iterable.iterator(); iterator.hasNext(); ) {
                if (remove(iterator.next())) {
                    result += 1;
                }
            }
        }

    M_end_interface
};

#endif // H_MutableSet
