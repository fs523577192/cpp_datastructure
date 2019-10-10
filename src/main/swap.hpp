#ifndef H_swap
#define H_swap

template<typename T> inline void swap(T& a, T& b) {
    T temp = b;
    b = a;
    a = temp;
}

#endif // H_swap