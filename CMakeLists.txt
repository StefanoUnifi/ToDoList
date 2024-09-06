cmake_minimum_required(VERSION 3.25)
project(ToDoList)

add_subdirectory(test)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES Activity.h Date.cpp Date.h ToDoList.cpp ToDoList.h)
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib)