cmake_minimum_required(VERSION 3.9)
project(GOP)

set(CMAKE_CXX_STANDARD 11)

add_executable(GOP main.cpp src/GOP.cpp include/GOP.h src/Giocatore.cpp include/Giocatore.h src/Casella.cpp include/Casella.h src/Dado.cpp src/General_functions.cpp src/Graphics.cpp src/Tabellone.cpp include/Auxiliary_functions.h src/Carta.cpp include/Carta.h)