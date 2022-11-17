cmake_minimum_required(VERSION 3.23)
project(Pokemon C)

set(CMAKE_C_STANDARD 99)

add_executable(Pokemon main.c Pokemon.c Pokemon.h Type.c Type.h)
