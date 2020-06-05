cmake_minimum_required(VERSION 3.15)
project(Lab_5)

set(CMAKE_CXX_STANDARD 98)

add_executable(Lab_5 main.cpp main.h CTree/CNodeDynamic.cpp CTree/CNodeDynamic.h CTree/CTreeDynamic.cpp CTree/CTreeDynamic.h CTree/CNodeStatic-old.cpp CTree/CNodeStatic-old.h CTree/CTreeStatic.cpp CTree/CTreeStatic.h)