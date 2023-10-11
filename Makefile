OBJ=obj/Plateau.o obj/Case.o obj/Joueur.o obj/Jeu.o obj/vue.o obj/controleur.o obj/Couleur.o obj/CasePropriete.o obj/CaseArgent.o obj/CaseRessources.o obj/CaseMystere.o
CC=g++
CFLAGS=-g -Wall
LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lGL

all: folders bin/monopoly bin/test

folders:
	mkdir -p obj bin data

bin/monopoly: $(OBJ) obj/main.o
	$(CC) $(OBJ) obj/main.o -o bin/monopoly $(LIBS_SDL)


bin/test: $(OBJ) obj/maintest.o
	$(CC) $(OBJ) obj/maintest.o -o bin/test $(LIBS_SDL)


obj/Couleur.o: src/Couleur.cpp src/Couleur.h
	$(CC) $(CFLAGS) -c src/Couleur.cpp -o obj/Couleur.o

obj/Plateau.o: src/Plateau.cpp src/Plateau.h src/Case.h src/CasePropriete.h src/Couleur.h src/CaseArgent.h src/CaseRessources.h src/CaseMystere.h
	$(CC) $(CFLAGS) -c src/Plateau.cpp -o obj/Plateau.o

obj/CasePropriete.o: src/CasePropriete.cpp 	src/CasePropriete.h src/Couleur.h src/Case.h src/Joueur.h
	$(CC) $(CFLAGS) -c src/CasePropriete.cpp -o obj/CasePropriete.o

obj/CaseArgent.o: src/CaseArgent.cpp src/CaseArgent.h src/Case.h
	$(CC) $(CFLAGS) -c src/CaseArgent.cpp -o obj/CaseArgent.o

obj/CaseRessources.o: src/CaseRessources.cpp src/CaseRessources.h src/Case.h
	$(CC) $(CFLAGS) -c src/CaseRessources.cpp -o obj/CaseRessources.o

obj/CaseMystere.o: src/CaseMystere.cpp src/CaseMystere.h src/Case.h
	$(CC) $(CFLAGS) -c src/CaseMystere.cpp -o obj/CaseMystere.o		

obj/Case.o: src/Case.cpp src/Case.h 
	$(CC) $(CFLAGS) -c src/Case.cpp -o obj/Case.o

obj/Jeu.o:src/Jeu.cpp src/Joueur.h src/Plateau.h
	$(CC) $(CFLAGS) -c src/Jeu.cpp -o obj/Jeu.o

obj/Joueur.o:src/Joueur.cpp src/Case.h
	$(CC) $(CFLAGS) -c src/Joueur.cpp -o obj/Joueur.o

obj/vue.o:src/vue.cpp src/vue.h src/Jeu.h
	$(CC) $(CFLAGS) -c src/vue.cpp -o obj/vue.o

obj/main.o: src/main.cpp src/Plateau.h src/Case.h src/vue.h src/Jeu.h
	$(CC) $(CFLAGS) -c src/main.cpp  -o obj/main.o

obj/maintest.o: src/maintest.cpp src/Plateau.h src/Case.h src/Jeu.h
	$(CC) $(CFLAGS) -c src/maintest.cpp  -o obj/maintest.o

obj/controleur.o:src/controleur.cpp src/controleur.h src/Jeu.h
	$(CC) $(CFLAGS) -c src/controleur.cpp -o obj/controleur.o
	
docs: doc/image.doxy
	doxygen doc/image.doxy

clean:
	rm -rf obj/* bin/* doc/html callgrind.out.*
