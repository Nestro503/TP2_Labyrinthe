#ifndef TP2_LABYRINTHE_FIFO_H
#define TP2_LABYRINTHE_FIFO_H

// SOURCES : fifo.h provient du site http://morissardjerome.free.fr/

#include "cellule.h"

struct _file {
    int longueur;
    Cellule tete;
    Cellule queue;
};

typedef struct _file* File;

#define fileEstVide(F) ((F)->longueur == 0)

File fileVide();
int longueur(File F);
void enfiler(File F, typage element);
typage tete(File F);
void defiler(File F);
typage defilement(File F);
void ecrireFile(File F);


#endif
