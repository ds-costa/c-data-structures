#include <stdio.h>
// #include "src/array.h"
// #include "src/strings.h"
// #include "src/linkedList.h"
// #include "src/sort.h"

#define ARRAY_IMPLEMENTATION_H
#include "src/array.h"


int main() {

    int arr[] = {
        123,76, 0, 3, 10, 434, 22, -1, 4, 99, 1, 12408, -12
    };

    float arr2[] = {
        123,76, 0, 3, 10, 434, 22, -1, 4, 99, 1, 12408, -12
    };
    
    double arr3[] = {
        122.333,76, 0, 3, 10, 434, 22, -1, 4, 99, 1, 12408, -12
    };

    arr_print(12, arr);

    return 0;
}


