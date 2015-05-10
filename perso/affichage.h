/*
 *  affichage.h
 *  DarDream
 *
 *  Created by Jérémy on 19/01/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

SDL_Surface* initSDL();
void afficherInventaire(SDL_Surface* screen,Personnage* Darwin,SDL_Event event);
void inventoryEvent(SDL_Surface* screen,Personnage* Darwin, SDL_Event event);