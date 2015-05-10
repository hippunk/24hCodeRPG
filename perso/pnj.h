#ifndef PNJ_H_INCLUDED
#define PNJ_H_INCLUDED

void initPnj(Pnj * mob, coordonnees spawn_location, string inom, int hp_max, int mp_max, int lvl, int combattable);

void attaquer(Pnj * mob,Personnage *cible, int degats, int effet);

void setNom(Pnj * mob, string inom);

void setVie(Pnj * mob, int qte);

void setVodka(Pnj * mob, int qte);

void setCoord(Pnj * mob,coordonnees newPosition);

void setCourage(Pnj * mob,int newCourage);

void setAgilite(Pnj * mob,int newAgil);

void setEtat(Pnj * mob,int newEtat);

void setInitiative(Pnj * mob,int newInit);

string getNom(Pnj * mob);

int getVie(Pnj * mob);

int getVodka(Pnj * mob);

coordonnees getCoord(Pnj * mob);

int getCourage(Pnj * mob);

int getAgilite(Pnj * mob);

int getEtat(Pnj * mob);

int getInitiative(Pnj * mob);

#endif // PNJ_H_INCLUDED
