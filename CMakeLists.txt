cmake_minimum_required(VERSION 3.17)
project(GameStore)

set(CMAKE_CXX_STANDARD 14)

add_executable(GameStore main.cpp BoardGameExpansion.cpp BoardGameExpansion.h Game.cpp Game.h CardGame.cpp CardGame.h BoardGame.cpp BoardGame.h GameAdmin.cpp GameAdmin.h io.cpp io.h)
configure_file(expansions.txt expansions.txt COPYONLY)