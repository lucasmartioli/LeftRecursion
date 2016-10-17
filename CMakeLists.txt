cmake_minimum_required(VERSION 3.5)
project(PredictionTable)

set(SOURCE_FILES main.c readgrammar.c conjunto.h first.c first.h grammar.h follow.c follow.h)
add_executable(PredictionTable ${SOURCE_FILES})