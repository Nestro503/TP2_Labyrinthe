#include "bfs.h"



void coloration_successeur(Graphe graphe, int num, File file){ // fonction qui colorie les sommets adjacents au sommet courant
    pArc arc = graphe.pSommet[num - graphe.ppsommet]->arc;

    while(arc != NULL){
        if(graphe.pSommet[arc->sommet]->couleur == 'B') {
            graphe.pSommet[arc->sommet]->couleur = 'G';

            enfiler(file, arc->sommet + graphe.ppsommet);
            //printf("\n%d est successeur de %d",arc->sommet, num);
        }
        //printf("%d", arc->sommet);
        arc = arc->arc_suivant;
    }
}


void init_sommet(Graphe graphe){
    for (int i = 0; i < graphe.ordre; ++i) {
        graphe.pSommet[i]->couleur = 'B';
    }
}


void algo_bsf(Graphe graphe, int sommet_initial){ // fonction qui prend un graphe et un sommet choisit
    int s = 0; // sommet courant
    File file = fileVide(); // création de la file vide
    init_sommet(graphe); // initialisation de la couleur des sommets à blanc (0)
    enfiler(file, sommet_initial); // enfiler le premier sommet choisit
    graphe.pSommet[sommet_initial]->couleur = 'G'; // mettre le sommet à la couleur grise
    while(!fileEstVide(file)){ // tant que la file n'est pas vide faire :
        //ecrireFile(file);
        s = defilement(file); // defiler l'élément en tête de file
        coloration_successeur(graphe, s, file);
        graphe.pSommet[s - graphe.ppsommet]->couleur = 'N'; // mettre le sommet courant à noir
        printf("%d --> ", s);
    }
    for (int i = 0; i < graphe.ordre; ++i) {
        //printf("%c", graphe.pSommet[i]->couleur);
        printf("%d", graphe.pSommet[i]->valeur);
    }
}