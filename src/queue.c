#include "queue.h"
#include <stdlib.h>
#include <assert.h>

struct queue queue = {
  Queue__create,
  Queue__enqueue,
  Queue__dequeue,
  Queue__dequeue_all,
  Queue__delete
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
