cmake_minimum_required(VERSION 3.29)
project(lab_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab_1 main.cpp
        main.h
        src/menu.cpp
        headers/menu.h
        src/entrypoint.cpp
        headers/entrypoint.h
        src/figures.cpp
        headers/figures.h
        src/fabric.cpp
        headers/fabric.h
        src/inputValidator.cpp
        headers/inputValidator.h
        src/figuresManager.cpp
        headers/figuresManager.h
        headers/constants.h
        headers/dot.h
        src/dot.cpp
)
