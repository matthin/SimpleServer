cmake_minimum_required (VERSION 2.6)
project (SimpleServer)

add_subdirectory(Source)
add_subdirectory(Source/http)
add_subdirectory(Source/methods)
include_directories(Source)

add_library(
  SimpleServer
  STATIC
  ${SimpleServerSource}
)

ADD_DEFINITIONS(-std=c++11)
SET(CMAKE_EXE_LINKER_FLAGS "-pthread")

add_executable(SimpleServerApp Source/Main.cc)
target_link_libraries(SimpleServerApp SimpleServer)

add_subdirectory(tests)
enable_testing()
add_test(NAME SimpleServerTests COMMAND SimpleServerTests)

