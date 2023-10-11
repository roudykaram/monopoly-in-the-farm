
#include "Case.h"
#include "CasePropriete.h"
#include "CaseArgent.h"
#include "CaseRessources.h"
#include "CaseMystere.h"
#include "Couleur.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef _PLATEAU_H
#define _PLATEAU_H

class Plateau{

    private:
    Case * cases[20]; // Tableau de pointeurs vers les 20 cases du plateau
    
    public:

    /**
     * @brief Constructeur de Plateau
     * 
     */
    Plateau ();

    /**
     * @brief Destructeur de Plateau
     * 
     */
    ~Plateau();

    /**
     * @brief Accesseur de cases[]
     * 
     * @param x 
     * @return Case& 
     */
    Case & getCase(unsigned int x) const;

    /**
     * @brief teste les fonctions de Plateau, Case, CaseMystere, CaseRessources, CaseArgent, CasePropriete
     * 
     */
    void testRegressionPlateau();

};

#endif