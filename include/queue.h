#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdint.h>

struct __queue_node {
  void *value;
  struct __queue_node *next;
};

typedef struct Queue {
  struct __queue_node *queue;
  struct __queue_node *last;
  uint64_t size;
} Queue;

struct queue {
  Queue *(* create)(void);
  void (* enqueue)(Queue *, void *);
  void *(* dequeue)(Queue *);
  void (* dequeue_all)(Queue *);
  void (* delete)(Queue *);
};

extern struct queue queue;

Queue *Queue__create(void);
void Queue__enqueue(Queue *, void *);
void *Queue__dequeue(Queue *);
void Queue__dequeue_all(Queue *);
void Queue__delete(Queue *);
void __destroy(struct __queue_node *);

#endif // __QUEUE_H__
