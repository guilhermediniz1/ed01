cmake_minimum_required(VERSION 3.24)
project(lista_linear_estatica C)

set(CMAKE_C_STANDARD 11)

add_executable(lista_linear_estatica main.c lista_sequencial.c  lista_sequencial.h)
