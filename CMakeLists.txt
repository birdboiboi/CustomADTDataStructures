cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -pedantic")


project(adt_linked_lists CXX)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(test)


add_executable(ADTTest src/main.cpp)
add_executable(Linked_List_Test test/linked_list_test.cpp)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(
    Linked_List_Test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Linked_List_Test)
add_test(NAME Linked_List_Test COMMAND LinkedList)

target_include_directories(Linked_List_Test PRIVATE ${adt_linked_lists_SOURCE_DIR}/include)



