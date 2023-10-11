KARAM Roudy 12018275

AZIZ Jane 12102430

PROJECT ID : 28484

 

Notre projet est un jeu de Plateau qui ressemble au concept de Monopoly mais revisité. On 4 types de cases:

des Cases Argent où le joueur peut gagner ou perdre 200 euros, des Cases Ressources où le joueur peut gagner ou perdre 2 unitées de soleil et d'eau, les Cases Mystere ou le Joueur peut gagner ou perdre un nombre aléatoire de ressources entre 0 et 3 unités, et les Cases Propriétée que le Joueur achète et sur lesquelles il peut planter des arbres ou un jardin s'il a déjà planter 3 arbres sur ce terrain. Et pour garder les arbres et jardins en vie, il faut les entretenir en les arrosant et en leur donnant du soleil. Au bout de 10 tours les 2 joueurs doivent dépenser des ressources sur leurs arbres et jardins pour les garder (1 unitée d'eau et de soleil pour un arbre et 4 pour un jardin). Et s'il n'a pas les ressources suffisantes, il perd les arbres ou jardins qu'il n'a pas pu arroser et entretenu.

Plus un terrain contient des arbres ou jardin, plus la taxe de passage de ce terrain augmente (comme le concept des maisons et hotel pour monopoly).

La première personne à ne plus avoir d'argent perd et le joueur adverse sera nommé le gagnant.

 

Fonctionnalités avec clavier/souris:

-cliquer sur le dé avec la souris

-acheter un terrain, un arbre ou un jardin en répondant par oui ou non (en tapant Y ou N sur le clavier)

 

 

Pour ce projet on a implémenté 8 classes:

-Case: Classe mère des autres cases.

-CasePropriete, CaseRessources, CaseArgent, CaseEnigme qui sont des heritages de Case.

-Jeu: qui contient le plateau les 2 joueurs ainsi que les indices du joueur_actuel et du gagnant, et toutes les fonctions relatives au déroulement du Jeu.

-Joueur: avec ses données membres (id, argent, nb_eau...) et fonctions

-Plateau:qui contient les 20 cases du plateau

 

 

 

Le zip 12102430_12018275 contient le fichier README.txt, le fichier makefile, et les dossiers bin, src, obj, data et doc.

 

Le dossier bin contient les executables (monopoly, test) créés par le makefile.

 

                monopoly: qui va executer le jeu avec tous les affichages dans une fenetre SDL2.

 

                test: exécute le fichier maintest.cpp qui fait appel à la fonction testRegression qui va tester les fonctions membres de nos classes et verifie si tout est conforme.

               

 

               

Le dossier src contient les fichiers sources (.cpp .h) dont ceux des classes et également le main.cpp, maintest.cpp, vue.cpp et controleur.cpp (et leur .h).

Le dossier obj contient les fichiers (.o).

Le dossier data contient les images qu'on utilisent pour notre plateau de jeu et notre menu d'accueil

ainsi que le ttf pour le font de SDL2.

Le dossier doc contient la documentation doxygen (dans doc/html), le PowerPoint de soutenance ainsi que le cahier de charge (avec UML et Gantt).

 

 

Quoi installer?

 

Il est indispensable de télecharger la librairie SDL2 (image, ttf et mixer) si vous ne l'avez pas déjà

sur votre machine.

 

Comment compiler?

 

Pour compiler, il faut se situer dans le dossier 12102430_12018275 (où se trouve les fichiers du code) et il faut dans le terminal, lancer la commande 'make' qui fait appel au makefile.

Valgrind, aussi nous permet de trouver les erreurs d'allocations ou de pertes de mémoire dans notre code avec la commande $> valgrind --tool=memcheck --leak-check=full (suivi du

chemin de notre executable)

A l'aide de gdb, on va pouvoir aussi voir les erreurs et débuguer notre code.

 

Comment exécuter ?

 

Dans le terminal on se positionne dans le dossier 12102430_12018275 où se trouve le makefile et on exécute bin/monopoly ou bin/test, en fonction du fichier qu'on veut exécuter.
