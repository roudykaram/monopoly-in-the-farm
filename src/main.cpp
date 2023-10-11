#include "Plateau.h"
#include "vue.h"
#include "controleur.h"
#include <iostream>
#include <unistd.h>

using namespace std;
 
int main(){

const int case_width=130;
const int case_height=130;
Jeu j;
SDL_Window*window = NULL; 
SDL_Renderer * renderer = NULL;  
SDL_Texture* images[38];
bool quit;
SDL_Event event;
SDL_Rect rect_de;
rect_de.x=6*case_width +20;
rect_de.y=0;
rect_de.h=case_height;
rect_de.w=case_width;
unsigned int valde;
unsigned int valeurde;
SDL_Color rouge={255,0,0};
SDL_Color bleu={0,0,255};
SDL_Color blanc={255,255,255};

bool tour_prochain=true;
bool propriete_achete=false;
bool non_achetee=false;
int question=-1;
int question_arroser_0=-1;
int question_arroser_1=-1;
int nb_clic=0;
bool boucle_taxe=true;
bool bouton_start=false;

//nombre d'arbres des joueurs avant l'arrosage
int nb_arbre_j0_avant=j.getJoueurs(0).get_nbarbre();
int nb_arbre_j1_avant=j.getJoueurs(1).get_nbarbre();
int nb_arbre_j0_apres=j.getJoueurs(0).get_nbarbre();
int nb_arbre_j1_apres=j.getJoueurs(1).get_nbarbre();

//nombre de jardins des joueurs avant l'arrosage
int nb_jardin_j0_avant=j.getJoueurs(0).get_nbjardin();
int nb_jardin_j1_avant=j.getJoueurs(1).get_nbjardin();
int nb_jardin_j0_apres=j.getJoueurs(0).get_nbjardin();
int nb_jardin_j1_apres=j.getJoueurs(1).get_nbjardin();

int arbre_case[19];
int jardin_case[19];


window = SDL_CreateWindow("Monopoly",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1100,900,SDL_WINDOW_SHOWN);
renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

charger_images(renderer,images);


if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erreur lors de l'initialisation de SDL : " << SDL_GetError() << std::endl;
        return 1;
    }

while (!quit){
    if(bouton_start==false){ //si on n'a pas encore appuye sur le bouton start
        while (SDL_PollEvent(&event)){
            if (event.type==SDL_QUIT){
                quit=true;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN){ //si on clic sur la souris
                
                clic_bouton_start(event,bouton_start); // si on appuie sur le bouton start, bouton_start est mis a true
            }

        dessiner_pageaccueil(renderer,images);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);

        }
    }    
    else if(question==24 || question==25){ //si le joueur n'a plus d'argent, on affiche le gagnant(photo avec trophee)
        while (SDL_PollEvent(&event)){
            if (event.type==SDL_QUIT){
                quit=true;
            }

            if (event.type == SDL_MOUSEBUTTONDOWN){ 
                valde=clic(event,j,rect_de);
                valeurde=valde;
                tour_prochain=false; 
                boucle_taxe=true;
                nb_clic++;                
            }
        }

        unsigned int joueur_actu=j.getJoueurActuel();
        j.set_gagnant(joueur_actu);
        afficher_gagnant(renderer,images,j.get_gagnant());
        
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        
    }

  else{

    bool bouton_y_n=false;
    bool bouton_y=false;

    for(int i=0;i<19;i++){  //on stocke le nombre d'arbre et de jardin de chaque case dans arbre_case[] et jardin_case[]
        if(i == 2 || i == 3 ||i == 4 || i == 6 ||i == 7 || i == 11 ||i == 12 ||
         i == 13 ||i == 17 || i == 18) {
            arbre_case[i]=j.getPlateau()->getCase(i).get_nb_arbre();
            jardin_case[i]=j.getPlateau()->getCase(i).get_nb_jardin();

         }
         else{
            arbre_case[i]=0;
            jardin_case[i]=0;
         }   
    }

    dessiner_plateau(renderer,images,arbre_case,jardin_case,valeurde);
    afficher_joueur (renderer,images,j.getJoueurs(0), j.getJoueurs(1));
    afficher_info(renderer, j.getJoueurs(0),800, 150,rouge);
    afficher_info(renderer, j.getJoueurs(1),800, 300,bleu);

      
    
           
    afficher_val_de( renderer,valeurde,800, 465, blanc);
    
    valde=0;    

    while (SDL_PollEvent(&event)){
        if (event.type==SDL_QUIT){
            quit=true;
        }   
        //quand on appuie sur le de et que c'est le tour de jouer
        if (event.type == SDL_MOUSEBUTTONDOWN && tour_prochain==true){ 
            valde=clic(event,j,rect_de);
            valeurde=valde;
            tour_prochain=false; 
            boucle_taxe=true;
            nb_clic++;                
        }

        //quand on appuie sur le clavier, si on appuie sur Y ou N 
        if (event.type==SDL_KEYDOWN){
           
            SDL_Keycode keyCode = event.key.keysym.sym;
            if (keyCode == SDLK_y ){
                   bouton_y_n=true;              
                   bouton_y=true;
                   cout<< "on a appuye sur y"<<endl;            
            }
            else if(keyCode == SDLK_n){
                    bouton_y_n=true;              
                    bouton_y=false; 
                    cout<< "on a appuye sur n"<<endl;
            }
                     
        }
    }


    //si on a appuye sur le de quand c'etait le tour de jouer
    if(valde>0){
               
                j.bouge(valde);
                valde=0;
               
               question=j.joue_tour(propriete_achete,non_achetee);           
               int pos_pion=j.getJoueurs(j.getJoueurActuel()).getPosition();

               //quand le pion est sur une autre case qu'une CasePropriete, on passe direct au tour suivant   
               if(pos_pion==8||pos_pion==15||pos_pion==1||pos_pion==10||pos_pion==16||pos_pion==19||pos_pion==5||pos_pion==9||pos_pion==14||pos_pion==0)     
                    {
                        tour_prochain=j.tour_suivant();   
                     }

    }
               int joueur_act=j.getJoueurActuel();
               int pos_actuelle=j.getJoueurs(joueur_act).getPosition();

               //si le pion est sur une CasePropriete
               if(pos_actuelle==2||pos_actuelle==3||pos_actuelle==4||pos_actuelle==6||pos_actuelle==7||pos_actuelle==11||pos_actuelle==12||pos_actuelle==13||pos_actuelle==17||pos_actuelle==18){
                
                    //si on appuie sur Y, et qu'on peut soit achete le terrain ou un arbre ou un jardin
                    if(bouton_y_n == true && bouton_y ==true && (question==0||question==1||question==2)){ 
                    
                        if(joueur_act==0){
                            propriete_achete=true; //on dit oui
                            question=j.joue_tour(propriete_achete,non_achetee);
                        
                            tour_prochain=j.tour_suivant();
                            
                            bouton_y_n=false;              
                            bouton_y=false; 
        
                        
                        }

                        if(joueur_act==1){
                    
                            propriete_achete=true;//on a dit oui
                            question=j.joue_tour(propriete_achete,non_achetee);
                            tour_prochain=j.tour_suivant();
                            bouton_y_n=false;              
                            bouton_y=false;
                        }
                    }
                    //si on appuie sur N et qu'on peut acheter le terrain ou un arbre ou un jardin
                    if(bouton_y_n == true && bouton_y ==false && (question==0||question==1||question==2)){
                        non_achetee=true;
                        question=j.joue_tour(propriete_achete,non_achetee);
                        tour_prochain=j.tour_suivant();
                        bouton_y_n=false;              
                        bouton_y=false;

                     }

                    //si le proprio est le joueur adverse ou qu'on n'a pas d'argent pour acheter
                    if((question==17 || question==22 || question==23) && boucle_taxe){
                        tour_prochain=j.tour_suivant();
                        bouton_y_n=false;              
                        bouton_y=false;
                        boucle_taxe=false;
                    }    

                }

                if(nb_clic==10){ // quand c'est le temps d'arroser les arbres (au bout de 10 tours)

                    nb_arbre_j0_avant=j.getJoueurs(0).get_nbarbre();
                    nb_arbre_j1_avant=j.getJoueurs(1).get_nbarbre();
                    nb_jardin_j0_avant=j.getJoueurs(0).get_nbjardin();
                    nb_jardin_j1_avant=j.getJoueurs(1).get_nbjardin();
                    question_arroser_0=j.arrose_arbre(0);
                    question_arroser_1=j.arrose_arbre(1);
                    nb_arbre_j0_apres=j.getJoueurs(0).get_nbarbre();
                    nb_arbre_j1_apres=j.getJoueurs(1).get_nbarbre();
                    nb_jardin_j0_avant=j.getJoueurs(0).get_nbjardin();
                    nb_jardin_j1_avant=j.getJoueurs(1).get_nbjardin();
                    nb_clic=0;
                }
                if(nb_clic==1){
                    question_arroser_0 = -1;
                    question_arroser_1 = -1;
                }
                
           
    // affichage des questions sous le plateau
        

    appel_questions(renderer,bouton_y_n,question,nb_arbre_j0_avant,nb_arbre_j0_apres,nb_jardin_j0_avant,nb_jardin_j0_apres);
    if(question_arroser_0 != -1){
        appel_questions(renderer,bouton_y_n,question_arroser_0,nb_arbre_j0_avant,nb_arbre_j0_apres,nb_jardin_j0_avant,nb_jardin_j0_apres);
    }
    if(question_arroser_1 != -1){
        appel_questions(renderer,bouton_y_n,question_arroser_1,nb_arbre_j1_avant,nb_arbre_j1_apres,nb_jardin_j1_avant,nb_jardin_j1_apres);
    }
    
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);

  }      
         
  } 
    

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
}