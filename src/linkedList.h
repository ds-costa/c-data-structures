#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

typedef struct linked_list
{
    Node* head;
    Node* tail;
    long int length;
} LinkedList;

/**
 * function: new_linked_list
 * Returns a new linked list
 * return: a new linked list
 */
LinkedList *new_linked_list();

/**
 * function: new_node
 * Return a linked list node 
 * @param key, new node key
 * @param value, new node value
 * return: a linked list node
 */
Node *new_node(int key, char value);

/**
 * function: list_prepend
 * Inserts a node at the beginning of the list
 * @param list, linked list reference
 * @param new_node, the node that will be added to the list
 */
void list_prepend(LinkedList **list, Node *new_node);

/**
 * function: list_append
 * Inserts a node at the end of the list
 * @param list, linked list reference
 * @param new_node, the node that will be added to the list
 */
void list_append(LinkedList **list, Node *new_node);

/**
 * function: list_remove_begin
 * Removes a node from the beginning of the list
 * @param list, linked list reference
 */
void list_remove_begin(LinkedList **list);

/**
 * function: list_remove_end
 * Removes a node from the end of the list 
 * @param list, linked list reference
 */
void list_remove_end(LinkedList **list);

/**
 * function: list_print
 *  Shows the contents of the linked list in the stdout
 * @param list, linked list
 */
void list_print(LinkedList  *list);

/**
 * function: list_delete
 * Delete a list 
 * @param list, linked list reference
 */
void list_delete(LinkedList **list);
#endif