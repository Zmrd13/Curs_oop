cmake_minimum_required(VERSION 3.17)
project(Curs_oop)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Curs_oop main.cpp TreeNode.cpp TreeNode.h BinaryTree.cpp BinaryTree.h)
target_link_libraries(Curs_oop sfml-graphics sfml-audio)