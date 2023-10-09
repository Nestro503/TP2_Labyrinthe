
#include "dfs.h"

// INFOS : Dans ce programme les caractères B,G et N correspondent respectivement à Blanc, Gris et Noir

void init_DFS(int sommet_initial, pSommet *sommet, Graphe *graphe){
    int date = 0;

    for(int i = 0; i < graphe->taille; i++){ //initialisation de tous les sommets à blanc
        sommet[i]->couleur = 'B';
    }
    parcours_DFS(sommet_initial,graphe)
}


void parcours_DFS(int sommet_initial, Graphe *graphe, int date){
    graphe->pSommet[sommet_initial]->couleur = 'G';
    date++;
    if (graphe = NULL){
        return;
    }
    while (graphe->pSommet[]->couleur == 'B'){
        parcours_DFS(sommet_initial, graphe, date);
    }
    graphe->pSommet[sommet_initial]->couleur = 'N';
    printf("Fin d'exploration");
    date++;
    printf("Ordre de découverte : ");
}