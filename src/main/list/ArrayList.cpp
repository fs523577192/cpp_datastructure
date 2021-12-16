#ifndef H_ArrayList
#define H_ArrayList

#ifndef H_handleArrayListIndexOutOfBound
#define H_handleArrayListIndexOutOfBound(p_list, size, index) throw "Array index out of bounds"
#endif

#include "./List.hpp"

namespace NS_DataStructure {

    template<typename E> class ArrayList : public List<E> {
      public:
        static constexpr t_uint32 DEFAULT_CAPACITY = {16};
      protected:
        t_uint32 capacity;
        t_uint32 actualSize = {0};
        E* items;

        class ArrayListIterator : public Iterator<E> {
          protected:
            t_uint32 currentIndex = {0};
            t_uint32 actualSize;
            E* items;
          public:
            ArrayListIterator(t_uint32 actualSize, E* items) {
                this->actualSize = actualSize;
                this->items = items;
            }

            t_boolean hasNext() {
                return this->currentIndex < this->actualSize;
            }
            E next() {
                if (this->currentIndex >= this->actualSize) {
                    H_handleArrayListIndexOutOfBound(items, this->actualSize, this->currentIndex);
                }
                E result = this->items[this->currentIndex.value];
                this->currentIndex += 1;
                return result;
            }
        }; // class ArrayListIterator<E>

      public:
        ArrayList(t_uint32 capacity) {
            this->capacity = capacity;
            this->items = capacity.value == 0 ? nullptr : new E[capacity.value];
        }
        ArrayList() : ArrayList(DEFAULT_CAPACITY) {}

        t_uint32 size() {
            return this->actualSize;
        }
        t_boolean isEmpty() {
            return this->actualSize == 0;
        }

        E get(t_uint32 const index) {
            if (index >= this->actualSize) {
                H_handleArrayListIndexOutOfBound(items, this->actualSize, index);
            }
            return this->items[index.value];
        }
        t_boolean set(t_uint32 const index, E element) {
            if (index >= this->actualSize) {
                H_handleArrayListIndexOutOfBound(items, this->actualSize, index);
                return false;
            }
            this->items[index.value] = element;
            return true;
        }

        t_boolean contains(E const element) {
            for (t_uint32 i = {0}; i < this->actualSize; i += 1) {
                if (this->items[i.value] == element) {
                    return true;
                }
            }
            return false;
        }

        t_boolean add(t_uint32 const index, E element) {
            if (index > this->actualSize) {
                H_handleArrayListIndexOutOfBound(items, this->actualSize, index);
                return false;
            }
            if (this->actualSize == this->capacity) {

            }
            for (t_uint32 i = this->actualSize; i > index; i -= 1) {
                this->items[i.value] = this->items[i.value - 1];
            }
            this->items[index.value] = element;
            this->actualSize += 1;
            return true;
        }

        Iterator<E>* iterator() {
            throw new ArrayListIterator(this->actualSize, this->items);
        }
    }; // class ArrayList<E>
}; // namespace NS_DataStructure
#endif // H_ArrayList
