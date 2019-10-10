#include <iostream>
#include <random>

bool doTestSorting( int* array, unsigned arraySize, std::random_device* p_generator,
        std::ostream* p_outputStream, void sortingMethod(int[], unsigned, unsigned) )
{
    int min = 2147483647, max = -2147483648, sum = 0;
        
    for (unsigned j = 0; j < arraySize; j += 1) {
        array[j] = (*p_generator)();
        
        if (array[j] < min) {
            min = array[j];
        }
        if (array[j] > max) {
            max = array[j];
        }
        sum += array[j];
        
        (*p_outputStream) << array[j] << "  ";
    }
    (*p_outputStream) << "\r\n";

    sortingMethod(array, 0, arraySize - 1);

    int resultSum = array[arraySize - 1];
    for (unsigned j = 0; j < arraySize - 1; j += 1) {
        (*p_outputStream) << array[j] << "  ";
        if ( array[j] > array[j + 1] ) {
            (*p_outputStream) << "\r\n" << "Error order" << "\r\n";
            return false;
        }
        
        resultSum += array[j];
    }
    (*p_outputStream) << "\r\n";
    
    if (array[0] != min) {
        (*p_outputStream) << "Expect min is " << min << " but the real min is " << array[0] << "\r\n";
        return false;
    }
    if (array[arraySize - 1] != max) {
        (*p_outputStream) << "Expect max is " << max << " but the real max is " << array[arraySize - 1] << "\r\n";
        return false;
    }
    if (resultSum != sum) {
        (*p_outputStream) << "Expect sum is " << sum << " but the real sum is " << resultSum << "\r\n";
        return false;
    }
    return true;
}

bool testSorting( std::ostream* p_outputStream, void sortingMethod(int[], unsigned, unsigned) )
{
    std::random_device generator;
    std::uniform_int_distribution<unsigned> distribution(1, 1000);

    std::cout << "Entropy of the random device: " << generator.entropy() << std::endl;
    
    for (unsigned i = 0; i < 10; i += 1) {
        unsigned arraySize = distribution(generator);
        std::cout << "Array size: " << arraySize << std::endl;
        int* array = new int[arraySize];
        
        bool result = doTestSorting(array, arraySize, &generator, p_outputStream, sortingMethod);
        delete[] array;
        if (!result) {
            return false;
        }
    }
    return true;
}