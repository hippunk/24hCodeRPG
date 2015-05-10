#include "gestion_map.h"

void map_creer(map_t ** Map, int taillex, int tailley)
{
    int i = 0;

    (*Map) = malloc(sizeof(map_t));

    (*Map)->taille_x = taillex;
    (*Map)->taille_y = tailley;

    (*Map)->matrice_map = malloc(sizeof(element_map_t*)*tailley);

    for(i = 0; i < tailley; i++)
        (*Map)->matrice_map[i] = malloc(sizeof(element_map_t)*taillex);
}

void map_detruire(map_t ** Map)
{
        int i = 0;

    for(i = 0; i < (*Map)->taille_y; i++)
        free((*Map)->matrice_map[i]);

    free((*Map)->matrice_map);
    free(*Map);
    *Map = NULL;
}

void mat_echantillon_creer(int *** MatEchantillon)
{
    int i = 0;

    (*MatEchantillon) = malloc(sizeof(int*)*20);

    for(i = 0; i < 20; i++)
        (*MatEchantillon)[i] = malloc(sizeof(int)*25);
}

void mat_echantillon_detruire(int *** MatEchantillon)
{
    int i = 0;

    for(i = 0; i < 20; i++)
        free((*MatEchantillon)[i]);

    free((*MatEchantillon));
    *MatEchantillon = NULL;
}

void Matrice_Remplir(map_t ** Map)
{

    int i = 0,j = 0;

    for(j = 0; j < (*Map)->taille_y; j++)
        for(i = 0; i < (*Map)->taille_x; i++)
        {
            (*Map)->matrice_map[j][i].couche = 0;
            (*Map)->matrice_map[j][i].bloquant = 0;
            (*Map)->matrice_map[j][i].sprite = 0;
            (*Map)->matrice_map[j][i].script = 0;
        }

}

void mat_echantillon_remplir(int *** MatEchantillon)
{

    int i = 0,j = 0;

    for(j = 0; j < 20; j++)
        for(i = 0; i < 25; i++)
        {
            (*MatEchantillon)[j][i] = 0;
        }

}

void Matrice_Afficher(map_t * Map)
{

    int i = 0,j = 0;

    for(j = 0; j < Map->taille_y; j++)
    {
        for(i = 0; i < Map->taille_x; i++)
            printf("%i", Map->matrice_map[j][i].sprite);
        printf("\n");
    }

}

void Matrice_Echantilloner(int *** MatEchantillon, map_t * Map, coordonnees debut)
{
    int i = 0,j = 0;

        for(j = 0; j < 20; j++)
        {
            for(i = 0; i < 25; i++)
            {
                (*MatEchantillon)[j][i] = Map->matrice_map[debut.y+j][debut.x+i].sprite;
            }
        }
}

void Matrice_Echantillon_Afficher(int ** MatEchantillon)
{
    int i = 0,j = 0;

        for(j = 0; j < 20; j++)
        {
            for(i = 0; i < 25; i++)
                printf("%i", MatEchantillon[j][i]);
            printf("\n");
        }
}

void Matrice_Echantillon_Position_Calculer(map_t * Map, Personnage perso, coordonnees * coord)
{
    if(perso.coord.x >= 0 && perso.coord.x < 12 && perso.coord.y >= 0 && perso.coord.y < 10)
    {
                coord->x = 0;
                coord->y = 0;
    }
    else if(perso.coord.x >= 12 && perso.coord.x < Map->taille_x-12 && perso.coord.y >= 0 && perso.coord.y < 10)
    {
                coord->x = perso.coord.x-12;
                coord->y = 0;
    }
    else if(perso.coord.x >= Map->taille_x-12 && perso.coord.x < Map->taille_x && perso.coord.y >= 0 && perso.coord.y < 10)
    {
                coord->x = Map->taille_x-25;
                coord->y = 0;
    }



    else if(perso.coord.x >= 0 && perso.coord.x < 12 && perso.coord.y >= 10 && perso.coord.y < Map->taille_y-10)
    {
                coord->x = 0;
                coord->y = perso.coord.y-10;
    }
    else if(perso.coord.x >= 12 && perso.coord.x < Map->taille_x-12 && perso.coord.y >= 10 && perso.coord.y < Map->taille_y-10)
    {
                coord->x = perso.coord.x-12;
                coord->y = perso.coord.y-10;
    }
    else if(perso.coord.x >= Map->taille_x-12 && perso.coord.x < Map->taille_x && perso.coord.y >= 10 && perso.coord.y < Map->taille_y-10)
    {
                coord->x = Map->taille_x-25;
                coord->y = perso.coord.y-10;
    }



    else if(perso.coord.x >= 0 && perso.coord.x < 12 && perso.coord.y >= Map->taille_y-10 && perso.coord.y < Map->taille_y)
    {
                coord->x = 0;
                coord->y = Map->taille_y-20;
    }
    else if(perso.coord.x >= 12 && perso.coord.x < Map->taille_x-12 && perso.coord.y >= Map->taille_y-10 && perso.coord.y < Map->taille_y)
    {
                coord->x = perso.coord.x-12;
                coord->y = Map->taille_y-20;
    }
    else if(perso.coord.x >= Map->taille_x-12 && perso.coord.x < Map->taille_x && perso.coord.y >= Map->taille_y-10 && perso.coord.y < Map->taille_y)
    {
                coord->x = Map->taille_x-25;
                coord->y = Map->taille_y-20;
    }
}
