#ifndef TP2_LABYRINTHE_DFS_H
#define TP2_LABYRINTHE_DFS_H

#include "../graphe.h"

void init_DFS(int sommet_initial, pSommet *sommet, Graphe *graphe);
void parcours_DFS(int sommet_initial, Graphe *graphe, int date);


#endif
