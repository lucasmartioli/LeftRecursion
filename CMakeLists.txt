cmake_minimum_required(VERSION 3.6)
project(PredictionTable)

set(SOURCE_FILES main.c readgramar.c conjunto.h follow.h follow.c)
add_executable(PredictionTable ${SOURCE_FILES})