cmake_minimum_required(VERSION 3.28)
project(BST_and_AVL)

set(CMAKE_CXX_STANDARD 17)

add_executable(BST_and_AVL main.cpp
        AVL.h
        Tree.h
        Tree.cpp
        AVL.cpp
        BST.h
        BST.cpp
        Action.h
        Action.cpp
        Balancer.h
        Balancer.cpp
        Remover.h
        Remover.cpp)
