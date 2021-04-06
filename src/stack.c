#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "stack.h"

void stack_push(Stack **stack_ptr, Node *new_node) {
	if(!(*stack_ptr)) {
		(*stack_ptr) = new_node;
	}
	else {
		new_node->next = (*stack_ptr);
		(*stack_ptr) = new_node;  
	}
}

void stack_pop(Stack **stack_ptr) {
	Stack *aux = *stack_ptr;
	(*stack_ptr) = (*stack_ptr)->next;
	free(aux);
}

Stack *stack_peek(Stack *stack_ptr) {
	printf("\nStack(Top): [%d : %c]\n", stack_ptr->data.key, stack_ptr->data.value);
	return stack_ptr;
}

void stack_print(Stack *stack_ptr) {
	Stack *aux = stack_ptr;
	printf("stack: [%d : %c] <- ", aux->data.key, aux->data.value);
	aux = aux->next;
	while(aux) {
		printf("[%d : %c] <- ", aux->data.key, aux->data.value);
		aux = aux->next;
	} printf(" NULL\n");
}