/*
 *  perso.c
 *  DarDream
 *
 *  Created by Jérémy on 18/01/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "common.h"

struct Liste_s liste={&New,&suivListe,&precListe};

void gainXp(Personnage* Darwin, int xp)
{
	if(Darwin->expActuelle+xp>=Darwin->expMaxDuNiveau)
	{
		int surplus=xp-(Darwin->expMaxDuNiveau-Darwin->expActuelle);
		lvlUp(Darwin);
		gainXp(Darwin,surplus);
	}
	else {
		Darwin->expActuelle+=xp;
	}

}

void lvlUp(Personnage* Darwin)
{

	Darwin->lvl+=1;

	//Augmentation des caractéritiques
	Darwin->expActuelle=0;
	Darwin->expMaxDuNiveau*=1.2;
	Darwin->vieMax*=1.2;
	Darwin->vodkaMax*=1.2;

	//Augmentation des stats
	Darwin->force*=1.2;
	Darwin->agilite*=1.2;
	Darwin->courage*=1.2;
	Darwin->initiative*=1.2;

	//Remise a niveau de la vie et de la vodka
	Darwin->vieCourante=Darwin->vieMax;
	Darwin->vodkaCourante=Darwin->vodkaMax;
}

void initPerso(Personnage* Darwin)
{
	Darwin->lvl=1;

	//Caractéristiques primaires
	Darwin->vieMax=20;
	Darwin->vieCourante=20;
	Darwin->vodkaCourante=20;
	Darwin->vodkaMax=20;
	Darwin->expActuelle=0;
	Darwin->expMaxDuNiveau=100;

	//Caractéristique secondaires
	Darwin->force=5;
	Darwin->agilite=5;
	Darwin->courage=5;
	Darwin->initiative=5;

	Darwin->coord.x = int_rand(0,79);
	Darwin->coord.y = int_rand(0,79);

	Darwin->equip=liste.new(NULL);
	Darwin->equip->head=&(Darwin->equip);

}

void recevoirDegat(Personnage* Darwin, int degat)
{
	if(Darwin->vieCourante<=degat)
	{
		Darwin->vieCourante=0;
		printf("Vous avez perdu, vos points de vie sont a zéro\n");
		exit(0);
	}
	else {
		Darwin->vieCourante-=degat;
		printf("Vous venez de prendre %i degats, il vous reste %i points de vie\n",degat,Darwin->vieCourante);
	}
}

void mangerOuBoire(Personnage* Darwin,Potion* p)
{
	switch(p->effet)
	{
		case soin:
			if(Darwin->vieCourante+p->valeur>=Darwin->vieMax)
				Darwin->vieCourante=Darwin->vieMax;
			else
				Darwin->vieCourante+=p->valeur;
		break;

		case vodka:
			if(Darwin->vodkaCourante+p->valeur>=Darwin->vodkaMax)
				Darwin->vodkaCourante=Darwin->vodkaMax;
			else
				Darwin->vodkaCourante+=p->valeur;
		break;
	}
}

void attaquerPnj(Personnage* Darwin, Pnj* mob)
{
	if(mob->combattable)
	{
		setVie(mob,-(genererAleatoire(Darwin->agilite, Darwin->agilite+Darwin->force, 0)));
	}
	else
	{
		printf("Ce personnage ne peut pas être combattu\n");
	}
}


/*void lancerSort(Personnage* Darwin, Pnj* mob)
{
	attaquerPnjAvecSort(Darwin,mob);
}

void attaquerPnjAvecSort(Personnage* Darwin, Pnj* mob)
{
	Darwin->sort-=Darwin->sort->conso;
}
*/
