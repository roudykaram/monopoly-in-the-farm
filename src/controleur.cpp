#include <iostream>
#include "controleur.h"

using namespace std;

unsigned int clic(SDL_Event event , Jeu &jeu, SDL_Rect de_rect){
    int x=event.motion.x;
    int y=event.motion.y;
    int val_de =0;

    //si les coordonnees du clic sont celle de la photo du de
    if(x>= de_rect.x && x<=de_rect.x + de_rect.w && y<= de_rect.y + de_rect.h && y>=de_rect.y ){
        val_de=jeu.jete_de();
        cout<<"la valeur du de est"<<val_de<<endl;  
    }
    return val_de;
    
}

void clic_bouton_start(SDL_Event event , bool &bouton_start){
    int x=event.motion.x;
    int y=event.motion.y;

    //si les coordonnees du clic sont celle du bouton start
    if(x>= 400 && x<=700 && y<= 560 && y>=400 ){
        bouton_start=true;
    }
    
}

bool bouton(SDL_Event event){
    
    bool bouton_y_n=false;
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_KEYDOWN){
            SDL_Keycode keyCode = event.key.keysym.sym;
            if (keyCode == SDLK_y){
                bouton_y_n=true;
                cout<<"Vous avez appuyer sur Y"<<endl;
                return bouton_y_n;
            }

            else if (keyCode == SDLK_n){
                bouton_y_n=true;
                cout<<"Vous avez appuyer sur N"<<endl;
                return bouton_y_n;
            }
        }
    }
    return bouton_y_n;
}