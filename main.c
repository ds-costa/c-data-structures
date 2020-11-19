#include <stdio.h>
#include "src/array.h"
#include "src/strings.h"

int main() {
    char words[][25] = {
        "tenet\0",
        "bird\0",
        "radar\0",
        "level\0",
        "pop\0",
        "deed\0",
        "kayak\0",
        "civic\0",
        "radar\0",
        "level\0",
        "deified\0",
        "rotator\0",
        "repaper\0",
        "testset\0",
        "racecar\0",
        "redivider\0"
    };

    for(int i = 0; i < 16; i++) {
        printf("%s %s a Palindrome\n", words[i], (palindrome(words[i]) == 1) ? "is" : "not is");
    }
    return 0;
}


