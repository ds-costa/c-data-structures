#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "linkedList.h"

LinkedList* newList()
{
    LinkedList* new_list = malloc(sizeof(LinkedList *));
    new_list->head = new_list->tail = NULL;
    new_list->length = 0;
    return new_list;
}

Node* newNode(int key, char value)
{
    Node* new_node = (Node *) malloc(sizeof(Node));
    new_node->data.key = key;
    new_node->data.value = value;
    new_node->next = NULL;
    return new_node;
}

void pushAtBegin(LinkedList** list, Node* new_node) 
{
    if((*list)->head == NULL) 
    {
        (*list)->head = (*list)->tail = new_node;
    }
    else
    {
        new_node->next = (*list)->head;
        (*list)->head = new_node;        
    }
    (*list)->length++;
}

void pushAtEnd(LinkedList** list, Node* new_node) 
{
    if((*list)->tail == NULL) 
    {
        (*list)->tail = (*list)->head = new_node;
    }
    else
    {
        (*list)->tail->next = new_node;
        (*list)->tail = new_node;
    }
    (*list)->length++;
}

void popAtBegin(LinkedList** list)
{
    Node* begin = (*list)->head;
    if(begin)
    {
        (*list)->head = (*list)->head->next;
        free(begin);
        (*list)->length--;
    }
}

void popAtEnd(LinkedList** list)
{
    Node* current = (*list)->head;
    Node* end = (*list)->tail;

    if(current)
    {
        while (current->next->next)
        {
            current = current->next;
        } 
        //printf("\n[%d :: %c]\n", current->data.key, current->data.value);
        //printf("\n[%d :: %c]\n", end->data.key, end->data.value);
        current->next = NULL;
        free(end);
        (*list)->length--;
    }
}

void print(LinkedList* list) 
{
    Node* current = list->head;
    
    printf("List(len = %ld)\n", list->length);
    while(current)
    {
        printf("[%i : %c] -> ", current->data.key, current->data.value);
        current = current->next;
    } 
    printf("[NULL]\n");
}

void deleteList(LinkedList** list) 
{
    Node* current = (*list)->head;
    Node* next;

    while(current) 
    {
        next = current->next;
        free(current);
        current = next;
    }

    (*list)->head = (*list)->tail = NULL;
    (*list)->length = 0;
    //free(*list);
}

