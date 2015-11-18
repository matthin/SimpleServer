set(TEST_SOURCE
   ${TEST_SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/Main.cc
   ${CMAKE_CURRENT_SOURCE_DIR}/Listener.cc
   ${CMAKE_CURRENT_SOURCE_DIR}/Socket.cc
)

add_executable(SimpleServerTests ${TEST_SOURCE} ${TEST_HEADERS})

target_link_libraries(
  SimpleServerTests
  SimpleServer
)

target_include_directories(SimpleServerTests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
SET(CMAKE_EXE_LINKER_FLAGS "-pthread")

