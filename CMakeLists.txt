cmake_minimum_required(VERSION 3.27)
project(ProjetoEDA)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjetoEDA main.cpp
        initialization.cpp
        initialization.h
        utils.cpp
        utils.h
        sections.cpp
        section.h
)
