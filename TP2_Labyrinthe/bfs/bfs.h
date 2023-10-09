//
// Created by Ethan Petain on 04/10/2023.
//

#ifndef TP2_LABYRINTHE_BFS_H
#define TP2_LABYRINTHE_BFS_H

#include "../fifo.h"
#include "../Graphe.h"

void coloration_successeur(Graphe graphe, int num, File file);
void init_sommet(Graphe graphe);
void algo_bsf(Graphe graphe, int sommet_initial);

#endif //TP2_LABYRINTHE_BFS_H
