#include "common.h"
#include "perso.h"
#include "pnj.h"

void initPnj(Pnj * mob, coordonnees spawn_location, string inom, int hp_max, int mp_max, int lvl, int combattable)
{
    mob->coord = spawn_location;
    mob->nom = inom;
    mob->vie_max = hp_max;
    mob->vodka_max = mp_max;
    mob->vie = mob->vie_max;
    mob->vodka_courante = mob->vodka_max;
    mob->niveau = lvl;
    mob->combattable = combattable;
    mob->force = 5 + lvl * 1.2;
    mob->courage = 5 + lvl * 1.2;
    mob->agilite = 5 + lvl * 1.2;
    mob->initiative = 5 + lvl * 1.2;
    mob->etat = 0;
}

void attaquer(Pnj * mob, Personnage * cible, int degats, int effet)
{
    recevoirDegat(cible, degats);
    //cible->setEtat(effet);

}

void setNom(Pnj * mob, string inom)
{
    mob->nom = inom;
}

void setVie(Pnj * mob, int qte)
{
    mob->vie = mob->vie + qte;
    if(mob->vie <= qte)
    {
        mob->mort = 1; // mort
        printf(mob->nom, " est mort !");
    }
    if(mob->vie > mob->vie_max)
    {
        mob->vie = mob->vie_max; // empeche de depasser vie max
    }
}

void setVodka(Pnj * mob, int qte)
{
    mob->vodka_courante = mob->vodka_courante + qte;
}

void setCoord(Pnj * mob, coordonnees newPosition)
{
    mob->coord = newPosition;
}

void setCourage(Pnj * mob, int newCourage)
{
    mob->courage = newCourage;
}

void setAgilite(Pnj * mob, int newAgil)
{
    mob->agilite = newAgil;
}

void setEtat(Pnj * mob, int newEtat)
{
    mob->etat = newEtat;
}

void setInitiative(Pnj * mob, int newInit)
{
    mob->initiative = newInit;
}

string getNom(Pnj * mob)
{
    return mob->nom;
}

int getVie(Pnj * mob)
{
    return mob->vie;
}

int getVodka(Pnj * mob)
{
    return mob->vodka_courante;
}

coordonnees getCoord(Pnj * mob)
{
    return mob->coord;
}

int getCourage(Pnj * mob)
{
    return mob->courage;
}

int getAgilite(Pnj * mob)
{
    return mob->agilite;
}

int getEtat(Pnj * mob)
{
    return mob->etat;
}

int getInitiative(Pnj * mob)
{
    return mob->initiative;
}