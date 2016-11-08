#ifndef __STACK_H__
#define __STACK_H__

#include <stdint.h>

struct __stack_node {
  void *value;
  struct __stack_node *next;
};

typedef struct __stack {
  uint64_t size;
  struct __stack_node *stack;
} Stack;

struct stack {
  Stack *(* create)(void);
  void (* push)(Stack *, void *);
  void *(* pop)(Stack *);
  void (* pop_all)(Stack *);
  Stack *(* delete)(Stack *);
  uint64_t (* size)(Stack *);
};

extern struct stack stack;

Stack *Stack__create(void);
void Stack__push(Stack *, void *);
void *Stack__pop(Stack *);
void Stack__pop_all(Stack *);
Stack *Stack__delete(Stack *);
uint64_t Stack__size(Stack *);


#endif // __STACK_H__
