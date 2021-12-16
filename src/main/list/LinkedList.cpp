#ifndef H_LinkedList
#define H_LinkedList

#ifndef H_handleLinkedListIndexOutOfBound
#define H_handleLinkedListIndexOutOfBound(p_list, size, index)  throw "List index out of bounds"
#endif

#include "./List.hpp"

namespace NS_DataStructure {

    class LinkedList {
      protected:
        template<typename E> class LinkedListNode {
          public:
            LinkedListNode<E>* next = nullptr;
            E element;

            LinkedListNode(E const element) {
                this->next = nullptr;
                this->element = element;
            }
            LinkedListNode(E const element, LinkedListNode<E>* const next) {
                this->next = next;
                this->element = element;
            }

            inline LinkedListNode<E>* getNext() {
                return this->next;
            }
            inline void setNext(LinkedListNode<E>* const next) {
                this->next = next;
            }
            inline E getElement() {
                return this->element;
            }
            inline void setElement(E const element) {
                this->element = element;
            }
        };
        template<typename E> class DoublyLinkedListNode : protected LinkedListNode<LinkedListNode<E>> {
          public:
            DoublyLinkedListNode(E const element) : LinkedListNode<LinkedListNode<E>>(LinkedListNode<E>(element)) {}
            DoublyLinkedListNode(E const element, DoublyLinkedListNode<E>* const prev) :
                    LinkedListNode<LinkedListNode<E>>(LinkedListNode<E>(element), static_cast<LinkedListNode<E>* const>(prev)) {}
            DoublyLinkedListNode(E const element, DoublyLinkedListNode<E>* const next, DoublyLinkedListNode<E>* const prev) :
                    LinkedListNode<LinkedListNode<E>>(LinkedListNode<E>(element, static_cast<LinkedListNode<E>* const>(next)),
                            static_cast<LinkedListNode<E>* const>(prev)) {}

            inline DoublyLinkedListNode<E>* getPrev() {
                return reinterpret_cast<DoublyLinkedListNode<E>*>(this->element.next);
            }
            inline void setPrev(DoublyLinkedListNode<E>* const prev) {
                this->element.next = prev;
            }
            inline E getElement() {
                return this->element.element;
            }
            inline void setElement(E const element) {
                this->element.element = element;
            }
        };

        template<typename E> class NonCircularIterator : public Iterator<E> {
          protected:
            LinkedListNode<E> *p_node;
          public:
            NonCircularIterator(LinkedListNode<E> *p_node) {
                this->p_node = p_node;
            }

            t_boolean hasNext() {
                return this->p_node != nullptr;
            }
            E next() {
                E result = this->p_node->getElement();
                this->p_node = this->p_node->getNext();
                return result;
            }
        };

        template<typename E> static inline bool isNonCycularEnd(LinkedListNode<E>* const p_node) {
            return p_node->getNext() == nullptr;
        }
        template<typename E> static inline bool isCycularEnd(LinkedListNode<E>* const p_head, LinkedListNode<E>* const p_node) {
            return p_node->getNext() == p_head;
        }
        template<typename E> static inline bool isCycularEnd(DoublyLinkedListNode<E>* const p_head, DoublyLinkedListNode<E>* const p_node) {
            return p_head->getPrev() == p_node;
        }

        template<typename E> static t_uint32 getSize(LinkedListNode<E>* const p_head) {
            t_uint32 size = { (unsigned long) 0 };
            for (LinkedListNode<E>* temp = p_head; temp != nullptr; temp = temp->getNext()) {
                size = size + 1;
            }
            return size;
        }

        template<typename E> static LinkedListNode<E>* getNonCycularNodeByIndex(
                LinkedListNode<E>* const p_head, t_uint32 const index) {
            LinkedListNode<E>* temp = p_head;
            for (t_uint32 i = index; i > 0; i = i - 1) {
                if (temp == nullptr) {
                    H_handleLinkedListIndexOutOfBound(this, index - i, index);
                }
                temp = temp->getNext();
            }
            if (temp == nullptr) {
                H_handleLinkedListIndexOutOfBound(this, index, index);
            }
            return temp;
        }
        template<typename E> static LinkedListNode<E>* getCycularNodeByIndex(
                LinkedListNode<E>* const p_head, t_uint32 const index) {
            if (index == 0) {
                if (p_head == nullptr) {
                    H_handleLinkedListIndexOutOfBound(this, 0, index);
                }
                return p_head;
            }
            LinkedListNode<E>* temp = p_head;
            for (t_uint32 i = index; i > 1; i = i - 1) {
                if (isCycularEnd(p_head, *temp)) {
                    H_handleLinkedListIndexOutOfBound(this, index - i, index);
                }
                temp = temp->getNext();
            }
            if (isCycularEnd(p_head, *temp)) {
                H_handleLinkedListIndexOutOfBound(this, index, index);
            }
            return temp->getNext();
        }

        template<typename E> static inline LinkedListNode<E>* insertAfter(
                LinkedListNode<E>* const p_nodeInList, LinkedListNode<E>* const p_nodeToInsert) {
            p_nodeToInsert->setNext(p_nodeInList->getNext());
            p_nodeInList->setNext(p_nodeToInsert);
            return p_nodeToInsert;
        }

        template<typename E> static inline DoublyLinkedListNode<E>* insertAfter(
                DoublyLinkedListNode<E>* const p_nodeInList, DoublyLinkedListNode<E>* const p_nodeToInsert) {
            p_nodeToInsert->setPrev(p_nodeInList);
            return static_cast<DoublyLinkedListNode<E>*>( insertAfter(static_cast<LinkedListNode<E>* const>(p_nodeInList),
                    static_cast<LinkedListNode<E>* const>(p_nodeToInsert)) );
        }

      public:
        template<typename E> class UniDirectionalNonCircular : public List<E> {
          protected:
            LinkedListNode<E>* p_head = nullptr;

            inline void prepend(LinkedListNode<E>* const p_nodeToInsert) {
                p_nodeToInsert->setNext(this->p_head);
                this->p_head = p_nodeToInsert;
            }

            void append(LinkedListNode<E>* const p_nodeToInsert) {
                LinkedListNode<E>** pp_node;
                for (pp_node = &(this->p_head); *pp_node != nullptr; pp_node = &((*pp_node)->next));
                *pp_node = p_nodeToInsert;
            }
          public:
            t_uint32 size() {
                return LinkedList::getSize(this->p_head);
            }
            t_boolean isEmpty() {
                return this->p_head == nullptr;
            }
            t_boolean contains(E const element) {
                for (LinkedListNode<E>* p_node = this->p_head; p_node != nullptr; p_node = p_node->getNext()) {
                    if (p_node->getElement() == element) {
                        return true;
                    }
                }
                return false;
            }

            E get(t_uint32 const index) {
                LinkedListNode<E>* p_node = getNonCycularNodeByIndex(this->p_head, index);
                return p_node->getElement();
            }
            t_boolean set(t_uint32 const index, E const element) {
                LinkedListNode<E>* p_node = getNonCycularNodeByIndex(this->p_head, index);
                if (p_node != nullptr) {
                    p_node->setElement(element);
                    return true;
                }
                return false;
            }
            t_boolean add(t_uint32 const index, E const element) {
                constexpr t_uint32 ZERO = { 0 };
                if (index == 0) {
                    return prepend(element);
                }
                LinkedListNode<E>* p_node = getNonCycularNodeByIndex(this->p_head, index - 1);
                if (p_node != nullptr) {
                    insertAfter(p_node, new LinkedListNode<E>(element));
                    return true;
                }
                return false;
            }
            t_boolean prepend(E const element) {
                LinkedListNode<E>* p_node = new LinkedListNode<E>(element);
                prepend(p_node);
                return true;
            }
            t_boolean append(E const element) {
                append(new LinkedListNode<E>(element));
                return true;
            }

            Iterator<E>* iterator() {
                return new NonCircularIterator<E>(this->p_head);
            }
        };
        template<typename E> class BiDirectionalNonCircular : public List<E> {
          protected:
            DoublyLinkedListNode<E>* p_head = nullptr;

            inline void prepend(DoublyLinkedListNode<E>* const p_nodeToInsert) {
                p_nodeToInsert->setNext(this->p_head);
                if (this->p_head != nullptr) {
                    this->p_head->setPrev(p_nodeToInsert);
                }
                this->p_head = p_nodeToInsert;
            }

            void append(DoublyLinkedListNode<E>* const p_nodeToInsert) {
                if (this->p_head == nullptr) {
                    this->p_head = p_nodeToInsert;
                }
                DoublyLinkedListNode<E>* p_node;
                for (p_node = this->p_head; p_node->next != nullptr; p_node = p_node->next);
                p_node->next = p_nodeToInsert;
                p_nodeToInsert->setPrev(p_node);
            }
          public:
            t_uint32 size() {
                return LinkedList::getSize(this->p_head);
            }
            t_boolean isEmpty() {
                return this->p_head == nullptr;
            }
            t_boolean contains(E const element) {
                for (DoublyLinkedListNode<E>* p_node = this->p_head; p_node != nullptr; p_node = p_node->getNext()) {
                    if (p_node->getElement() == element) {
                        return true;
                    }
                }
                return false;
            }

            E get(t_uint32 const index) {
                DoublyLinkedListNode<E>* p_node = getNonCycularNodeByIndex(this->p_head, index);
                return p_node->getElement();
            }
            t_boolean set(t_uint32 const index, E const element) {
                DoublyLinkedListNode<E>* p_node = getNonCycularNodeByIndex(this->p_head, index);
                if (p_node != nullptr) {
                    p_node->setElement(element);
                    return true;
                }
                return false;
            }
            t_boolean add(t_uint32 const index, E const element) {
                constexpr t_uint32 ZERO = { 0 };
                if (index == 0) {
                    return prepend(element);
                }
                DoublyLinkedListNode<E>* p_node = getNonCycularNodeByIndex(this->p_head, index - 1);
                if (p_node != nullptr) {
                    insertAfter(p_node, new DoublyLinkedListNode<E>(element));
                    return true;
                }
                return false;
            }
            t_boolean prepend(E const element) {
                DoublyLinkedListNode<E>* p_node = new DoublyLinkedListNode<E>(element);
                prepend(p_node);
                return true;
            }
            t_boolean append(E const element) {
                append(new DoublyLinkedListNode<E>(element));
                return true;
            }

            Iterator<E>* iterator() {
                return new NonCircularIterator<E>(this->p_head);
            }
        };
    }; // class LinkedList
}; // namespace NS_DataStructure
#endif // ifndef H_LinkedList
