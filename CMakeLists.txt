cmake_minimum_required(VERSION 3.17)
project(engine_wrapper)

set(CMAKE_CXX_STANDARD 17)

add_executable(engine_wrapper main.cpp wrapper.h definitions.h does_something.h engine.h)