#include <stdio.h>
#include "src/array.h"
#include "src/strings.h"
#include "src/linkedList.h"
#include "src/sort.h"

int main() {

    int arr[] = {
        123,76, 0, 3, 10, 434, 22, -1, 4, 99, 1, 12408, -12
    };

    float arr2[] = {
        123,76, 0, 3, 10, 434, 22, -1, 4, 99, 1, 12408, -12
    };
    
    double arr3[] = {
        123.333,76, 0, 3, 10, 434, 22, -1, 4, 99, 1, 12408, -12
    };

    array_print_int(12, arr);
    array_print_float(12, arr2);
    array_print_double(12, arr3);

    return 0;
}


