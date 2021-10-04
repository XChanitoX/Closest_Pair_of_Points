cmake_minimum_required(VERSION 3.20)
project(Closest_Pair_of_Points)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS system window graphics)
add_executable(Closest_Pair_of_Points
        main.cpp Librerias.h Point.h Simulation.h)
target_link_libraries(Closest_Pair_of_Points sfml-system sfml-window sfml-graphics)