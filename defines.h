#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int x;
    int y;

}coordonnees;

//Structures Pour la gestion de map et d'élément de map

typedef struct element_map_d
{
        int couche;
        int bloquant;
        int sprite;
        int script;

}element_map_t;

typedef struct map_d
{
    element_map_t ** matrice_map;
    int taille_x;
    int taille_y;

}map_t;

int int_rand(int MIN, int MAX);

#endif // DEFINES_H_INCLUDED
