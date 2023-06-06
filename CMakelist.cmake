cmake_minimum_required(VERSION 3.24)


set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -pedantic -std=c99 -fsanitize=address")

add_executable("Guia7.c")