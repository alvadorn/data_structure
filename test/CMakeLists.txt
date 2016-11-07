include_directories ("${PROJECT_SOURCE_DIR}/include")
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC)
foreach(file IN LISTS SRC)
  string(REGEX MATCH "(([a-z]|[A-Z]|[0-9]|_)*\\.c)$" file_ext ${file})
  string(REGEX MATCH "^(([a-z]|[A-Z]|[0-9]|_)*)" file_name ${file_ext})
  string(FIND ${file_ext} "_test.c" POS)
  string(SUBSTRING ${file_ext} 0 ${POS} file_test)
  message(STATUS "${file} -> ${file_ext} -> ${file_name} -> ${POS} -> ${file_test}")
  add_executable(${file_name} ${file_ext})
  add_test(${file_name} ${file_name})
  add_test(${file_name}_valgrind valgrind
           --error-exitcode=1 --read-var-info=yes
           --leak-check=full --show-leak-kinds=all
           ./${file_name})
  target_link_libraries(${file_name} ${file_test} cmocka)
endforeach(file)
