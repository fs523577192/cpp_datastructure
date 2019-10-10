#ifndef H_mergeSort
#define H_mergeSort

// #include <iostream>

#include "../swap.hpp"

template<typename T> void mergeSort(T array[], unsigned beginIndex, unsigned endIndex) {
    // Average/Worst Time: O(n log(n))
    // Average/Worst Space: O(log(n))
    // Stable
    if (beginIndex >= endIndex) {
        return;
    }
    
    unsigned indexOfMiddle = (beginIndex + endIndex) / 2;
    unsigned indexDiff = endIndex - beginIndex, indexOfMiddleDiff = indexOfMiddle - beginIndex;
    // std::cout << "indexOfMiddle: " << indexOfMiddle << std::endl; // For debug
    mergeSort(array, beginIndex, indexOfMiddle);
    mergeSort(array, indexOfMiddle + 1, endIndex);
    
    unsigned i, j, k;
    // Backup entries whose index is from beginIndex to endIndex
    T* temp = new T[indexDiff + 1];
    for (i = 0, j = beginIndex;  j <= endIndex;  i += 1, j += 1) {
        temp[i] = array[j];
    }
    // Merge two lists (array[beginIndex..indexOfMiddle] == temp[0..indexOfMiddleDiff] and
    // array[indexOfMiddle+1..endIndex] == temp[indexOfMiddleDiff+1..indexDiff])
    for (i = 0, j = indexOfMiddleDiff + 1, k = beginIndex;  i <= indexOfMiddleDiff && j <= indexDiff && k <= endIndex;  k += 1) {
        if (temp[i] <= temp[j]) {
            array[k] = temp[i];
            i += 1;
        } else {
            // temp[i] > temp[j]
            array[k] = temp[j];
            j += 1;
        }
    }
    for (;  i <= indexOfMiddleDiff && k <= endIndex;  i += 1, k += 1) {
        array[k] = temp[i];
    }
    for (;  j <= indexDiff && k <= endIndex;  j += 1, k += 1) {
        array[k] = temp[j];
    }
    // The two lists are merged now
    delete[] temp;
}

#endif // H_mergeSort