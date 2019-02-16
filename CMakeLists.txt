cmake_minimum_required(VERSION 3.12)
project(calc C)

set(CMAKE_C_STANDARD 11)

add_executable(calc main.c header/int_link.h source/int_link.c header/char_stack.h source/char_stack.c header/calc.h source/calc.c)