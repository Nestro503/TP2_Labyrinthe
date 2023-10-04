cmake_minimum_required(VERSION 3.23.2)
project(TP2_Labyrinthe C)

set(CMAKE_C_STANDARD 23)

add_executable(TP2_Labyrinthe
        main.c
        Graphe.h
        fifo.c dfs/dfs.h bfs/bfs.h bfs/bfs.c dfs/dfs.c)
