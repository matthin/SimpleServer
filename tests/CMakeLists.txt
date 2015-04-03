set(TEST_SOURCE
   ${TEST_SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/Main.cc
   ${CMAKE_CURRENT_SOURCE_DIR}/Listener.cc
   ${CMAKE_CURRENT_SOURCE_DIR}/Socket.cc
)

set(EXECUTABLE_NAME SimpleServerTests)

add_executable(${EXECUTABLE_NAME} ${TEST_SOURCE} ${TEST_HEADERS})

target_link_libraries(
    ${LIBRARY_NAME}
)

target_link_libraries(
	${EXECUTABLE_NAME}
	${LIBRARY_NAME}
)

target_include_directories(${EXECUTABLE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
SET(CMAKE_EXE_LINKER_FLAGS "-pthread")
