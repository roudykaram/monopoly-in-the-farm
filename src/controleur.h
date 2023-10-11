#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "Jeu.h"

/**
 * @brief Prend les coordonnees du clic et renvoie une valeur aleatoire de de si 
 * les coordonnees correspondent a celle de l'image du de
 * 
 * @param event 
 * @param jeu 
 * @param de_rect 
 * @return unsigned int 
 */
unsigned int clic(SDL_Event event , Jeu &jeu, SDL_Rect de_rect);

/**
 * @brief Prend le clic de souris et met le booleen bouton_start a true si les
 * coordonnees du clic correspondent a celle du bouton start
 * 
 * @param event 
 * @param bouton_start 
 */
void clic_bouton_start(SDL_Event event , bool &bouton_start);

/**
 * @brief Prend la touche appuyee sur le clavier et retourne true si on a appuyer
 * sur Y ou sur N
 * 
 * @param event 
 * @return true 
 * @return false 
 */
bool bouton(SDL_Event event);