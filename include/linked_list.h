#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdint.h>

struct __ll_node {
  void *value;
  struct __ll_node *next;
};

typedef struct LinkedList {
  struct __ll_node *first;
  struct __ll_node *last;
  struct __ll_node *list;
  uint64_t size;
} LinkedList;

struct linked_list {
  LinkedList *(* create)(void);
  void (* destroy)(LinkedList *, void *);
  void (* destroy_all)(LinkedList *);
  void (* add)(LinkedList *, void *);
  void (* delete)(LinkedList *);
};

extern struct linked_list linked_list;

LinkedList *LinkedList__create(void);
void LinkedList__destroy(LinkedList *, void *);
void LinkedList__destroy_all(LinkedList *);
void LinkedList__add(LinkedList *, void *);
void LinkedList__delete(LinkedList *);
struct __ll_node * __destroy_node(struct __ll_node *);

#endif // __LINKED_LIST_H__
