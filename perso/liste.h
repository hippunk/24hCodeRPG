/*
 *  liste.h
 *  DarDream
 *
 *  Created by Jérémy on 18/01/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

Liste New(void* donnee);
void precListe(Liste* li);
void suivListe(Liste* li);
void addListe(Liste* li,void* donnee);
void removeList(Liste* li);
void traitementDonnee(void* data,Liste* list);
void affichageDonnee(Liste li);
void rechercherIndex(Liste* li, int index);