#ifndef TP2_LABYRINTHE_DFS_H
#define TP2_LABYRINTHE_DFS_H

#include "../Graphe.h"
#include "../bfs/bfs.h"

// Permet de colorer tous les sommets en blanc avant le début du parcours
void init_DFS(int sommet_initial, Graphe graphe);

// Fonction qui colorie les sommets adjacents au sommet courant
void coloration_successeur_DFS(Graphe graphe, int num, int date);

// Efectue le parcours de sommets en sommets tant que le graphe n'est pas entièrement coloré
void parcours_DFS(int s, Graphe graphe, int date);


#endif
