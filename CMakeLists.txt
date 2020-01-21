cmake_minimum_required(VERSION 3.15)
project(SOLID_Server_REDO)

set(CMAKE_CXX_STANDARD 14)

add_executable(SOLID_Server_REDO main.cpp Solver/ISolver.h Solver/SearchSolver.h Searchers/ISearcher.h Searchers/Searcher.h State.h Searchables/ISearchable.h Position.cpp Position.h Searchables/Matrix.cpp Searchables/Matrix.h Searchers/BestFS.h Searchers/DFS.h Searchers/BFS.h Searchers/Astar.h MatrixBuilder.cpp MatrixBuilder.h Handlers/ClientHandler.h Handlers/MyClientHandler.h Handlers/StringHandler.cpp Handlers/StringHandler.h "CacheManagers/CacheManager.h" Solver/StringReverser.cpp Solver/StringReverser.h Handlers/MatrixHandler.cpp Handlers/MatrixHandler.h)