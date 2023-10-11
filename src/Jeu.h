#include "Joueur.h"
#include "Plateau.h"


#ifndef _JEU_H
#define _JEU_H

class Jeu{

    private:
    Plateau* plateau;
    Joueur joueurs[2];
   unsigned int joueur_actuel;
    unsigned int  gagnant;

    public:

    /**
     * @brief Constructeur par defaut de Jeu
     * 
     */
    Jeu();

    /**
     * @brief Destructeur de Jeu
     * 
     */
    ~Jeu();

   
    /**
     * @brief retourne un entier aleatoire entre 1 et 6
     * 
     * @return unsigned int 
     */
    unsigned int jete_de();


    /**
     * @brief bouge le joueur actuel de x cases
     * 
     * @param x 
     */
    void bouge(int x); 

    
    /**
     * @brief alterne vers le Joueur suivant
     * 
     */
    bool tour_suivant();

    /**
     * @brief effectue tous les changements sur le Joueur lors du tour (achat, perte 
     * d'argent, de ressources, etc.) et retourne l'indice de la phrase a afficher sur la fenetre SDL
     * 
     * @param propriete_achetee 
     * @param non_achetee 
     * @return int 
     */
    int joue_tour(bool &propriete_achetee,bool &non_achetee);

    /**
     * @brief Retire les ressources convenables pour entretenir les arbres et jardins
     * Et si le joueur n'a pas assez de ressources, il tue les arbres et jardins selon le 
     * nombre de ressources qui manque (ex: s'il lui manque 1 eau et 1 soleil, 1 arbre est donc mort)
     * 
     * @param id 
     * @return int 
     */
    int arrose_arbre(unsigned int id);
    

    /**
     * @brief Accesseur au joueur_actuel
     * 
     * @return unsigned int
     */
    unsigned int getJoueurActuel()const;

    /**
     * @brief Accesseur au joueur dans le tableau de joueurs
     * 
     * @param id 
     * @return Joueur 
     */
    Joueur getJoueurs(int id) const;

    /**
     * @brief Mutateur de gagnant
     * 
     * @param i 
     */
    void set_gagnant(unsigned int i);

    /**
     * @brief Accesseur de gagnant
     * 
     * @return unsigned int 
     */
    unsigned int get_gagnant()const;


    /**
     * @brief Mutateur du Joueur_actuel
     * 
     * @param i 
     */
    void setJoueurActuel(unsigned int i);

    
    /**
     * @brief Accesseur de plateau
     * 
     * @return Plateau* 
     */
    Plateau* getPlateau() const;

    /**
     * @brief teste toutes les fonctions de Jeu grace aux asserts
     * 
     */
    void testRegressionJeu();

};

#endif

