
#ifndef TP2_LABYRINTHE_BFS_H
#define TP2_LABYRINTHE_BFS_H

#include "../fifo.h"
#include "../Graphe.h"

//Permet de colorer tous les sommets en blanc avant le début du parcours
void init_sommet(Graphe graphe);

// Fonction qui colorie les sommets adjacents au sommet courant
void coloration_successeur(Graphe graphe, int num, File file);

// Fonction qui comprend l'algo général du parcorus en largeur
void algo_bsf(Graphe graphe, int sommet_initial);

// Permet d'identifier toutes les composantes connexes du graphes
void recherche_CC(Graphe graphe);

// Variante du parcours de BFS pour la recherche de composantes connexes
void variante_algo_bsf(Graphe graphe, int sommet_initial);


#endif //TP2_LABYRINTHE_BFS_H
