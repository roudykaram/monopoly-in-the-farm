#include "Couleur.h"
#include "Case.h"
#include "Joueur.h"
#include<iostream>


using namespace std;
#ifndef _CASEPROPRIETE_H
#define _CASEPROPRIETE_H


class CasePropriete : public Case{

    private:


        int prix; // prix du terrain
        int proprio;
        int loyer; // loyer  que l'adversaire paye s'il arrive sur cette case
        int nb_arbre;
        int nb_jardin;


    public:

        /**
         * @brief Constructeur par defaut de CasePropriete
         * 
         */
        CasePropriete();

        /**
         * @brief Constructeur par copie de CasePropriete 
         * le prix du terrain qui change pas 
         * le loyer qui commence a une valeur et qui augmente en fonction de nb arbre et jardin 
         * nb arbre/ jardin sur le terrain  
         * nb arbre max sur chaque terrain 
         *  
         * @param p 
         * @param l 
         * @param j 
         * @param arb 
         * @param jard 
         */
        CasePropriete(int prix_achat, int pos, std::string type, int l, int proprietaire, int arb, int jard); 
        
        /**
         * @brief Destructeur de CasePropriete
         * 
         */
        ~CasePropriete();
        
        /**
         * @brief Accesseur de prix
         * 
         * @return int 
         */
        int get_prix()const;

        /**
         * @brief Mutateur de prix
         * 
         * @param x 
         */
        void set_prix(unsigned int x);

        /**
         * @brief Accesseur de loyer
         * 
         * @return int 
         */
        int get_loyer()const;
    

        /**
         * @brief Mutateur de loyer
         * 
         * @param nouveau_montant 
         */
        void set_loyer(int nouveau_montant); 

        
        /**
         * @brief calcule le nouveau loyer en fonction du nombre d'arbres et de jardins
         * 
         * @return int 
         */
        int calculer_loyer();

        /**
         * @brief Accesseur de proprio
         * 
         * @return int 
         */
         virtual int get_proprio() const;

       
        /**
         * @brief Mutateur de proprio
         * 
         * @param i 
         */
        virtual void set_proprio(int i);

        /**
         * @brief Mutateur de nb_arbre
         * 
         * @param i 
         */
        virtual void set_nb_arbre(int i);

        /**
         * @brief Accesseur de nb_arbre
         * 
         * @return int 
         */
        virtual int get_nb_arbre()const;

        /**
         * @brief Mutateur de nb_jardin
         * 
         * @param i 
         */
        virtual void set_nb_jardin(int i);
        
        /**
         * @brief Accesseur de nb_jardin
         * 
         * @return int 
         */
        virtual int get_nb_jardin()const;


};

#endif