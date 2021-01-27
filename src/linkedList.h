#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

typedef struct linked_list
{
    Node* head;
    Node* tail;
    long int length;
} LinkedList;

//Prototypes
LinkedList* newList();
Node* newNode(int key, char value);

void pushAtBegin(LinkedList** list, Node* new_node);
void pushAtEnd(LinkedList** list, Node* new_node);
void popAtBegin(LinkedList** list);
void popAtEnd(LinkedList** list);

void print(LinkedList* list);
void deleteList(LinkedList** list);
#endif