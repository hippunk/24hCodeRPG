# définition des variables
CC = gcc
CFLAGS = -O3 -lSDL -lSDL_image -lm

# désactivation des règles implicites
.SUFFIXES:



all: main.o gestion_map.o gen_map.o defines.o random.o perso.o pnj.o liste.o affichage.o
	$(CC) $(CFLAGS) main.o gestion_map.o gen_map.o defines.o perso/random.o perso/perso.o perso/pnj.o perso/liste.o perso/affichage.o -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

gestion_map.o: gestion_map.c
	$(CC) $(CFLAGS) -c gestion_map.c -o gestion_map.o 

gen_map.o: gen_map.c
	$(CC) $(CFLAGS) -c gen_map.c -o gen_map.o

defines.o: defines.c
	$(CC) $(CFLAGS) -c defines.c -o defines.o

random.o: perso/random.c
	$(CC) $(CFLAGS) -c perso/random.c -o perso/random.o

perso.o: perso/perso.c
	$(CC) $(CFLAGS) -c perso/perso.c -o perso/perso.o

pnj.o: perso/pnj.c 
	$(CC) $(CFLAGS) -c perso/pnj.c -o perso/pnj.o

liste.o: perso/liste.c 
	$(CC) $(CFLAGS) -c perso/liste.c -o perso/liste.o

affichage.o: perso/affichage.c
	$(CC) $(CFLAGS) -c perso/affichage.c -o perso/affichage.o


# suppression des fichiers temporaires
clean:
	rm -rf *.o perso/*.o
 
# suppression de tous les fichiers, sauf les sources,
# en vue d'une reconstruction complète
mrproper: clean
	rm -rf Programme
