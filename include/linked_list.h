#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdint.h>
#include <stdbool.h>

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
  void (* destroy)(LinkedList *, void *, bool (*)(void *, void *));
  void (* destroy_all)(LinkedList *);
  void (* add)(LinkedList *, void *);
  LinkedList *(* delete)(LinkedList *);
  uint64_t (* size)(LinkedList *);
  void *(* find)(LinkedList *, void *, bool (*)(void *, void *));
};

extern struct linked_list linked_list;

LinkedList *LinkedList__create(void);
void LinkedList__destroy(LinkedList *, void *, bool (*)(void *, void *));
void LinkedList__destroy_all(LinkedList *);
void LinkedList__add(LinkedList *, void *);
LinkedList *LinkedList__delete(LinkedList *);
void LinkedList__iterator(LinkedList *);
void *LinkedList__getNext(LinkedList *);
void *LinkedList__find(LinkedList *, void *, bool (*)(void *, void *));
uint64_t LinkedList__size(LinkedList *);
struct __ll_node * __destroy_node(struct __ll_node *);

#endif // __LINKED_LIST_H__
