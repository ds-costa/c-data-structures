#include <stdio.h>
#include "src/array.h"
#include "src/strings.h"

int main() {
    char words[][10] = {
        "tenet\0",
        "bird\0",
        "radar\0",
        "level\0"
    };

    for(int i = 0; i < 4; i++) {
        printf("%s %s a Palindrome\n", words[i], (palindrome(words[i]) == 1) ? "is" : "not is");
    }
    return 0;
}


