#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "queue.h"
#include <stdlib.h>
#include <stdint.h>

Queue *q;

/*
* Auxiliar Functions
*/
int setup() {
  q = queue.create();
  return 0;
}

int teardown() {
  q = queue.delete(q);
  return 0;
}

void add_some_elements(uint64_t size) {
  uint64_t i;
  for (i = 0; i < size; i++) {
    uint64_t *tmp = (uint64_t *) malloc(sizeof(uint64_t));
    *tmp = i;
    queue.enqueue(q, tmp);
  }
}


/*
* Tests
*/
static void create_queue_and_delete() {
  q = queue.create();
  assert_non_null(q);
  assert_int_equal(queue.size(q), 0);
  q = queue.delete(q);
  assert_null(q);
}

static void create_add_some_and_verify_size() {
  add_some_elements(30);
  assert_true(queue.size(q) == UINT64_C(30));
}

static void create_and_dequeue_some_elements() {
  uint64_t size = 50;
  add_some_elements(size);
  uint64_t *tmp;

  assert_true(UINT64_C(0) == *(tmp = (uint64_t *)queue.dequeue(q)));
  assert_true(queue.size(q) == size-1);
  free(tmp);

  assert_true(UINT64_C(1) == *(tmp = (uint64_t *)queue.dequeue(q)));
  assert_true(queue.size(q) == size - 2);
  free(tmp);

  assert_true(UINT64_C(2) == *(tmp = (uint64_t *)queue.dequeue(q)));
  assert_true(queue.size(q) == size - 3);
  free(tmp);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(create_queue_and_delete),
    cmocka_unit_test_setup_teardown(create_add_some_and_verify_size, setup, teardown),
    cmocka_unit_test_setup_teardown(create_and_dequeue_some_elements, setup, teardown)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
