/*
 *  affichage.c
 *  DarDream
 *
 *  Created by Jérémy on 19/01/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */
#include "SDL/SDL_image.h"
#include "common.h"
#include "affichage.h"


static int nbItem=5;
static SDL_Surface** inventaire;
static SDL_Rect* position;
static int selected=0;

void afficherInventaire(SDL_Surface* screen, Personnage* Darwin, SDL_Event event)
{
	inventaire=malloc(sizeof(SDL_Surface*)*(nbItem*nbItem+5));
	position=malloc(sizeof(SDL_Rect)*(nbItem*nbItem+5));
	int i;
	(inventaire[0])=SDL_CreateRGBSurface(SDL_HWSURFACE, 800, 640, 32, 0, 0, 0, 0);
	SDL_FillRect(inventaire[0], NULL, SDL_MapRGB((inventaire[0])->format, 100, 100, 100));
	(position[0]).x = 264;
	(position[0]).y = 0;

	for(i=1;i<nbItem*nbItem+1;i++){
		inventaire[i]=SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50, 32, 0, 0, 0, 0);
		SDL_FillRect(inventaire[i], NULL, SDL_MapRGB(screen->format, 10, 10, 10));
		(position[i]).y = (int)floor((i+nbItem-1)/nbItem)*60+position[0].y;
		(position[i]).x = ((i-1)%nbItem+1)*60+position[0].x;
	}

	inventaire[29]=IMG_Load("/Volumes/Jey/DarDream/chapeau.png");
	inventaire[27]=IMG_Load("/Volumes/Jey/DarDream/chapeau.png");
	inventaire[26]=IMG_Load("/Volumes/Jey/DarDream/chapeau.png");
	inventaire[28]=IMG_Load("/Volumes/Jey/DarDream/blanc.png");


	for(i=nbItem*nbItem+1;i<nbItem*nbItem+5;i++){

		(position[i]).y = position[nbItem*(nbItem*nbItem+5-(i+1))].y+60;
		(position[i]).x = position[nbItem*nbItem].x+120;
	}

	for(i=0;i<nbItem*nbItem+5;i++){
		SDL_BlitSurface(inventaire[i], NULL, screen, &(position[i]));
	}

	SDL_Flip(screen);
	inventoryEvent(screen,Darwin,event);
}

void inventoryEvent(SDL_Surface* screen,Personnage* Darwin, SDL_Event event)
{
	printf("Transfert de l'événement\n");
	int done;
	int i;
	done = 0;
	Uint32 item;
	int u=-1;
	Darwin->equip->donnee=&u;
	for(i=1;i<nbItem*nbItem+5;i++)
	{
		item=(SDL_MapRGB(screen->format, 100*i, 10*i/2, 10*3*i));
		(Darwin->equip)->add(&(Darwin->equip),&item);
	}

			switch (event.type) {
				case SDL_MOUSEMOTION:
					for(i=1;i<nbItem*nbItem+1;i++)
					{
						if(event.motion.x<position[i].x+50 && event.motion.x>position[i].x && event.motion.y<position[i].y+50 && event.motion.y>position[i].y && selected!=i)
						{
							Liste li=Darwin->equip;
							(rechercherIndex((&li), i));
							item=*((Uint32*)(li->donnee));
							SDL_FillRect(inventaire[i], NULL, item);
						}
						else{
							if(selected!=i)
								SDL_FillRect(inventaire[i], NULL, SDL_MapRGB(screen->format, 10, 10, 10));
						}
						SDL_BlitSurface(inventaire[i], NULL, screen, &(position[i]));
					}
					SDL_Flip(screen);
					break;
				case SDL_MOUSEBUTTONDOWN:
					for(i=1;i<nbItem*nbItem+5;i++)
					{
						if(event.button.x<position[i].x+50 && event.button.x>position[i].x && event.button.y<position[i].y+50 && event.button.y>position[i].y)
						{
							if(selected!=0){
								echangeIndex(&(Darwin->equip), selected, i);
								selected=0;
							}
							else
								selected=i;
						}
					}
					break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
						done = 1;
						break;
				}
					break;

				case SDL_QUIT:
					done = 1;
					break;
				default:
					break;
			}
}
