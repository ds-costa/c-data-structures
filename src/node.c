#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/**
 * function: new_node
 * Return a linked list node 
 * @param key, new node key
 * @param value, new node value
 * return: a linked list node
 */
Node *new_node(int key, char value)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data.key = key;
    new_node->data.value = value;
    new_node->next = NULL;
    return new_node;
}