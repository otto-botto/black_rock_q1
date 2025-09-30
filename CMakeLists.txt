cmake_minimum_required(VERSION 3.30.5)
project(black_rock_q1)

# Allow the project to work with c and c++.
file(GLOB csources "${PROJECT_SOURCE_DIR}/*.[ch]")
set_property(SOURCE ${csources} PROPERTY CMAKE_C_STANDARD 11)
file(GLOB cppsources "${PROJECT_SOURCE_DIR}/*.cc")
set_property(SOURCE ${cppsources} PROPERTY CMAKE_CXX_STANDARD 14)
set_property(SOURCE ${cppsources} PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)

# Set up GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()


add_library(tree "tree.c" "tree.h")
add_executable(tree_test "tree_test.cc")
target_link_libraries(tree_test GTest::gtest_main tree)

add_executable(main "main.c")
target_link_libraries(main tree )
