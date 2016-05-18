cmake_minimum_required(VERSION 2.8.3)

project(rrct CXX)

find_package(Eigen3)

include_directories(${EIGEN3_INCLUDE_DIR})

add_subdirectory(src)
