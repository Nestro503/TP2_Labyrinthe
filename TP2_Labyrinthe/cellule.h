
// cellule.h provient du site http://morissardjerome.free.fr/


#ifndef TP2_LABYRINTHE_CELLULE_H
#define TP2_LABYRINTHE_CELLULE_H

typedef int typage;

struct _cellule {
    typage element;
    struct _cellule *suivant;
};

typedef struct _cellule* Cellule;

#endif //TP2_LABYRINTHE_CELLULE_H
