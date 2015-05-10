#ifndef GEN_MAP_H_INCLUDED
#define GEN_MAP_H_INCLUDED

#include "defines.h"

typedef struct point_gen_d
{
    int type;
    int seedluck;

}point_gen_t;


void generer_exterieur(map_t ** Map);
void genematrice_creer(point_gen_t *** genematrice, coordonnees mat_taille);
void zeroter(point_gen_t *** genematrice, coordonnees mat_taille);
void genematrice_affiche(point_gen_t ** genematrice, coordonnees mat_taille);
void genematrice_copier_map(point_gen_t ** genematrice, map_t ** Map);
void genematrice_generer(point_gen_t *** genematrice, coordonnees mat_taille);
void genematrice_detruire(point_gen_t *** genematrice, coordonnees mat_taille);


#endif // GEN_MAP_H_INCLUDED
