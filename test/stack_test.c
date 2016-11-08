#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "stack.h"
#include <stdlib.h>
#include <stdint.h>

Stack *st;

/*
* Auxiliar Functions
*/
int setup() {
  st = stack.create();
  return 0;
}

int teardown() {
  st = stack.delete(st);
  return 0;
}

void add_some_elements(uint64_t size) {
  uint64_t i;
  for (i = 0; i < size; i++) {
    uint64_t *tmp = (uint64_t *) malloc(sizeof(uint64_t));
    *tmp = i;
    stack.push(st, tmp);
  }
}


/*
* Tests
*/
static void create_stack_and_delete() {
  st = stack.create();
  assert_non_null(st);
  assert_int_equal(stack.size(st), 0);
  st = stack.delete(st);
  assert_null(st);
}

static void create_add_some_and_verify_size() {
  add_some_elements(30);
  assert_true(stack.size(st) == UINT64_C(30));
}


static void create_and_pop_some_elements() {
  uint64_t size = 50;
  add_some_elements(size);
  uint64_t *tmp;

  assert_true(UINT64_C(49) == *(tmp = (uint64_t *)stack.pop(st)));
  assert_true(stack.size(st) == size-1);
  free(tmp);

  assert_true(UINT64_C(48) == *(tmp = (uint64_t *)stack.pop(st)));
  assert_true(stack.size(st) == size - 2);
  free(tmp);

  assert_true(UINT64_C(47) == *(tmp = (uint64_t *)stack.pop(st)));
  assert_true(stack.size(st) == size - 3);
  free(tmp);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(create_stack_and_delete),
    cmocka_unit_test_setup_teardown(create_add_some_and_verify_size, setup, teardown),
    cmocka_unit_test_setup_teardown(create_and_pop_some_elements, setup, teardown)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
