#include "Plateau.h"
#include "vue.h"
#include "Jeu.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    Joueur joueur;
    joueur.testRegressionJoueur();

    Plateau p;
    p.testRegressionPlateau();

    Jeu j;
    j.testRegressionJeu();

}