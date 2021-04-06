#ifndef STACK_H
#define STACK_H
#include "node.h"

typedef Node Stack;

void stack_push(Stack **stack_ptr, Node *new_node);
void stack_pop(Stack **stack_ptr);
Node* stack_peek(Stack *stack_ptr);
void stack_print(Stack *stack_ptr);


#endif