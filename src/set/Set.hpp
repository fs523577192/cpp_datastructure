#ifndef H_Set
#define H_Set

#include "../Collection.hpp"

/**
 * A kind of Collection in which any two elements are not equivalent
 */
namespace NS_DataStructure {

    template<typename E> M_declare_interface_with_base(Set, Collection<E>)

    M_end_interface
};

#endif // H_Set
