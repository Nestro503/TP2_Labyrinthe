#ifndef TP2_LABYRINTHE_DFS_H
#define TP2_LABYRINTHE_DFS_H

#include "../Graphe.h"
#include "../bfs/bfs.h"

void init_DFS(int sommet_initial, pSommet *sommet, Graphe *graphe);
void parcours_DFS(int sommet_initial, Graphe *graphe, int date);
void init_DFS2(int sommet_initial, Graphe graphe);
void parcours_DFS2(int s, Graphe graphe, int* date);


#endif
