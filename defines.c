#include "defines.h"
#include "perso/common.h"

int int_rand(int MIN, int MAX)
{
    int chiffre;

    chiffre = rand()%(MAX-MIN+1)+MIN;

    return chiffre;
}
