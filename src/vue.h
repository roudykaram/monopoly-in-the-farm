
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "Jeu.h"
#include"controleur.h"

    /**
     * @brief Charge les images du jeu dans images[]
     * 
     * @param renderer Pointeur vers le renderer SDL
     */
    void charger_images(SDL_Renderer* renderer,SDL_Texture* images[]);



    /**
     * @brief Dessine le plateau en utilisant les images des cases
     * 
     * @param x Position x du coin supérieur gauche du plateau
     * @param y Position y du coin supérieur gauche du plateau
     */
    void dessiner_plateau(SDL_Renderer* renderer,SDL_Texture* images[],int arbre_case[],int jardin_case[],unsigned int valeurde);
    
    /**
     * @brief Affiche la page d'accueil avec l'image d'accueil et l'image du bouton start
     * 
     * @param renderer 
     * @param images 
     */
    void dessiner_pageaccueil(SDL_Renderer* renderer,SDL_Texture* images[]);
    
    /**
     * @brief Affiche la photo du gagnant sur l'ecran: photo d'un trophee avec un background rouge pour le
     * joueur 0, et une photo d'un trophee avec un background bleu pour le joueur 1
     * 
     * @param renderer 
     * @param images 
     * @param gagnant 
     */
    void afficher_gagnant(SDL_Renderer* renderer,SDL_Texture* images[],unsigned int gagnant); 

     /**
      * @brief Affiche les pions sur l'ecran
      * 
      * @param renderer 
      * @param images 
      * @param p1 
      * @param p2 
      */
    void afficher_joueur (SDL_Renderer* renderer,SDL_Texture* images[],Joueur p1, Joueur p2);

     /**
      * @brief affiche les infos sur les joueurs: leur montant total, leur nombre d'arbres...
      * 
      * @param renderer 
      * @param j 
      * @param x 
      * @param y 
      * @param c 
      */
    void afficher_info(SDL_Renderer * renderer,Joueur j,int x, int y,SDL_Color c);

     /**
      * @brief Affiche la phrase "la valeur du de est :" avec la valeur sur la Fenetre SDL
      * 
      * @param renderer 
      * @param val_de 
      * @param x 
      * @param y 
      * @param c 
      */
    void afficher_val_de(SDL_Renderer * renderer,unsigned int val_de,int x, int y,SDL_Color c);

     /**
      * @brief Charge la question selon l'indice donne en parametre 
      * 
      * @param renderer 
      * @param indice 
      * @param c 
      * @param nb_arbre_avant 
      * @param nb_arbre_apres 
      * @param nb_jardin_avant 
      * @param nb_jardin_apres 
      */
    void charger_questions(SDL_Renderer* renderer,unsigned int indice,SDL_Color c,int nb_arbre_avant,int nb_arbre_apres,int nb_jardin_avant,int nb_jardin_apres);

     /**
      * @brief appel la fonction charger_questions et change la couleur de la question selon l'indice de la question
      * 
      * @param renderer 
      * @param bouton_y_n 
      * @param question 
      * @param nb_arbre_avant 
      * @param nb_arbre_apres 
      * @param nb_jardin_avant 
      * @param nb_jardin_apres 
      */
    void appel_questions(SDL_Renderer* renderer,bool bouton_y_n, int question,int nb_arbre_avant,int nb_arbre_apres,int nb_jardin_avant,int nb_jardin_apres);
