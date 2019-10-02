#ifndef H_Stack
#define H_Stack

#include "../common.hpp"

namespace NS_DataStructure {

    template<typename E> M_declare_interface(Stack)

        M_interface_method t_boolean isEmpty() M_end_interface_method

        /**
         * Push an element into the top of the stack
         * @param element  the element to push
         */
        M_interface_method void push(E element) M_end_interface_method

        /**
         * @return the element on the top of the stack
         * @throws NoSuchElementException  if the stack is empty
         */
        M_interface_method E peek() M_end_interface_method

        /**
         * Pop the element on the top out of the stack
         * @return the element on the top of the stack
         * @throws NoSuchElementException  if the stack is empty
         */
        M_interface_method E pop() M_end_interface_method

    M_end_interface
};

#endif // H_Stack
