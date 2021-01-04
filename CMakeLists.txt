cmake_minimum_required(VERSION 3.17)
project(C-Review)

set(CMAKE_CXX_STANDARD 98)

add_executable(C List_malloc.cpp )
add_executable(List_insert List_insert.cpp)
add_executable(List_delete List_delete.cpp)
add_executable(List_GetElem List_GetElem.cpp)
add_executable(List_LocateElem List_LocateElem.cpp)