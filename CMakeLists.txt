cmake_minimum_required(VERSION 4.0)
project(Grocery)

set(CMAKE_CXX_STANDARD 20)

add_executable(Grocery main.cpp
        FrequenciesCalculator.cpp
        FrequenciesCalculator.h)
