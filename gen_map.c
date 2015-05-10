#include "defines.h"
#include "gen_map.h"

void generer_exterieur(map_t ** Map)
{
    point_gen_t ** genematrice = NULL;
    coordonnees mat_taille = {(*Map)->taille_x,(*Map)->taille_y};

    genematrice_creer(&genematrice, mat_taille);
    zeroter(&genematrice, mat_taille);
    genematrice_generer(&genematrice, mat_taille);

    //genematrice_affiche(genematrice, mat_taille);
    genematrice_copier_map(genematrice, Map);
    genematrice_detruire(&genematrice, mat_taille);
}

void genematrice_creer(point_gen_t *** genematrice, coordonnees mat_taille)
{
    int i;

    (*genematrice) = malloc(sizeof(point_gen_t*)*mat_taille.y);

    for(i = 0; i < mat_taille.y; i++)
        (*genematrice)[i] = malloc(sizeof(point_gen_t)*mat_taille.x);
}

void genematrice_generer(point_gen_t *** genematrice, coordonnees mat_taille)
{


    printf("Generation de la map en cour\n");

    int i = 0, j = 0,k = 0;
    int a = 0, b = 0;
    int nb_forets = int_rand(1,3);
    int nb_lacs = int_rand(0,2);
    int nb_montagnes = int_rand(1,2);
    int nb_deserts = int_rand(1,1);

    printf("Placement des elements\n");

    //Boucle de placement
    //foret
    for(i = 0;i < nb_forets;i++)
    {
        a = int_rand(0,mat_taille.y-1);
        b = int_rand(0,mat_taille.x-1);

        (*genematrice)[a][b].type = 2;
        (*genematrice)[a][b].seedluck = 80;
    }
    //lac
    for(i = 0;i < nb_lacs;i++)
    {
        a = int_rand(0,mat_taille.y-1);
        b = int_rand(0,mat_taille.x-1);

        (*genematrice)[a][b].type = 6;
        (*genematrice)[a][b].seedluck = 80;
    }
    //montagne
    for(i = 0;i < nb_montagnes;i++)
    {
        a = int_rand(0,mat_taille.y-1);
        b = int_rand(0,mat_taille.x-1);

        (*genematrice)[a][b].type = 4;
        (*genematrice)[a][b].seedluck = 70;
    }
    //desert
    for(i = 0;i < nb_deserts;i++)
    {
        a = int_rand(0,mat_taille.y-1);
        b = int_rand(0,mat_taille.x-1);

        //emplacement de test
        /*a = 5;
        b = 5;*/

        (*genematrice)[a][b].type = 5;
        (*genematrice)[a][b].seedluck = 90;
    }

    printf("Propagation des elements...\n");

    //test a la con
    /*    int caca = 0;
        int popo = 0;
        for(caca = 0; caca < 10; caca++)
        {
            popo = int_rand(1,10);
            printf(" caca : %i bon caca : %i\n",popo,popo <= 9);
        }*/



    //propagation
    for(k=100/*seedluck max*/;k > 0 ;k--)//=k/2+k/4)
    {
        //printf("K = %i\n", k);
        for(j = 0;j < mat_taille.y;j++)
        {
            for(i = 0;i < mat_taille.x;i++)
            {
                if((*genematrice)[j][i].seedluck == k)
                {
                    //printf("passage par desert %i %i\n", k, 5 >= k);
                    if(int_rand(1,100) <= k && j-1 >= 0)// && (*genematrice)[j-1][i].type == 0)
                    {
                        //printf("propagation du desert\n");
                        (*genematrice)[j-1][i].type = (*genematrice)[j][i].type;
                        (*genematrice)[j-1][i].seedluck = (*genematrice)[j][i].seedluck-1;
                    }
                    else if(j-1 >= 0)
                    {
                        //printf("bouyou\n");
                        (*genematrice)[j-1][i].seedluck = 0;
                    }

                    if(int_rand(1,100) <= k && i+1 < mat_taille.x)// && (*genematrice)[j-1][i].type == 0)
                    {
                        (*genematrice)[j][i+1].type = (*genematrice)[j][i].type;
                        (*genematrice)[j][i+1].seedluck = (*genematrice)[j][i].seedluck-1;
                    }
                    else if(i+1 < mat_taille.x)
                    {
                        (*genematrice)[j][i+1].seedluck = 0;
                    }

                    if(int_rand(1,100) <= k && j+1 < mat_taille.y)// && (*genematrice)[j-1][i].type == 0)
                    {
                        (*genematrice)[j+1][i].type = (*genematrice)[j][i].type;
                        (*genematrice)[j+1][i].seedluck = (*genematrice)[j][i].seedluck-1;
                    }
                    else if(j+1 < mat_taille.y)
                    {
                        (*genematrice)[j+1][i].seedluck = 0;
                    }

                    if(int_rand(1,100) <= k && i-1 >= 0)// && (*genematrice)[j-1][i].type == 0)
                    {
                        (*genematrice)[j][i-1].type = (*genematrice)[j][i].type;
                        (*genematrice)[j][i-1].seedluck = (*genematrice)[j][i].seedluck-1;
                    }
                    else if(i-1 >= 0)
                    {
                        (*genematrice)[j][i-1].seedluck = 0;
                    }
                }
            }
        }
    }

    printf("Mise en plaine\n");

    //Mise en plaine
    for(j = 0;j < mat_taille.y;j++)
    {
        for(i = 0;i < mat_taille.x;i++)
        {
            if((*genematrice)[j][i].type == 0)
                (*genematrice)[j][i].type = 1;
        }
    }

    printf("Generation terminee\n");
}

void zeroter(point_gen_t *** genematrice, coordonnees mat_taille)
{
    int i = 0, j = 0;

    for(j=0;j < mat_taille.y;j++)
        for(i=0;i < mat_taille.x;i++)
        {
            (*genematrice)[j][i].type = 0;
            (*genematrice)[j][i].seedluck = 0;
        }
}

void genematrice_affiche(point_gen_t ** genematrice, coordonnees mat_taille)
{
    int i = 0, j = 0;

    for(j=0;j < mat_taille.y;j++)
    {
        for(i=0;i < mat_taille.x;i++)
        {
            printf("%i", genematrice[j][i].type);
            printf("%i ", genematrice[j][i].seedluck);
        }
        printf("\n");
    }
}



void genematrice_copier_map(point_gen_t ** genematrice, map_t ** Map)
{
    int i = 0, j = 0;

    for(j=0;j < (*Map)->taille_y;j++)
	{
		for(i=0;i < (*Map)->taille_x;i++)
		{
			(*Map)->matrice_map[j][i].sprite = genematrice[j][i].type;
			if(	genematrice[j][i].type == 4 || genematrice[j][i].type == 6)
			{
								(*Map)->matrice_map[j][i].bloquant = 1;
			}

		}

	}

}

void genematrice_detruire(point_gen_t *** genematrice, coordonnees mat_taille)
{
    int i = 0;

    for(i = 0; i < mat_taille.y; i++)
        free((*genematrice)[i]);

    free(*genematrice);

    *genematrice = NULL;
}
