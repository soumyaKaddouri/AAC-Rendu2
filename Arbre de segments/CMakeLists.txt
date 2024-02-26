cmake_minimum_required(VERSION 3.1)

set(SRC
    src/source.cpp
)
set(HEADER
    src/source.hpp
)

set(TEST_SRC 
    test/catch.cpp 
    test/tests.cpp
)
set(TEST_HEADER 
    test/catch.hpp
)

project(aac)

add_library(min_avec_segments ${SRC} ${HEADER})
target_compile_options(min_avec_segments PUBLIC -g -Wall -Wextra -pedantic)
target_compile_features(min_avec_segments PUBLIC cxx_std_14)
message(${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(min_avec_segments PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(test ${TEST_SRC} ${TEST_HEADER})
target_link_libraries(test PRIVATE min_avec_segments)