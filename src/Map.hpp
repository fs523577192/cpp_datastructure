#ifndef H_Map
#define H_Map

#include "Set.hpp"

namespace NS_DataStructure {

    template<typename K, typename V> M_declare_interface(Map)

        public:
            M_declare_interface(Entry)

                M_interface_method K getKey() M_end_interface_method

                M_interface_method V getValue() M_end_interface_method

            M_end_interface

        M_interface_method t_uint32 size() M_end_interface_method

        /**
         * default implementation
         * @return true  if the collection is empty
         *         false if the collection contains at least one element
         */
        public; t_boolean isEmpty() {
            return size() <= 0;
        }

        M_interface_method t_boolean containsKey(K key) M_end_interface_method

        M_interface_method V get(K key) M_end_interface_method

        M_interface_method Set<K> keySet() M_end_interface_method

        M_interface_method Set<Entry<K, V>> entrySet() M_end_interface_method

    M_end_interface
};

#endif // H_Map
