cmake_minimum_required(VERSION 3.24)
project(Shunting_Yard)

set(CMAKE_CXX_STANDARD 17)

add_executable(Shunting_Yard main.cpp LinkedList.cpp Test.cpp Test.h Stack.cpp Stack.h Queue.cpp Queue.h Iterator.cpp Iterator.h RPN.cpp RPN.h)
