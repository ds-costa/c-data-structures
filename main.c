#include <stdio.h>
#include "src/array.h"
#include "src/strings.h"
#include "src/linkedList.h"

int main() {
    LinkedList* list = newList();
    print(list);
    pushAtBegin(&list, newNode(1, 'a'));
    pushAtBegin(&list, newNode(2, 'b'));
    pushAtBegin(&list, newNode(3, 'c'));
    print(list);
    popAtEnd(&list);
    print(list);
    pushAtBegin(&list, newNode(26, 'z'));
    pushAtBegin(&list, newNode(25, 'y'));
    print(list);
    popAtBegin(&list);
    print(list);
    popAtEnd(&list);
    return 0;
}


