#ifndef NODE_H
#define NODE_H

typedef struct data {
    int key;
    char value;
} Data;

typedef struct node {
    Data data;
    struct node* next;
} Node;

/**
 * function: new_node
 * Return a linked list node 
 * @param key, new node key
 * @param value, new node value
 * return: a linked list node
 */
Node *new_node(int key, char value);

#endif