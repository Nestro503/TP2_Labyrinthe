
#include "dfs.h"

/// PARCOURS DFS ///

// INFOS : Dans ce programme les caractères B,G et N correspondent respectivement à Blanc, Gris et Noir


void coloration_successeur_DFS(Graphe graphe, int num, int date){ // fonction qui colorie les sommets adjacents au sommet courant
    pArc arc = graphe.pSommet[num]->arc;
    while(arc != NULL){
        if(graphe.pSommet[arc->sommet]->couleur == 'B') {
            parcours_DFS(arc->sommet,graphe, date);
        }
        arc = arc->arc_suivant;
    }
}

void algo_DFS(int sommet_initial, Graphe graphe){
    int date = 0;
    init_sommet(graphe);
    printf("\nPARCOURS DSF :\n"); // indique le type de parcours choisit
    parcours_DFS(sommet_initial,graphe,date);
    printf("X\n");
}

void parcours_DFS(int s, Graphe graphe, int date){
    graphe.pSommet[s]->couleur = 'G';
    date++;
    printf("%d --> ", s);
    coloration_successeur_DFS(graphe,s,date);
    graphe.pSommet[s]->couleur = 'N';
}