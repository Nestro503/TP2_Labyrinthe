#include "bfs.h"

/// PARCOURS BFS ///

// INFOS : Dans ce programme les caractères B,G et N correspondent respectivement à Blanc, Gris et Noir


void coloration_successeur(Graphe graphe, int num, File file){ // fonction qui colorie les sommets adjacents au sommet courant
    pArc arc = graphe.pSommet[num]->arc;  // prends l'arc du sommet defiler

    while(arc != NULL){
        if(graphe.pSommet[arc->sommet]->couleur == 'B') {
            graphe.pSommet[arc->sommet]->couleur = 'G';

            enfiler(file, arc->sommet);
        }
        arc = arc->arc_suivant;
    }
}


void init_sommet(Graphe graphe){    // initialise le graphe en mettant tous les sommets en blanc
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
        graphe.pSommet[s]->couleur = 'N'; // mettre le sommet courant à noir
        printf("%d --> ", s);
    }
    printf("\n");
}


void variante_algo_bsf(Graphe graphe, int sommet_initial){ // fonction qui prend un graphe et un sommet choisit
    int s = 0; // sommet courant
    File file = fileVide(); // création de la file vide
    init_sommet(graphe); // initialisation de la couleur des sommets à blanc (0)
    enfiler(file, sommet_initial); // enfiler le premier sommet choisit
    graphe.pSommet[sommet_initial]->couleur = 'G'; // mettre le sommet à la couleur grise
    while(!fileEstVide(file)){ // tant que la file n'est pas vide faire :
        s = defilement(file); // defiler l'élément en tête de file
        coloration_successeur(graphe, s, file);
        graphe.pSommet[s]->couleur = 'N'; // mettre le sommet courant à noir
        printf("%d%c ",s, graphe.pSommet[s]->couleur);
    }
}


void recherche_CC(Graphe graphe){
    int num = 1; // compteur des composantes
    for (int i = 0; i < graphe.ordre; ++i) {
        graphe.pSommet[i]->couleur = 'B';
    }
    for (int i = 0; i < graphe.ordre; ++i) { // Boucle parcourant tout le graphe
        if(graphe.pSommet[i]->couleur == 'B'){ // Tant qu'il existe d'autres sommets blanc c'est qu'il y a d'autres composantes
            printf("Composante connexe n%d : ",num); // Affichage des différentes composantes
            variante_algo_bsf(graphe,i);
            printf("\n");
            num++;  // Incrémentation du nombre de composantes trouvées
        }
    }
}