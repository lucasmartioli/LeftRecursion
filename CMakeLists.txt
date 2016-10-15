cmake_minimum_required(VERSION 3.6)
project(PredictionTable)

set(SOURCE_FILES main.c readgramar.c conjunto.h follow.h follow.c first.c first.h)
add_executable(PredictionTable ${SOURCE_FILES})