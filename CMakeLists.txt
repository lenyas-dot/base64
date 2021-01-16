cmake_minimum_required(VERSION 3.19)
project(base64)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES Functions.cpp)
add_subdirectory(googletest)


add_executable(base64 main.cpp Functions.cpp Functions.h)
add_executable(tests tests.cpp ${SOURCE_FILES})

target_include_directories(tests PRIVATE googletest/googletest/include PRIVATE source)

target_link_libraries(tests gtest)