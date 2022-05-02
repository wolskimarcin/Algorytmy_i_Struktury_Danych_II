cmake_minimum_required(VERSION 3.21)
project(Zestaw_01)

set(CMAKE_CXX_STANDARD 14)

add_executable(Zestaw_01 setSimple.h testSimple.cpp setLinked.h testLinked.cpp SortedList.h main.cpp)
