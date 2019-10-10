#ifndef H_bubbleSort
#define H_bubbleSort

#include "../swap.hpp"

template<typename T> void bubbleSort(T array[], unsigned beginIndex, unsigned endIndex) {
    // Average/Worst Time: O(n^2)
    // Average/Worst Space: O(1)
    // Stable
    while (endIndex > beginIndex) {
        for (unsigned currentIndex = beginIndex; currentIndex < endIndex; currentIndex += 1) {
            if (array[currentIndex] > array[currentIndex+1]) {
                swap(array[currentIndex], array[currentIndex+1]);
            }
        }
        // Now array[endIndex] is the greatest
        endIndex -= 1;
    }
}

#endif // H_bubbleSort