#include "stack.h"

#include <assert.h>
#include <stdlib.h>

struct stack stack = {
  Stack__create,
  Stack__push,
  Stack__pop,
  Stack__pop_all,
  Stack__delete,
  Stack__size
};

Stack *Stack__create(void) {
  Stack *tmp = (Stack *) malloc(sizeof(Stack));
  if (tmp != NULL) {
    tmp->size = 0;
    tmp->stack = NULL;
  }
  return tmp;
}

void Stack__push(Stack *stack, void *p) {
  assert(stack != NULL);
  struct __stack_node *tmp = (struct __stack_node *) malloc (sizeof(struct __stack_node));
  tmp->value = p;
  tmp->next = stack->stack;
  stack->stack = tmp;
  stack->size++;
}


/*
* If NULL is returned, the stack is empty
*/
void *Stack__pop(Stack *stack) {
  assert(stack != NULL);
  struct __stack_node *tmp = stack->stack;
  if (tmp != NULL) {
    void *auxiliar = tmp->value;
    stack->stack = tmp->next;
    stack->size--;
    free(tmp);
    return auxiliar;
  }
  return NULL;
}

void Stack__pop_all(Stack *stack) {
  assert(stack != NULL);
  struct __stack_node *tmp = stack->stack;
  while (tmp != NULL) {
    struct __stack_node *tmp2 = tmp;
    free(tmp->value);
    tmp = tmp2->next;
    free(tmp2);
  }
  stack->size = 0;
}


Stack *Stack__delete(Stack *stack) {
  assert(stack != NULL);
  Stack__pop_all(stack);
  free(stack);
  return NULL;
}

uint64_t Stack__size(Stack *stack) {
  return stack->size;
}
