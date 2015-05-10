#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "defines.h"
#include "gestion_map.h"
#include "gen_map.h"

#include <setjmp.h>
#include "perso/affichage.h"

jmp_buf env;

int main(int argc,char* argv[])
{

    srand(time(NULL));

    int sortir = 1;
    map_t * MapTest;
    int ** echantest;

    Personnage Darwin;

    map_creer(&MapTest, 80, 80);
    Matrice_Remplir(&MapTest);
    mat_echantillon_creer(&echantest);

    coordonnees c1 = {1,1};

    generer_exterieur(&MapTest);
    Matrice_Echantilloner(&echantest, MapTest,c1);

    while(sortir)
    {
        initPerso(&Darwin);

        if(MapTest->matrice_map[Darwin.coord.y][Darwin.coord.x].bloquant != 1)
            sortir = 0;
    }

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Surface * ecran = NULL;
    SDL_Surface * tile = NULL;
    SDL_Event event;

	int iFlag=0;
    int continuer = 1;
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;
    ecran = SDL_SetVideoMode(800,640,32,SDL_SWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("RPG", NULL);
	int rafraichir=1;
    while(continuer)
    {

        int i = 0, j = 0;
        Matrice_Echantillon_Position_Calculer(MapTest, Darwin, &c1);

        SDL_PollEvent(&event);
		if(iFlag==1)
		{
			inventoryEvent(ecran,&Darwin,event);
		}
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_UP && iFlag!=1)
                {

                    if(Darwin.coord.y > 0 && MapTest->matrice_map[Darwin.coord.y-1][Darwin.coord.x].bloquant != 1)
                    {
                        Darwin.coord.y--;
                        rafraichir=1;

                        Matrice_Echantillon_Position_Calculer(MapTest, Darwin, &c1);
                    }
                }
                else if(event.key.keysym.sym == SDLK_DOWN && iFlag!=1)
                {
                    if(Darwin.coord.y < MapTest->taille_y-1 && MapTest->matrice_map[Darwin.coord.y+1][Darwin.coord.x].bloquant != 1)
                    {
                        Darwin.coord.y++;
                        rafraichir=1;

                        Matrice_Echantillon_Position_Calculer(MapTest, Darwin, &c1);
                    }
                }
				else if(event.key.keysym.sym == SDLK_i && iFlag!=1)
                {
					iFlag=1;
					afficherInventaire(ecran, &Darwin, event);
                }
                else if(event.key.keysym.sym == SDLK_LEFT && iFlag!=1)
                {
                        if(Darwin.coord.x > 0 && MapTest->matrice_map[Darwin.coord.y][Darwin.coord.x-1].bloquant != 1)
                        {
                            Darwin.coord.x--;
                            rafraichir=1;

                            Matrice_Echantillon_Position_Calculer(MapTest, Darwin, &c1);
                        }
                }
                else if(event.key.keysym.sym == SDLK_RIGHT && iFlag!=1)
                {
                    if(Darwin.coord.x < MapTest->taille_x-1 && MapTest->matrice_map[Darwin.coord.y][Darwin.coord.x+1].bloquant != 1)
                    {
                        Darwin.coord.x++;
                        rafraichir=1;
                        Matrice_Echantillon_Position_Calculer(MapTest, Darwin, &c1);
                    }

                }
				else if(event.key.keysym.sym == SDLK_ESCAPE && iFlag==1)
                {
                    iFlag=0;
					rafraichir=1;
                }
				break;
        }
		if(rafraichir==1 && iFlag!=1)
		{
			Matrice_Echantilloner(&echantest, MapTest,c1);

			for(j=0;j<20;j++)
			{
				for(i=0;i<25;i++)
				{
					switch(echantest[j][i])
					{
						/*case 1 :tile = SDL_LoadBMP("gfx/1.bmp");break;
						case 2 :tile = SDL_LoadBMP("gfx/2.bmp");break;
						case 4 :tile = SDL_LoadBMP("gfx/4.bmp");break;
						case 5 :tile = SDL_LoadBMP("gfx/5.bmp");break;
						case 6 :tile = SDL_LoadBMP("gfx/6.bmp");break;*/

                        case 1 :tile = IMG_Load("gfx/1.bmp");break;
						case 2 :tile = IMG_Load("gfx/2.bmp");break;
						case 4 :tile = IMG_Load("gfx/4.bmp");break;
						case 5 :tile = IMG_Load("gfx/5.bmp");break;
						case 6 :tile = IMG_Load("gfx/6.bmp");break;
					}
					positionFond.x = i*32;
					positionFond.y = j*32;
					SDL_BlitSurface(tile, NULL, ecran, &positionFond);

				}
			}
			if((Darwin.coord.x >= c1.x && Darwin.coord.y >= c1.y) && (Darwin.coord.x < c1.x+25 && Darwin.coord.y < c1.y+20) && iFlag!=1)
            {
                positionFond.x = (Darwin.coord.x-c1.x)*32;
                positionFond.y = (Darwin.coord.y-c1.y)*32;
                //tile = SDL_LoadBMP("gfx/10.bmp");
                tile = IMG_Load("gfx/10.png");
                SDL_BlitSurface(tile, NULL, ecran, &positionFond);
            }
			if(!iFlag)
			SDL_Flip(ecran);
			rafraichir=0;
		}
    }

    mat_echantillon_detruire(&echantest);
    map_detruire(&MapTest);

    return 0;
}





