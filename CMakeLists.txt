cmake_minimum_required(VERSION 3.17)
project(CryptBase64)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-std=gnu++17 -U__STRICT_ANSI__)

add_subdirectory(googletest)

include_directories(src) # необходимо для того, чтобы писать в директиве просто lib.h
include_directories(googletest/googletest/include)

set(SOURCE_FILES src/libBase64.cpp)

add_executable(main main.cpp ${SOURCE_FILES})
add_executable(tests tests.cpp ${SOURCE_FILES})

target_link_libraries(tests gtest)