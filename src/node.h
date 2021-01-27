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

#endif