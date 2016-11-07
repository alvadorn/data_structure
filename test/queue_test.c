#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "queue.h"

static void create_queue_and_delete() {
  Queue *q = queue.create();
  assert_non_null(q);
  assert_int_equal(queue.size(q), 0);
  queue.delete(q);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(create_queue_and_delete),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
