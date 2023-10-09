
#include "dfs.h"

// INFOS : Dans ce programme les caractères B,G et N correspondent respectivement à Blanc, Gris et Noir

void coloration_successeur_DFS(Graphe graphe, int num, int* date){ // fonction qui colorie les sommets adjacents au sommet courant
    pArc arc = graphe.pSommet[num - graphe.ppsommet]->arc;

    while(arc != NULL){
        if(graphe.pSommet[arc->sommet]->couleur == 'B') {
            //printf("\n%d est successeur de %d",arc->sommet, num);
            parcours_DFS2(arc->sommet,graphe, date);
        }
        //printf("%d", arc->sommet);
        arc = arc->arc_suivant;
    }
}

void init_DFS(int sommet_initial, pSommet *sommet, Graphe *graphe){
    int date = 0;

    for(int i = 0; i < graphe->taille; i++){ //initialisation de tous les sommets à blanc
        sommet[i]->couleur = 'B';
    }
    //parcours_DFS(sommet_initial,graphe);
}


/*void parcours_DFS(int sommet_initial, Graphe *graphe, int date){
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
}*/

void init_DFS2(int sommet_initial, Graphe graphe){
    init_sommet(graphe);
    int date = 0;
    parcours_DFS2(sommet_initial,graphe,&date);
}
void parcours_DFS2(int s, Graphe graphe, int* date){
    graphe.pSommet[s]->couleur = 'G';
    date++;
    coloration_successeur_DFS(graphe,s,date);
    graphe.pSommet[s]->couleur = 'N';
    printf("%d < --  ", s);
}