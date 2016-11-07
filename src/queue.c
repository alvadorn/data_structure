#include "queue.h"
#include <stdlib.h>
#include <assert.h>

struct queue queue = {
  Queue__create,
  Queue__enqueue,
  Queue__dequeue,
  Queue__dequeue_all,
  Queue__delete,
  Queue__size,
};

Queue *Queue__create(void) {
  Queue *tmp = (Queue *) malloc(sizeof(Queue));
  tmp->size = 0;
  return tmp;
}

void Queue__enqueue(Queue *queue, void *value) {
  assert(queue != NULL);
  if (queue != NULL) {
    struct __queue_node *tmp = (struct __queue_node *) malloc (sizeof(struct __queue_node));
    tmp->next = NULL;
    if (queue->size == 0) {
      queue->queue = tmp;
    } else {
      queue->last->next = tmp;
    }
    queue->size++;
    queue->last = tmp;
  }
}

void *Queue__dequeue(Queue *queue) {
  assert(queue != NULL);
  struct __queue_node *tmp = queue->queue;
  void *value = tmp->value;
  queue->queue = tmp->next;
  queue->size--;
  free(tmp);
  return value;
}

void Queue__dequeue_all(Queue *queue) {
  assert(queue != NULL);
  if (queue->size == 0) {
    return;
  }
  struct __queue_node *tmp = queue->queue;
  while (tmp != NULL) {
    struct __queue_node *next = tmp->next;
    __destroy(tmp);
    tmp = next;
  }
  queue->size = 0;
}


uint64_t Queue__size(Queue *queue) {
  return queue->size;
}

void Queue__delete(Queue *queue) {
  assert(queue != NULL);
  Queue__dequeue_all(queue);
  free(queue);
}


void __destroy (struct __queue_node *node) {
  assert(node != NULL);
  if (node != NULL) {
    free(node->value);
    free(node);
  }
}
