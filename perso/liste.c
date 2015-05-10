#include "common.h"

void traitementDonnee(void* donnee,Liste* li);
void affichageDonnee(Liste li);
void precListe(Liste* le);
void suivListe(Liste* le);
void addListe(Liste* le,void* donnee);
void removeList(Liste* li);

Liste New(void* donnee)
{//Création d'une nouvelle instance de liste
	Liste li;
	//Allocation et affectation des données

	li=malloc(sizeof(struct Liste_s));
	li->suivant=&suivListe;
	li->precedent=&precListe;
	li->add=&addListe;
	li->remove=&removeList;
	li->afficher=&affichageDonnee;
	li->index=1;
	//Déclaration du précédent et du suivant dans la liste
	li->suiv=NULL;
	li->prec=NULL;
	int defaut=-1;
	if(donnee==NULL)
		li->donnee=&defaut;
	else
		traitementDonnee(donnee,&li);
	li->head=&li;
	return li;
	
}

void rechercherIndex(Liste* li, int index){
	while((*li)->prec!=NULL)
	{
		(*li)=(*li)->prec;
	}
	while((*li)->suiv!=NULL && (*li)->index!=index)
	{
		printf("Je recherche %i\n",index);
		(*li)=(*li)->suiv;
		if((*li)->index==index)printf("J'ai trouvé\n");
	}
}

void echangeIndex(Liste* li, int index, int index2){
	while((*li)->prec!=NULL)
	{
		(*li)=(*li)->prec;
	}
	while((*li)->suiv!=NULL && (*li)->index!=index)
	{
		if((*li)->index==index)(*li)->index=index2;
		(*li)=(*li)->suiv;
		if((*li)->index==index2)(*li)->index=index;
	}
}

void precListe(Liste* li)
{
	if((*li)->prec!=NULL)
		(*li) = (*li)->prec;
}

void suivListe(Liste* li)
{
	if((*li)->suiv!=NULL)
		(*li) = (*li)->suiv;
}

void addListe(Liste* li,void* donnee)
{
	if(*((int*)(*li)->donnee)!=-1)
	{
		Liste tmp=malloc(sizeof(struct Liste_s));
		
		//traitement des données
		traitementDonnee(donnee,&tmp);
		tmp->suivant=&suivListe;
		tmp->precedent=&precListe;
		tmp->add=&addListe;
		tmp->remove=&removeList;
		tmp->afficher=&affichageDonnee;
		
		//Déclaration du précédent et du suivant dans la liste
		tmp->suiv=NULL;
		tmp->prec=(*li);
		tmp->index=(*li)->index+1;
		(*li)->suiv=tmp;
		(*li)=(*li)->suiv;
	}else{
		(*li)->donnee=donnee;
		(*li)->suivant=&suivListe;
		(*li)->precedent=&precListe;
		(*li)->add=&addListe;
		(*li)->remove=&removeList;
		(*li)->afficher=&affichageDonnee;
		(*li)->index=1;
		
		//Déclaration du précédent et du suivant dans la liste
		(*li)->suiv=NULL;
		(*li)->prec=NULL;
	}
}

void miseAjourDesIndex(Liste* li)
{
	(*li)->index=(*li)->prec->index+1;
	if((*li)->suiv!=NULL)
		miseAjourDesIndex(&((*li)->suiv));
}

void removeList(Liste* li)
{	
	Liste tmp=(*li);
	if((*li)->prec!=NULL && (*li)->suiv!=NULL){
		(*li)->suiv->prec=(*li)->prec;
		(*li)->prec->suiv=(*li)->suiv;
		miseAjourDesIndex(&(*li)->suiv);
	}
	else if((*li)->suiv!=NULL && (*li)->prec==NULL){
		(*li)->suiv->prec=NULL;
		(*li)->index=1;
		miseAjourDesIndex(&((*li)->suiv));
	}
	else if((*li)->suiv==NULL && (*li)->prec!=NULL)
		(*li)->prec->suiv=NULL;
	
	(*li)->suivant=NULL;
	(*li)->precedent=NULL;
	(*li)->add=NULL;
	(*li)->afficher=NULL;
	
	if((*li)->prec!=NULL)
		(*li)=(*li)->prec;
	else if((*li)->suiv!=NULL)
		(*li)=(*li)->suiv;
	else 
		(*li)=NULL;
	
	free(tmp);
	tmp=NULL;
}


void traitementDonnee(void* data,Liste* list)
{
	(*list)->donnee=data;
}



void affichageDonnee(Liste li)
{
	if(li==NULL)
		return;
	printf("%i\n",*((int*)(li->donnee)));
}