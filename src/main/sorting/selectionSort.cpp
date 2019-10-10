#ifndef H_selectionSort
#define H_selectionSort

#include "../swap.hpp"

template<typename T> void selectionSort(T array[], unsigned beginIndex, unsigned endIndex) {
    // Average/Worst Time: O(n^2)
    // Average/Worst Space: O(1)
    // Not Stable
    while (endIndex > beginIndex) {
        unsigned indexOfMax = endIndex;
        for (unsigned currentIndex = beginIndex; currentIndex < endIndex; currentIndex += 1) {
            if (array[currentIndex] > array[indexOfMax]) {
                indexOfMax = currentIndex;
            }
        }
        if (indexOfMax < endIndex) {
            swap(array[endIndex], array[indexOfMax]);
        }
        // Now array[endIndex] is the greatest
        endIndex -= 1;
    }
}

#endif // H_selectionSort