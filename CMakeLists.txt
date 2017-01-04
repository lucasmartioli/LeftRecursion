
set(CMAKE_CXX_STANDARD 11)

cmake_minimum_required(VERSION 3.5)
project(PredictionTable)

set(SOURCE_FILES main.cpp readgrammar.cpp grammar.h lrecursionpurge.cpp lrecursionpurge.h)
add_executable(PredictionTable ${SOURCE_FILES} )