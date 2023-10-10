
#include "Graphe.h"
#include "bfs/bfs.h"
#include "dfs/dfs.h"

// affichage des successeurs du sommet num
void afficher_successeurs(pSommet * sommet, int num){
    pArc arc=sommet[num]->arc;
    printf(" sommet %d :\n",num );
    while(arc!=NULL){
        printf("%d ",arc->sommet);
        arc=arc->arc_suivant;
    }
}

// A DETAILLER
void pp_sommet2(int* ppsommet, char * nomFichier){
    FILE * ifs = fopen(nomFichier,"r");
    int taille, orientation, ordre, s1, s2;
    int temp;

    if (!ifs){printf("Erreur de lecture fichier\n");exit(-1);}

    fscanf(ifs,"%d",&ordre); // ordre du graphe
    fscanf(ifs,"%d",&taille); // taille du fichier
    fscanf(ifs,"%d",&orientation); // si graphe orienté ou non

    // donne le plus petit sommet à l'ordre du graphe
    // probleme : si graphe commence avec un sommet plus grand que l'ordre du graphe ca pourrait faire bugger le code

    int ppsommet_prev;

    // créer les arêtes du graphe
    for (int i=0; i<taille; ++i){
        ppsommet_prev = *ppsommet;
        fscanf(ifs,"%d%d",&s1,&s2);
        if(s1 < s2){
            temp = s1;
        }else{
            temp = s2;
        }
        if(temp < ppsommet_prev){
            *ppsommet = temp;
        }
    }
}

// Ajouter l'arête entre les sommets s1 et s2 du graphe
pSommet* CreerArete(pSommet* sommet,int s1,int s2){

    if(sommet[s1]->arc==NULL){
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;
        sommet[s1]->arc=Newarc;
        return sommet;
    }

    else{
        pArc temp=sommet[s1]->arc;
        while(temp->arc_suivant!=NULL){
            temp=temp->arc_suivant;
        }
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;

        if(temp->sommet>s2){
            Newarc->arc_suivant=temp->arc_suivant;
            Newarc->sommet=temp->sommet;
            temp->sommet=s2;
            temp->arc_suivant=Newarc;
            return sommet;
        }

        temp->arc_suivant=Newarc;
        return sommet;
    }
}

// créer le graphe
Graphe* CreerGraphe(int ordre){

    Graphe * Newgraphe=(Graphe*)malloc(sizeof(Graphe));
    Newgraphe->pSommet = (pSommet*)malloc(ordre*sizeof(pSommet));

    for(int i=0; i<ordre; i++){
        Newgraphe->pSommet[i]=(pSommet)malloc(sizeof(struct Sommet));
        Newgraphe->pSommet[i]->valeur=i;
        Newgraphe->pSommet[i]->arc=NULL;
    }
    return Newgraphe;
}


/* La construction du réseau peut se faire à partir d'un fichier dont le nom est passé en paramètre
Le fichier contient : ordre, taille, orientation (0 ou 1) et liste des arcs */

Graphe * lire_graphe(char * nomFichier, int ppsommet){
    Graphe* graphe;
    FILE * ifs = fopen(nomFichier,"r");
    int taille, orientation, ordre, s1, s2;


    if (!ifs){
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(ifs,"%d",&ordre); // ordre du graphe

    ordre = ordre + ppsommet;

    graphe=CreerGraphe(ordre); // créer le graphe d'ordre sommets et mets pp_sommet en premier

    fscanf(ifs,"%d",&taille); // taille du fichier
    fscanf(ifs,"%d",&orientation); // si graphe orienté ou non

    graphe->orientation=orientation;
    graphe->ordre=ordre;
    graphe->taille=taille;
    // donne le plus petit sommet à l'ordre du graphe
    // probleme : si graphe commence avec un sommet plus grand que l'ordre du graphe ca pourrait faire bugger le code

    // créer les arêtes du graphe
    for (int i=0; i<taille; ++i){
        fscanf(ifs,"%d%d",&s1,&s2);
        graphe->pSommet=CreerArete(graphe->pSommet, s1, s2);

        if(!orientation)
            graphe->pSommet=CreerArete(graphe->pSommet, s2, s1);
    }
    return graphe;
}



/*affichage du graphe avec les successeurs de chaque sommet */
void graphe_afficher(Graphe* graphe){
    printf("\ngraphe :");

    if(graphe->orientation)
        printf("oriente\n");
    else
        printf("non oriente\n");

    printf("ordre = %d\n",graphe->ordre);
    printf("taille = %d\n",graphe->taille);
    printf("listes d'adjacence :\n");

    for (int i=0; i<graphe->ordre; i++){
        afficher_successeurs(graphe->pSommet, i);
        printf("\n");
    }
}



int main(){

    Graphe * g;
    int ppsommet = 100;
    char nom_fichier[50];
    int sommet_initial;

    ///validation du fichier utilisé
    printf("Entrer le nom du fichier du labyrinthe:");
    scanf("%s",nom_fichier);

    /// A COMMENT
    pp_sommet2(&ppsommet,nom_fichier);
    g = lire_graphe(nom_fichier, ppsommet);

    ///saisie du numéro du sommet initial pour lancer un BFS puis un DSF
    printf("Numero du sommet initial :");
    scanf("%d", &sommet_initial);

    ///parcours de graphe
    algo_bsf(*g, sommet_initial);   // Fonction générale pour le parcours en largeur
    algo_DFS(sommet_initial, *g);   // Fonction générale pour le parcours en longueur

    recherche_CC(*g);   // Fonction de recherche des composantes connexes du graphe

    /// afficher le graphe
    //graphe_afficher(g);

    return 0;
}
