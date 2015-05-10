/*
 *  perso.h
 *  DarDream
 *
 *  Created by Jérémy on 18/01/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */


void gainXp(Personnage* Darwin, int xp);
void lvlUp(Personnage* Darwin);
void initPerso(Personnage* Darwin);
void recevoirDegat(Personnage* Darwin, int degat);
void mangerOuBoire(Personnage* Darwin,Potion* p);