#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include <cmocka.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

LinkedList *list;

/*
* Auxiliar functions
*/
static int setup() {
  list = linked_list.create();
  return 0;
}

static int teardown() {
  list = linked_list.delete(list);
  return 0;
}

void add_some_elements(uint64_t size) {
  uint64_t i;
  for (i = 0; i < size; i++) {
    uint64_t *v = (uint64_t *) malloc(sizeof(uint64_t));
    *v = i;
    linked_list.add(list, v);
  }
}

bool compare(void *v1, void *v2) {
  return *(uint64_t *)v1 == *(uint64_t *)v2;
}


/*
* Tests functions
*/
static void create_linked_list_and_delete() {
  list = linked_list.create();
  assert_non_null(list);
  assert_true(UINT64_C(0) == linked_list.size(list));
  list = linked_list.delete(list);
  assert_null(list);
}

static void create_add_some_and_verify_size() {
  list = linked_list.create();
  uint64_t size = 20;
  add_some_elements(size);
  assert_true(size == linked_list.size(list));
  uint64_t i = 0;
  for (LinkedList__iterator(list); i < linked_list.size(list); i++) {
    assert_true(i == (*(uint64_t *)LinkedList__getNext(list)));
  }
  linked_list.delete(list);
}

static void create_add_some_and_destroy_some_elements() {
  uint64_t size = 20;
  add_some_elements(size);
  uint64_t v = 50;
  linked_list.destroy(list, &v, compare);
  assert_true(size == linked_list.size(list));
  v = 8;
  linked_list.destroy(list, &v, compare);
  assert_true(UINT64_C(19) == linked_list.size(list));
  v = 18;
  linked_list.destroy(list, &v, compare);
  assert_true(UINT64_C(18) == linked_list.size(list));
  v = 0;
  linked_list.destroy(list, &v, compare);
  assert_true(UINT64_C(17) == linked_list.size(list));
}

static void create_add_some_and_find() {
  uint64_t size = 20;
  add_some_elements(size);
  uint64_t v = 5;
  uint64_t tmp = *(uint64_t *)linked_list.find(list, &v, compare);
  assert_true(tmp == v);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(create_linked_list_and_delete),
    cmocka_unit_test(create_add_some_and_verify_size),
    cmocka_unit_test_setup_teardown(create_add_some_and_destroy_some_elements, setup, teardown),
    cmocka_unit_test_setup_teardown(create_add_some_and_find, setup, teardown)
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
