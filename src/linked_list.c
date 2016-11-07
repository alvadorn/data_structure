#include "linked_list.h"
#include <stdlib.h>
#include <assert.h>

struct linked_list linked_list = {
  LinkedList__create,
  LinkedList__destroy,
  LinkedList__destroy_all,
  LinkedList__add,
  LinkedList__delete
};

LinkedList *LinkedList__create(void) {
  LinkedList *tmp = (LinkedList *) malloc(sizeof(LinkedList *));
  tmp->size = 0;
  tmp->first = NULL;
  tmp->last = NULL;
  tmp->list = NULL;
  return tmp;
}

void LinkedList__add(LinkedList *list, void *value) {
  struct __ll_node *node = (struct __ll_node *) malloc(sizeof(struct __ll_node));
  node->value = value;
  node->next = NULL;
  if (list->size == 0) {
    list->first = list->list = node;
  } else {
    struct __ll_node *tmp = list->last;
    tmp->next = node;
  }
  list->size++;
  list->last = node;
}

void LinkedList__destroy_all(LinkedList *list) {
  assert(list != NULL);
  struct __ll_node *node = list->first;
  while (node != NULL) {
    node = __destroy_node(node);
  }
  list->size = 0;
  list->first = NULL;
  list->last = list->list = NULL;
}

void LinkedList__delete(LinkedList *list) {
  assert(list != NULL);
  LinkedList__destroy_all(list);
  free(list);
}

struct __ll_node * __destroy_node(struct __ll_node *node) {
  assert(node != NULL);
  if (node != NULL) {
    struct __ll_node *tmp = node->next;
    free(node->value);
    free(node);
    return tmp;
  }
  return NULL;
}
