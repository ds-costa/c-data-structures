#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "linkedList.h"

/**
 * function: new_linked_list
 * Returns a new linked list
 * return: a new linked list
 */
LinkedList *new_linked_list()
{
    LinkedList *new_list = malloc(sizeof(LinkedList *));
    new_list->head = new_list->tail = NULL;
    new_list->length = 0;
    return new_list;
}

/**
 * function: list_prepend
 * Inserts a node at the beginning of the list
 * @param list, linked list reference
 * @param new_node, the node that will be added to the list
 */
void list_prepend(LinkedList **list, Node *new_node) 
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

/**
 * function: list_append
 * Inserts a node at the end of the list
 * @param list, linked list reference
 * @param new_node, the node that will be added to the list
 */
void list_append(LinkedList **list, Node *new_node) 
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

/**
 * function: list_remove_begin
 * Removes a node from the beginning of the list
 * @param list, linked list reference
 */
void list_remove_begin(LinkedList **list)
{
    Node* begin = (*list)->head;
    if(begin)
    {
        (*list)->head = (*list)->head->next;
        free(begin);
        (*list)->length--;
    }
}

/**
 * function: list_remove_end
 * Removes a node from the end of the list 
 * @param list, linked list reference
 */
void list_remove_end(LinkedList **list)
{
    Node* current = (*list)->head;
    Node* end = (*list)->tail;

    if(current)
    {
        while (current->next->next)
        {
            current = current->next;
        } 
        current->next = NULL;
        free(end);
        (*list)->length--;
    }
}

/**
 * function: list_print
 *  Shows the contents of the linked list in the stdout
 * @param list, linked list
 */
void list_print(LinkedList  *list) 
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

/**
 * function: list_delete
 * Delete a list 
 * @param list, linked list reference
 */
void list_delete(LinkedList **list) 
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
}