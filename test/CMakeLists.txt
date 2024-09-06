cmake_minimum_required(VERSION 3.25)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp ActivityTest.cpp DateTest.cpp ToDoListTest.cpp ToDoListFixture.cpp)
add_executable(runAllTests ${SOURCE_TEST_FILES})
target_link_libraries(runAllTests gtest gtest_main ${CMAKE_PROJECT_NAME}_lib)