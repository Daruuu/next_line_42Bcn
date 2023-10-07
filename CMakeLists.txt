cmake_minimum_required(VERSION 3.26)
project(next_line_42Bcn C)

set(CMAKE_C_STANDARD 99)

# Agregar cada archivo .c
add_executable(next_line ft_get_next_line.c
        get_next_line.h)