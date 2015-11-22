cmake_minimum_required (VERSION 2.6)
project (SimpleServer)

add_subdirectory(opt/rokunet)
include_directories(opt/rokunet/Include)

add_subdirectory(Source)
add_subdirectory(Source/methods)
include_directories(Source)

add_library(
  SimpleServer
  STATIC
  ${SimpleServerSource}
)

target_link_libraries(
  SimpleServer
  rokunet
)

ADD_DEFINITIONS(-std=c++11)
SET(CMAKE_EXE_LINKER_FLAGS "-pthread")

add_executable(SimpleServerApp Source/Main.cc)
target_link_libraries(SimpleServerApp SimpleServer)

add_subdirectory(tests)
enable_testing()
add_test(NAME SimpleServerTests COMMAND SimpleServerTests)

