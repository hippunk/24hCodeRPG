/*
 *  common.h
 *  DarDream
 *
 *  Created by Jérémy on 18/01/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "../defines.h"
#include <string.h>
#include <math.h>


typedef char* string;

typedef enum{
    BRULE, EMPOISONNE, PARALYSE
}Etat;

typedef struct Liste_s{

	struct Liste_s*(*new)(void* const);
	void(*suivant)(struct Liste_s**);
	void(*precedent)(struct Liste_s**);
	void(*add)(struct Liste_s**,void* const);
	void(*afficher)(struct Liste_s*);
	void(*remove)(struct Liste_s**);

	struct Liste_s* suiv;
	struct Liste_s* prec;
	void* donnee;
	int index;
	struct Liste_s** head;

}*Liste;

/*typedef struct{

	int x;
	int y;

}coordonnees;*/

typedef struct{

	coordonnees coord;
	string nom;
	int vie;
	int vie_max;
	int vodka_courante;
	int vodka_max;
	int force;
	int courage;
	int agilite;
	int etat;
	int initiative;
	int niveau;
	int combattable;
	short mort;

}Pnj;


typedef enum{
	soin,vodka
}effetPotion;

typedef struct{

	effetPotion effet;
	int valeur;

}Potion;

typedef struct{

	//Coordonnées
	coordonnees coord;

	//Caractéristiques
	int vieCourante, vieMax;
	int vodkaCourante, vodkaMax;
	int expActuelle, expMaxDuNiveau;
	int lvl;

	//Stats
	int courage;
	int agilite;
	int force;
	int initiative;

	//Inventaire
	Liste equip;
	int nbPlaceEquipements;
	int argent;

}Personnage;

int genererAleatoire(int minValue, int maxValue, int scale);

#include "perso.h"
#include "liste.h"
