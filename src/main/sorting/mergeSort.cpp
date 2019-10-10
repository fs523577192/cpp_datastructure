#ifndef H_mergeSort
#define H_mergeSort

#include "../swap.hpp"

template<typename T> void mergeSort(T array[], unsigned beginIndex, unsigned endIndex) {
    // Average/Worst Time: O(n log(n))
    // Average/Worst Space: O(log(n))
    // Stable
    if (beginIndex >= endIndex) {
        return;
    }
    
    int indexOfMiddle = (beginIndex + endIndex) / 2;
    mergeSort(array, beginIndex, indexOfMiddle);
    mergeSort(array, indexOfMiddle + 1, endIndex);
    
    T temp[] = new T[endIndex - beginIndex + 1];
    int i, j, k;
    for (i = 0, j = beginIndex;  j <= endIndex;  i += 1, j += 1) {
        temp[i] = array[j];
    }
    for (i = 0, j = indexOfMiddle - beginIndex + 1, k = beginIndex;  k <= endIndex;  k += 1) {
        if (temp[i] <= temp[j]) {
            temp[k] = temp[i];
            i += 1;
        } else {
            // temp[i] > temp[j]
            temp[k] = temp[j];
            j += 1;
        }
    }
    delete temp;
}

#endif // H_mergeSort