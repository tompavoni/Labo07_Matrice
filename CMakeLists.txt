cmake_minimum_required(VERSION 3.20)
project(Labo07_Matrice)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS="-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Labo07_Matrice
               main.cpp
               tab.h
               tab.cpp
               annexe.h
               annexe.cpp)
