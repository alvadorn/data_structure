#include "linked_list.h"
#include <stdlib.h>
#include <assert.h>

struct linked_list linked_list = {
  LinkedList__create,
  LinkedList__destroy,
  LinkedList__destroy_all,
  LinkedList__add,
  LinkedList__delete,
  LinkedList__size,
  LinkedList__find
};

LinkedList *LinkedList__create(void) {
  LinkedList *tmp = (LinkedList *) malloc(sizeof(LinkedList));
  if (tmp != NULL) {
    tmp->size = 0;
    tmp->first = NULL;
    tmp->last = NULL;
    tmp->list = NULL;
  }
  return tmp;
}

void LinkedList__add(LinkedList *list, void *value) {
  assert(list != NULL);
  struct __ll_node *node = (struct __ll_node *) malloc(sizeof(struct __ll_node));
  node->value = value;
  node->next = NULL;
  if (list->size == 0) {
    list->first = list->list = node;
  } else {
    struct __ll_node *tmp = list->last;
    tmp->next = node;
  }
  (list->size)++;
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

LinkedList *LinkedList__delete(LinkedList *list) {
  assert(list != NULL);
  LinkedList__destroy_all(list);
  free(list);
  return NULL;
}

uint64_t LinkedList__size(LinkedList *list) {
  return list->size;
}

void LinkedList__destroy(LinkedList *list, void *element, bool (* compare)(void *, void *)) {
  assert(list != NULL);
  struct __ll_node *tmp = list->first;
  struct __ll_node *last = NULL;
  while (tmp != NULL) {
    if (compare(tmp->value, element)) {
      if (last == NULL) {
        list->first = tmp->next;
      } else {
        last->next = tmp->next;
      }
      free(tmp->value);
      free(tmp);
      list->size--;
      return;
    }
    last = tmp;
    tmp = tmp->next;
  }
}

void *LinkedList__find(LinkedList *list, void *element, bool (* compare)(void *, void *)) {
  assert(list != NULL);
  struct __ll_node *tmp = list->first;
  while (tmp != NULL) {
    if (compare(element, tmp->value)) {
      return tmp->value;
    }
    tmp = tmp->next;
  }
  return NULL;
}

void LinkedList__iterator(LinkedList *list) {
    list->list = list->first;
}

void *LinkedList__getNext(LinkedList *list) {
  void *tmp = list->list->value;
  list->list = list->list->next;
  return tmp;
}

struct __ll_node * __destroy_node(struct __ll_node *node) {
  assert(node != NULL);
  if (node != NULL) {
    struct __ll_node *tmp = node->next;
    if (node->value != NULL) {
      free(node->value);
    }
    free(node);
    return tmp;
  }
  return NULL;
}
