#ifndef stack_t_H
#define stack_t_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef int EntryType; // You can define your own entry type

typedef struct _stack_t stack_t;

/**
 * @brief Init a stack
 * 
 * @param total_capacity 
 * @return stack_t 
 */
stack_t stack_t_init(size_t total_capacity);

/**
 * @brief Push a value
 * 
 * @param stk 
 * @param entry 
 * @return true 
 * @return false 
 */
bool stack_t_push(stack_t *stk, EntryType entry);

/**
 * @brief Pop a value
 * 
 * @param stk 
 * @return true 
 * @return false 
 */
bool stack_t_pop(stack_t *stk);

/**
 * @brief Peek a value
 * 
 * @param stk 
 * @return EntryType 
 */
EntryType stack_t_peek(stack_t *stk);

/**
 * @brief Check if the stack is empty
 * 
 * @param stk 
 * @return true 
 * @return false 
 */
bool stack_t_is_empty(stack_t *stk);


/**
 * @brief Print the stack
 * 
 * @param stk 
 */
void stack_t_print(stack_t *stk);

/**
 * @brief Get the stack count
 * 
 * @param stk 
 * @return size_t 
 */
size_t stack_t_get_count(stack_t *stk);


#ifdef STACK_IMPLEMENTATION_H

typedef struct _stack_t {
    size_t top; // current stack_t top element index
    size_t capacity; // total capacity
    EntryType *entries;    
} stack_t;

stack_t stack_init(size_t total_capacity) {
    return (stack_t) {
        .top = -1,
        .capacity = total_capacity,
        .entries = malloc(sizeof(stack_t) * total_capacity)
    };    
}

bool stack_push(stack_t *stk, EntryType entry) {
    if(stk->top + 1 == stk->capacity) {
        return false;
    }
    stk->entries[++stk->top] = entry;
    return true; 
}

bool stack_is_empty(stack_t *stk) {
    return stk->top == -1;
}

bool stack_pop(stack_t *stk) {
	if(stack_is_empty(stk)) {
        return false;
    }
    stk->top--;
    return true;
}

EntryType stack_peek(stack_t *stk) {
    if(stack_is_empty(stk)) {
        return INT32_MIN;
    }
    return stk->entries[stk->top];
}

void stack_print(stack_t *stk) {

    if(stack_is_empty(stk)) {
        return;
    }

    for(size_t i = stk->top; i < -1; i--) {
        printf("[%d]\n", stk->entries[i]);
    }
    printf("stk max size: %ld, top: %d\n", stk->capacity, stk->entries[stk->top]);
    return;
}

size_t stack_get_count(stack_t *stk) {
    return stk->top + 1;
}

#endif
#endif
