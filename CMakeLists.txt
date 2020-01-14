cmake_minimum_required(VERSION 3.15)
project(SOLID_Server_REDO)

set(CMAKE_CXX_STANDARD 14)

add_executable(SOLID_Server_REDO main.cpp Solver/ISolver.h Solver/SearchSolver.cpp Solver/SearchSolver.h Searchers/ISearcher.h Searchers/Searcher.cpp Searchers/Searcher.h State.cpp State.h Searchables/ISearchable.h Position.cpp Position.h Searchables/Matrix.cpp Searchables/Matrix.h Searchers/BestFS.cpp Searchers/BestFS.h)