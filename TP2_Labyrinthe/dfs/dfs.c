
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

void init_DFS(int sommet_initial, Graphe graphe){      // initialise le graphe en mettant tous les sommets en blanc
    init_sommet(graphe);
    int date = 0;
    parcours_DFS(sommet_initial,graphe,date);
    printf("\n");
}

void parcours_DFS(int s, Graphe graphe, int date){
    graphe.pSommet[s]->couleur = 'G';
    date++;
    printf("%d --> ", s);

    coloration_successeur_DFS(graphe,s,date);
    graphe.pSommet[s]->couleur = 'N';
}