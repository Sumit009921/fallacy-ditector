cmake_minimum_required(VERSION 4.0)
project(fallacy_project C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(fallacy_project
        fallacy.c
        fallacy.h
        main.c)
