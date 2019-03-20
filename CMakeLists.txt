cmake_minimum_required(VERSION 3.13)
project(Life_ C)

set(CMAKE_C_STANDARD 99)

add_executable(Life_ main.c rand_life.c rand_life.h life.c life.h neighbourhood.c neighbourhood.h neighbourhood.c rand_life.c readParameters.c  readParameters.h show.c show.h)