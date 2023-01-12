cmake_minimum_required(VERSION 3.9)

project(Sudoku_Game  VERSION 1.0.0 DESCRIPTION "Game for fun")
add_definitions(-std=c++14)

#include_directories(src)
add_executable(Sudoku_Game 
	src/main.cpp
	src/cell.cpp
	src/cell.h
	src/sudoku.cpp
	src/sudoku.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/repos/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

target_link_libraries(Sudoku_Game  sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
