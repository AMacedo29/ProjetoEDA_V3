cmake_minimum_required(VERSION 3.27)
project(ProjetoEDA)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjetoEDA main.cpp
        utils.cpp
        utils.h
        sections.cpp
        sections.h
        pecas.cpp
        pecas.h
        simulator.cpp
        simulator.h
        gestao.cpp
        gestao.h
)
