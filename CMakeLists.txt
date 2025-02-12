cmake_minimum_required(VERSION 3.30)
project(Arbres)

set(CMAKE_CXX_STANDARD 23)

include_directories(include include/Exception include/ArbreBinaire include/ArbreRecherche)

add_executable(Arbres src/main.cpp
        src/lib/Exception.cpp
        src/lib/ArbreRecherche.cpp
)
