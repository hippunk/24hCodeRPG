#ifndef GESTION_MAP_H_INCLUDED
#define GESTION_MAP_H_INCLUDED

#include "defines.h"
#include "perso/common.h"


//prototypes des méthodes

void map_creer(map_t ** MapTest, int taillex, int tailley);
void map_detruire(map_t ** Map);
void Matrice_Remplir(map_t ** Map);
void Matrice_Afficher(map_t * Map);
void Matrice_Echantilloner(int *** MatEchantillon, map_t * Map, coordonnees debut);
void Matrice_Echantillon_Afficher(int ** MatEchantillon);
void mat_echantillon_detruire(int *** MatEchantillon);
void mat_echantillon_creer(int *** MatEchantillon);
void mat_echantillon_remplir(int *** MatEchantillon);
void Matrice_Echantillon_Position_Calculer(map_t * Map, Personnage perso, coordonnees * coord);

#endif
