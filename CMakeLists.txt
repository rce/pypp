cmake_minimum_required(VERSION 3.8)
project(pypp)

#find_package(pybind11 REQUIRED)
add_subdirectory(pybind11)

add_executable(example src/main.cpp)
target_link_libraries(example PRIVATE pybind11::embed)
