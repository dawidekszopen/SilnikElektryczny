cmake_minimum_required(VERSION 4.3)
project(SilnikElektryczny C)

set(CMAKE_C_STANDARD 11)

add_executable(SilnikElektryczny main.c
        silnikElektryczny.c
        silnikElektryczny.h)
