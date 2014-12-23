cmake_minimum_required (VERSION 2.6)
project (SimpleServer)

set(LIBRARY_NAME SimpleServerLibrary)

add_subdirectory(Source)
add_subdirectory(tests)

enable_testing()
add_test(NAME SimpleServerTests COMMAND SimpleServerTests)
