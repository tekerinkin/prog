cmake_minimum_required(VERSION 3.16)
project(c__)


set(CMAKE_CXX_STANDARD 20)

include_directories("/usr/local/boost_1_75_0")


add_executable(c__ main.cpp complex.h vector.h quicksort.h linked_list.h TypeList.h)

