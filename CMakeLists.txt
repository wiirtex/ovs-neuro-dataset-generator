cmake_minimum_required(VERSION 3.28)
project(ovs_neuro_dataset_generator)

set(CMAKE_CXX_STANDARD 20)

add_executable(ovs_neuro_dataset_generator main.cpp
        generators.cpp
        generators.h
        Figure.cpp
        Figure.h
)
