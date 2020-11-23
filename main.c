#include <stdio.h>
#include "src/array.h"
#include "src/strings.h"

int main() {
    char str[] = "Github is amazing\0";
    printf("Original: %s\n", str);
    stringReverse(str);
    printf("Reversed: %s\n", str);
    return 0;
}


