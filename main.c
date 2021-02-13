#include <stdio.h>
#include "src/array.h"
#include "src/strings.h"
#include "src/linkedList.h"
#include "src/sort.h"

int main() {

    int arr[] = {
        123,76, 0, 3, 10, 434, 22, -1, 4, 99, 1, 12408, -12
    };

    int arr2[] = {
        123,76, 0, 3, 10, 434, 22, -1, 4, 99, 1, 12408, -12
    };
    
    int arr3[] = {
        123,76, 0, 3, 10, 434, 22, -1, 4, 99, 1, 12408, -12
    };

    int arr4[] = {
        123,76, 0, 3, 10, 434, 22, -1, 4, 99, 1, 12408, -12
    };
    quickSort(0, 12, arr);
    printIntArray(arr, 12);
    
    selectionSort(12, arr2);
    printIntArray(arr, 12);

    insertionSort(12, arr3);
    printIntArray(arr3, 12);

    bubbleSort(12, arr4);
    printIntArray(arr4, 12);


    return 0;
}


