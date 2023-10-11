#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
//#include "CasePropriete.h"
#include "Case.h"

class CasePropriete;
#ifndef _JOUEUR_H
#define _JOUEUR_H

class Joueur {
    private:

    unsigned int id;
    unsigned int argent;
    int quantite_eau;
    int quantite_soleil;
    int nb_arbre;
    int nb_jardin;
    unsigned int position;
    public:

    Joueur();
    /**
     * @brief Constructeur de Joueur qui prend l'id en parametre
     * 
     * @param id 
     */
    Joueur(int id); 

    /**
    * @brief Destructeur de Joueur
    * 
    */
    ~Joueur();

    /**
     * @brief Accesseur de id
     * 
     * @return unsigned int 
     */
    unsigned int getid () const;

    /**
     * @brief Mutateur de id
     * 
     * @param id 
     */
    void setid (int id); 

    /**
     * @brief Accesseur de quantite_eau
     * 
     * @return int 
     */
    int  getEau () const;

    /**
     * @brief Accesseur de quantite_soleil
     * 
     * @return int 
     */
    int getSoleil () const;

    /**
     * @brief Accesseur de nb_arbre
     * 
     * @return int 
     */
    int get_nbarbre () const;

    /**
     * @brief Mutateur de nb_arbre
     * 
     * @param i 
     */
    void set_nbarbre(int i);

    /**
     * @brief Mutateur de nb_jardin
     * 
     * @param i 
     */
    void set_nbjardin(int i);
    
    /**
     * @brief Accesseur de nb_jardin
     * 
     * @return int 
     */
    int get_nbjardin () const;
    /**
     * @brief Accesseur pour avoir la valeur de argent
     * 
     * @return unsigned int 
     */
    unsigned int getArgent () const;

    
    /**
     * @brief Accesseur pour avoir la valeur de position
     * 
     * @return int 
     */
    unsigned int getPosition () const;

   
    /**
    * @brief Mutateur de la donnée membre eau
    * 
    * @param x 
    */
    void setEau (int x);
   
    /**
    * @brief Mutateur de la donnée membre soleil
    * 
    * @param x 
    */
    void setSoleil (int x);

    /**
    * @brief Mutateur de la donnée membre argent
    * 
    * @param x 
    */
    void setArgent (unsigned int x);

    /**
    * @brief Mutateur de la donnée membre position
    * 
    * @param x 
    */
    void setPosition (unsigned int x);

    /**
     * @brief teste toutes les fonctions de Joueur
     * 
     */
    void testRegressionJoueur();


   
};
#endif


