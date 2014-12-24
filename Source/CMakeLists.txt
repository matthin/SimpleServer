set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/Client.cc
   ${CMAKE_CURRENT_SOURCE_DIR}/Config.cc
   ${CMAKE_CURRENT_SOURCE_DIR}/Listener.cc
   ${CMAKE_CURRENT_SOURCE_DIR}/Server.cc
   ${CMAKE_CURRENT_SOURCE_DIR}/Socket.cc
   ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp.cc
)

set(EXECUTABLE_NAME SimpleServer)

add_subdirectory(http)
add_subdirectory(methods)

add_executable(${EXECUTABLE_NAME} Main.cc)

add_library(
    ${LIBRARY_NAME}
    SHARED
    ${SOURCE}
)

target_link_libraries(
    ${LIBRARY_NAME}
)

target_link_libraries(
    ${EXECUTABLE_NAME}
    ${LIBRARY_NAME}
)

ADD_DEFINITIONS(
   -std=c++11
)

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

SET(CMAKE_EXE_LINKER_FLAGS "-pthread")
