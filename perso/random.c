#include "common.h"

int base=0;

int genererAleatoire(int minValue, int maxValue, int scale)
{
    const int BASE_MAX = 1000000;
    int random_number;
    srand ( time(NULL)+ base );
    random_number = rand() % (maxValue - minValue ) + scale;
    random_number += minValue;
	random_number=(random_number<maxValue)?random_number:maxValue;
    base++;
    if(base==BASE_MAX) base =0;
    return random_number;
}
