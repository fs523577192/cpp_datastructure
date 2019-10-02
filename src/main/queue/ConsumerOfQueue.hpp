#ifndef H_ConsumerOfQueue
#define H_ConsumerOfQueue

#include "../common.hpp"

namespace NS_DataStructure {

    template<typename E> M_declare_interface(ConsumerOfQueue)

        /**
         * Consume (take away) the element in the queue that is added earliest
         *
         * If the queue is a blocking queue, this method will block the current thread and wait until someone provide an element to the queue.
         *
         * @return the element in the queue that is added earliest
         * @throws NoSuchElementException if the queue is empty and the queue is not a blocking queue
         */
        M_interface_method E consume() M_end_interface_method

        /**
         * @return the element in the queue that is added earliest
         * @throws NoSuchElementException if the queue is empty
         */
        M_interface_method E getFirst(E element) M_end_interface_method

        /**
         * @return the element in the queue that is added latest
         * @throws NoSuchElementException if the queue is empty
         */
        M_interface_method E getLast() M_end_interface_method

    M_end_interface
};

#endif // H_ConsumerOfQueue
