#ifndef H_Collection
#define H_Collection

#include "Iterable.hpp"

namespace NS_DataStructure {

    template<typename E> M_declare_interface_with_base(Collection, Iterable<E>)

        M_interface_method t_uint32 size() M_end_interface_method

        /**
         * default implementation
         * @return true  if the collection is empty
         *         false if the collection contains at least one element
         */
        public: virtual t_boolean isEmpty() {
            return size() <= 0;
        }

        /**
         * default implementation
         * @return true  if the collection contains at least one element
         *               that equals to the input element
         *         false otherwise
         */
        public: virtual t_boolean contains(E const element) {
            for (Iterator<E>* p_itr = this->iterator(); p_itr->hasNext(); ) {
                if (p_itr->next() == element) {
                    return true;
                }
            }
            return false;
        }

    M_end_interface
};

#endif // H_Collection
