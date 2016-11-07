include_directories ("${PROJECT_SOURCE_DIR}/include")
add_executable(queue_test queue_test.c)
add_dependencies(queue_test queue_test)
add_test(queue_test queue_test)
add_test(queue_test_valgrind valgrind
         --error-exitcode=1 --read-var-info=yes
         --leak-check=full --show-leak-kinds=all
         ./queue_test)
target_link_libraries(queue_test queue cmocka)
