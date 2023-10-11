#include <sstream>
#include <iostream>
#include "vue.h"

using namespace std;

void charger_images(SDL_Renderer* renderer, SDL_Texture* images[]) {
    // Tableau contenant le nom de fichier pour chaque type de case
    const char* images_filenames[23] = {
        "data/CasePropriete.png", 
        "data/CaseRessources.png", 
        "data/CaseEnigme.png", 
        "data/CaseArgent.png",
        "data/CaseDepart.png", // On ajoute une image pour la case départ
        "data/de.png",
        "data/photocentre.png",
        "data/pageaccueil.png",
        "data/boutonstart.png",
        "data/Joueur1.png",
        "data/Joueur2.png",
        "data/gagnant_rouge.png",
        "data/gagnant_bleu.png",
        "data/1arbre.png",
        "data/2arbres.png",
        "data/3arbres.png",
        "data/1jardin.png",
        "data/de1.png",
        "data/de2.png",
        "data/de3.png",
        "data/de4.png",
        "data/de5.png",
        "data/de6.png",

    };

    for (int i = 0; i < 38; i++) {
        // Charger l'image correspondante au type de case de la case i
        if (i == 0) {
            // Case départ
            images[i] = IMG_LoadTexture(renderer, images_filenames[4]);
        } else if (i == 2 || i == 3 ||i == 4 || i == 6 ||i == 7 || i == 11 ||i == 12 ||
         i == 13 ||i == 17 || i == 18) {
            // Cases de type CasePropriete
            images[i] = IMG_LoadTexture(renderer, images_filenames[0]);
        } else if (i == 8 || i== 15) {
            // Case de type CaseEnigme
            images[i] = IMG_LoadTexture(renderer, images_filenames[2]);
        } else if (i == 1 || i== 10 || i == 16 || i== 19){
            // Case de type CaseArgent
            images[i] = IMG_LoadTexture(renderer, images_filenames[3]);
        } else if (i == 5 || i== 9 || i == 14){
            //Case de type Ressources
            images[i] = IMG_LoadTexture(renderer, images_filenames[1]);
        } else if (i ==  20){
            //le de
            images[i] = IMG_LoadTexture(renderer, images_filenames[5]);
        } else if (i ==  21){
            //photo du centre du plateau
            images[i] = IMG_LoadTexture(renderer, images_filenames[6]);
        } else if (i ==  22){
            //photo de la page d'accueil
            images[i] = IMG_LoadTexture(renderer, images_filenames[7]);
        } else if (i ==  23){
            //Bouton Start
            images[i] = IMG_LoadTexture(renderer, images_filenames[8]);
        } else if (i == 24){ //joueur 1
            images[i] = IMG_LoadTexture(renderer, images_filenames[9]);
        } else if (i == 25){ //joueur 2
            images[i] = IMG_LoadTexture(renderer, images_filenames[10]);
        } else if (i==26){  //gagnant rouge
            images[i] = IMG_LoadTexture(renderer, images_filenames[11]);
        } else if (i==27){ //gagnant bleu
            images[i] = IMG_LoadTexture(renderer, images_filenames[12]);
        } else if (i==28){ //image 1 arbre
            images[i] = IMG_LoadTexture(renderer, images_filenames[13]);
        } else if (i==29){ //image 2 arbres
            images[i] = IMG_LoadTexture(renderer, images_filenames[14]);
        } else if (i==30){ //image 3 arbres
            images[i] = IMG_LoadTexture(renderer, images_filenames[15]);
        } else if (i==31){ //image 1 jardin
            images[i] = IMG_LoadTexture(renderer, images_filenames[16]);
        } else if (i==32){ //de 1
            images[i] = IMG_LoadTexture(renderer, images_filenames[17]);
        } else if (i==33){ //de 2
            images[i] = IMG_LoadTexture(renderer, images_filenames[18]);
        } else if (i==34){ //de 3
            images[i] = IMG_LoadTexture(renderer, images_filenames[19]);
        } else if (i==35){ //de 4
            images[i] = IMG_LoadTexture(renderer, images_filenames[20]);
        } else if (i==36){ //de 5
            images[i] = IMG_LoadTexture(renderer, images_filenames[21]);
        } else if (i==37){ //de 6
            images[i] = IMG_LoadTexture(renderer, images_filenames[22]);
        }


        if(!images[i]){
            cout<< "l'image " <<i << "n'a ete pas ete chargee"<<endl;
        }
        
    }

    
}


void dessiner_plateau(SDL_Renderer* renderer, SDL_Texture* images[],int arbre_case[],int jardin_case[],unsigned int valeurde) {
    // Dessin du plateau en utilisant les images des cases
    
    SDL_Rect Rect;
 
    const int case_width=130;
    const int case_height=130;
    
    for (int i= 0; i< 21; i++) {

        if (i==20) {  // pour le de
            Rect.x = 6* case_width + 20;
            Rect.y = 0;
        }

        else if (i==6 || i == 7 || i == 8 || i == 9){
           Rect.x = 5 * case_width; 
           if (i==6) Rect.y= case_height;
           if (i==7) Rect.y= 2*case_height;
           if (i==8) Rect.y= 3*case_height;
           if (i==9) Rect.y= 4*case_height;
        }
        else if(i==16 || i == 17 || i == 18 || i == 19){
            Rect.x = 0;
            if (i==16) Rect.y= 4*case_height;
            if (i==17) Rect.y= 3*case_height;
            if (i==18) Rect.y= 2*case_height;
            if (i==19) Rect.y= case_height;
        }
        else { 
            
            

            if(i<16 && i>9){
                if(i==15) Rect.x= 0;
                if(i==14) Rect.x= 1*case_width;
                if(i==13) Rect.x= 2*case_width;
                if(i==12) Rect.x= 3*case_width;
                if(i==11) Rect.x= 4*case_width;
                if(i==10) Rect.x= 5*case_width; 
                Rect.y = 5 * case_height;
            }

            else { 
                Rect.x = i%6 * case_width;
                Rect.y = 0;
            }    
        }
        Rect.w = case_width;
        Rect.h = case_height;

        if(i == 2 || i == 3 ||i == 4 || i == 6 ||i == 7 || i == 11 ||i == 12 ||
         i == 13 ||i == 17 || i == 18) { //Case Propriete
            
            
            if(arbre_case[i]==0 && jardin_case[i]==0){ //aucun arbre ni jardin
                SDL_RenderCopyEx(renderer, images[i], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
            } 
            if(arbre_case[i]==1 && jardin_case[i]==0){ //un seul arbre
                SDL_RenderCopyEx(renderer, images[28], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
            } 
            if(arbre_case[i]==2 && jardin_case[i]==0){ //2 arbres
                SDL_RenderCopyEx(renderer, images[29], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
            } 
            if(arbre_case[i]==3 && jardin_case[i]==0){ //3 arbres
                SDL_RenderCopyEx(renderer, images[30], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
            } 
            if(arbre_case[i]==0 && jardin_case[i]==1){ //1 jardin
                SDL_RenderCopyEx(renderer, images[31], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
            } 
               
        }
        else if(i==20){ //si c'est un de
            if(valeurde==1 || valeurde==0){
                SDL_RenderCopyEx(renderer, images[32], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
            }
            else if(valeurde==2){
                SDL_RenderCopyEx(renderer, images[33], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
            }
            else if(valeurde==3){
                SDL_RenderCopyEx(renderer, images[34], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
            }
            else if(valeurde==4){
                SDL_RenderCopyEx(renderer, images[35], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
            }
            else if(valeurde==5){
                SDL_RenderCopyEx(renderer, images[36], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
            }
            else if(valeurde==6){
                SDL_RenderCopyEx(renderer, images[37], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
            }
        } 
        else{
            SDL_RenderCopyEx(renderer, images[i], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
        }
    }
        //la photo du centre de plateau
        Rect.x=case_width;
        Rect.y=case_height;
        Rect.w=4*case_width;
        Rect.h=4*case_height;
        SDL_RenderCopyEx(renderer, images[21], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
    
        
}

void dessiner_pageaccueil(SDL_Renderer* renderer,SDL_Texture* images[]){
   SDL_Rect Rect;
   //photo de la page d'accueil
   Rect.x=0;
   Rect.y=0;
   Rect.w=1100;
   Rect.h=900;
   SDL_RenderCopyEx(renderer, images[21], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE); 

   //photo du bouton start
   Rect.x=400;
   Rect.y=400;
   Rect.w=300;
   Rect.h=160;
   SDL_RenderCopyEx(renderer, images[23], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE); 
}

void afficher_gagnant(SDL_Renderer* renderer,SDL_Texture* images[],unsigned int gagnant){
    SDL_Rect Rectangle;
    Rectangle.x=0;
    Rectangle.y=0;
    Rectangle.w=1100;
    Rectangle.h=900;
    if(gagnant==0){ //photo avec le trophee le background rouge
        SDL_RenderCopyEx(renderer, images[26], nullptr, &Rectangle, 0, nullptr, SDL_FLIP_NONE);
    } else if(gagnant==1){ //photo avec le trophee le background bleu
        SDL_RenderCopyEx(renderer, images[27], nullptr, &Rectangle, 0, nullptr, SDL_FLIP_NONE);
    }
}


void afficher_joueur(SDL_Renderer* renderer,SDL_Texture* images[],Joueur p1, Joueur p2){
    SDL_Rect Rect;

    const int case_width=130;
    const int case_height=130;
    Rect.w = 50;
    Rect.h = 50;

    if (p1.getPosition()==6 || p1.getPosition() == 7 || p1.getPosition() == 8 || p1.getPosition() == 9){
           Rect.x = 5 * case_width; 
           if (p1.getPosition()==6) Rect.y= case_height;
           if (p1.getPosition()==7) Rect.y= 2*case_height;
           if (p1.getPosition()==8) Rect.y= 3*case_height;
           if (p1.getPosition()==9) Rect.y= 4*case_height;
        }
        else if(p1.getPosition()==16 || p1.getPosition() == 17 || p1.getPosition() == 18 || p1.getPosition() == 19){
            Rect.x = 0;
            if (p1.getPosition()==16) Rect.y= 4*case_height;
            if (p1.getPosition()==17) Rect.y= 3*case_height;
            if (p1.getPosition()==18) Rect.y= 2*case_height;
            if (p1.getPosition()==19) Rect.y= case_height;
        }
            else if(p1.getPosition()<16 && p1.getPosition()>9){ 
            
            

            
                if(p1.getPosition()==15) Rect.x= 0;
                if(p1.getPosition()==14) Rect.x= 1*case_width;
                if(p1.getPosition()==13) Rect.x= 2*case_width;
                if(p1.getPosition()==12) Rect.x= 3*case_width;
                if(p1.getPosition()==11) Rect.x= 4*case_width;
                if(p1.getPosition()==10) Rect.x= 5*case_width; 
                Rect.y = 5 * case_height;
            }

                else if(p1.getPosition()<6 && p1.getPosition()>=0){ 
                    Rect.x = p1.getPosition() %6 * case_width;
                    Rect.y = 0;
                }
    SDL_RenderCopyEx(renderer, images[24], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);

    const int height_j2=70;
    const int width_j2=70;

    if (p2.getPosition()==6 || p2.getPosition() == 7 || p2.getPosition() == 8 || p2.getPosition() == 9){  // pour le Joueur 2
           Rect.x = 5 * case_width; 
           if (p2.getPosition()==6) Rect.y= case_height+height_j2;
           if (p2.getPosition()==7) Rect.y= 2*case_height+height_j2;
           if (p2.getPosition()==8) Rect.y= 3*case_height+height_j2;
           if (p2.getPosition()==9) Rect.y= 4*case_height+height_j2;
        }
        else if(p2.getPosition()==16 || p2.getPosition() == 17 || p2.getPosition() == 18 || p2.getPosition() == 19){
            Rect.x = 0;
            if (p2.getPosition()==16) Rect.y= 4*case_height+height_j2;
            if (p2.getPosition()==17) Rect.y= 3*case_height+height_j2;
            if (p2.getPosition()==18) Rect.y= 2*case_height+height_j2;
            if (p2.getPosition()==19) Rect.y= case_height+height_j2;
        }
            else if(p2.getPosition()<16 && p2.getPosition()>9){ 
            
            

            
                if(p2.getPosition()==15) Rect.x= 0;
                if(p2.getPosition()==14) Rect.x= 1*case_width + width_j2;
                if(p2.getPosition()==13) Rect.x= 2*case_width + width_j2;
                if(p2.getPosition()==12) Rect.x= 3*case_width + width_j2;
                if(p2.getPosition()==11) Rect.x= 4*case_width + width_j2;
                if(p2.getPosition()==10) Rect.x= 5*case_width + width_j2; 
                Rect.y = 5 * case_height+width_j2;
            }

                else if(p2.getPosition()<6 && p2.getPosition()>=0){ 
                    Rect.x = p2.getPosition() %6 * case_width + width_j2;
                    Rect.y = 0;
                }            

    SDL_RenderCopyEx(renderer, images[25], nullptr, &Rect, 0, nullptr, SDL_FLIP_NONE);
   
                
}
    


void afficher_info(SDL_Renderer * renderer,Joueur j,int x, int y,SDL_Color c){
    if(TTF_Init()==-1){
        std::cerr<<"Erreur lors de l'initialisation de TTF "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }
    TTF_Font* font=TTF_OpenFont("data/DejaVuSansCondensed.ttf",20);
    if(font==NULL){
        std::cerr<<"Erreur lors du chargement de la police "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }
    unsigned int id= j.getid();
    unsigned int money=j.getArgent();
    int soleil=j.getSoleil();
    int eau=j.getEau();
    int arbres=j.get_nbarbre();
    int jardins=j.get_nbjardin();

    std::string message[7];
    message[0] ="Joueur " + std::to_string(id);
    message[1] ="argent: " + std::to_string(money);
    message[2] ="eau: " + std::to_string(eau);
    message[3] ="soleil: " + std::to_string(soleil);
    message[4] ="nb arbres: " + std::to_string(arbres);
    message[5] ="nb jardins: " + std::to_string(jardins);

    for(int i=0;i<6;i++){
    SDL_Surface* surface=TTF_RenderText_Blended(font,message[i].c_str(),c);


    if(surface==NULL){
        std::cerr<<"Erreur lors de la creation de la surface "<<i<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);


    }

    SDL_Texture* texture= SDL_CreateTextureFromSurface(renderer,surface);
    if(texture==NULL){
        std::cerr<<"Erreur lors de la creation de la texture"<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Rect posfont={x,y,surface->w,surface->h};
    SDL_RenderCopy(renderer,texture,NULL,&posfont);
    y+=20;
    

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    }
    TTF_CloseFont(font);
    TTF_Quit();

    
 }


void afficher_val_de(SDL_Renderer * renderer,unsigned int val_de,int x, int y,SDL_Color c){
    if(TTF_Init()==-1){
        std::cerr<<"Erreur lors de l'initialisation de TTF "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }
    TTF_Font* font=TTF_OpenFont("data/DejaVuSansCondensed.ttf",20);
    if(font==NULL){
        std::cerr<<"Erreur lors du chargement de la police "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }

    std::string message ="La valeur du de est: " + std::to_string(val_de);

    SDL_Surface* surface=TTF_RenderText_Blended(font,message.c_str(),c);


    if(surface==NULL){
        std::cerr<<"Erreur lors de la creation de la surface "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);


    }

    SDL_Texture* texture= SDL_CreateTextureFromSurface(renderer,surface);
    if(texture==NULL){
        std::cerr<<"Erreur lors de la creation de la texture"<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Rect posfont={x,y,surface->w,surface->h};
    SDL_RenderCopy(renderer,texture,NULL,&posfont);
    
    

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    
    TTF_CloseFont(font);
    TTF_Quit();

    
}

void charger_questions(SDL_Renderer* renderer,unsigned int indice,SDL_Color c,int nb_arbre_avant,int nb_arbre_apres,int nb_jardin_avant,int nb_jardin_apres){
    
    if(TTF_Init()==-1){
        std::cerr<<"Erreur lors de l'initialisation de TTF "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }
    TTF_Font* font=TTF_OpenFont("data/DejaVuSansCondensed.ttf",20);
    if(font==NULL){
        std::cerr<<"Erreur lors du chargement de la police "<<TTF_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }
    
    std::string questions[28];
        
    questions[0]="Voulez-vous acheter ce terrain? Il coute 200 euros.";
    questions[1]="Voulez-vous planter un arbre? Il coute 100 euros.";// Cliquez sur Y pour oui et N pour non.";
    questions[2]="Voulez-vous planter un jardin? Il coute 200 euros";
    questions[3]="Vous avez perdu 200 euros!";
    questions[4]="Vous avez gagne 200 euros!";
    questions[5]="Vous avez perdu 2 unites d'eau et de soleil!";
    questions[6]="Vous avez gagne 2 unites d'eau et de soleil!";
    questions[7]="Vous avez gagne 1 unitee d'eau et de soleil et votre adversaire en a perdue.";
    questions[8]="Vous avez gagne 2 unitees d'eau et de soleil et votre adversaire en a perdues.";
    questions[9]="Vous avez gagne 3 unitees d'eau et de soleil et votre adversaire en a perdues.";
    questions[10]="Pas de changements.";
    questions[11]="Vous avez perdu 1 unitee d'eau et de soleil et votre adversaire en a gagnee.";
    questions[12]="Vous avez perdu 2 unitees d'eau et de soleil et votre adversaire en a gagnees.";
    questions[13]="Vous avez perdu 3 unitees d'eau et de soleil et votre adversaire en a gagnees.";
    questions[14]="Vous avez bien achete le terrain.";
    questions[15]="Vous avez bien achete l'arbre";
    questions[16]="Vous avez bien achete le jardin";
    questions[17]="Vous avez paye les taxes de passage";
    questions[18]="Vous n'avez pas achete le terrain.";
    questions[19]="Vous n'avez pas achete l'arbre";
    questions[20]="Vous n'avez pas achete le jardin";
    questions[21]="Vous n'avez pas l'argent suffisant pour acheter le terrain.";
    questions[22]="Vous n'avez pas l'argent suffisant pour acheter l'arbre.";
    questions[23]="Vous n'avez pas l'argent suffisant pour acheter le jardin.";
    questions[24]="Vous avez perdu :( Vous n'avez pas assez d'argent pour payer la taxe de passage.";
    questions[25]="Vous avez perdu :( Vous n'avez pas assez d'argent pour payer les 200 euros.";
    questions[26]="Le joueur 1 arrose: il avait "+ std::to_string(nb_arbre_avant) +" arbres, "+std::to_string(nb_jardin_avant)+" jardins. Maintenant il a "
    + std::to_string(nb_arbre_apres) +" arbres, "+std::to_string(nb_jardin_apres) +" jardins.";
    questions[27]="Le joueur 2 arrose: il avait "+ std::to_string(nb_arbre_avant) +" arbres, "+std::to_string(nb_jardin_avant)+" jardins. Maintenant il a "
    + std::to_string(nb_arbre_apres) +" arbres, "+std::to_string(nb_jardin_apres) +" jardins.";

    
    
        SDL_Surface* surface=TTF_RenderText_Blended(font,questions[indice].c_str(),c);
        


        if(surface==NULL){
            std::cerr<<"Erreur lors de la creation de la surface "<<TTF_GetError()<<endl;
            SDL_Quit();
            exit(1);

        
        }

        SDL_Texture* texture= SDL_CreateTextureFromSurface(renderer,surface);
        if(texture==NULL){
            std::cerr<<"Erreur lors de la creation de la texture"<<TTF_GetError()<<endl;
            SDL_Quit();
            exit(1);
        }

        SDL_Rect posfont;

        if(indice>=0 && indice<=25){

            posfont={100,800,surface->w,surface->h};
        }
        else if(indice==26){ //pour les phrases de la fonction arroser de joueur 0
            posfont={100,830,surface->w,surface->h};
        }
        else if(indice==27){ //pour les phrases de la fonction arroser de joueur 1
            posfont={100,850,surface->w,surface->h};
        }
    
        SDL_RenderCopy(renderer,texture,NULL,&posfont);
        

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
        
        TTF_CloseFont(font);
        TTF_Quit();
    

       

}

void appel_questions(SDL_Renderer* renderer,bool bouton_y_n, int question,int nb_arbre_avant,int nb_arbre_apres,int nb_jardin_avant,int nb_jardin_apres){

    SDL_Color rouge={255,0,0};
    SDL_Color vert={0,255,0};
    SDL_Color blanc={255,255,255};

    if(bouton_y_n == false && question==0 ){
        charger_questions(renderer,0,blanc,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(bouton_y_n == false && question==1 ){
        charger_questions(renderer,1,blanc,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
        
    } 

    if(bouton_y_n == false && question==2 ){
        charger_questions(renderer,2,blanc,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
                     
    }

    if(question==3){
        charger_questions(renderer,3,rouge,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }
    
    if(question==4){
        charger_questions(renderer,4,vert,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==5){
        charger_questions(renderer,5,rouge,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }
    
    if(question==6){
        charger_questions(renderer,6,vert,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==7){
        charger_questions(renderer,7,vert,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==8){
        charger_questions(renderer,8,vert,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==9){
        charger_questions(renderer,9,vert,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==10){
        charger_questions(renderer,10,blanc,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==11){
        charger_questions(renderer,11,rouge,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==12){
        charger_questions(renderer,12,rouge,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==13){
        charger_questions(renderer,13,rouge,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==14){
        charger_questions(renderer,14,vert,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==15){
        charger_questions(renderer,15,vert,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==16){
        charger_questions(renderer,16,vert,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==17){
        charger_questions(renderer,17,rouge,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==18){
        charger_questions(renderer,18,rouge,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==19){
        charger_questions(renderer,19,rouge,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==20){
        charger_questions(renderer,20,rouge,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==21){
        charger_questions(renderer,21,rouge,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==22){
        charger_questions(renderer,22,rouge,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }

    if(question==23){
        charger_questions(renderer,23,rouge,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }
    if(question==26){
        charger_questions(renderer,26,rouge,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }
    if(question==27){
        charger_questions(renderer,27,rouge,nb_arbre_avant,nb_arbre_apres,nb_jardin_avant,nb_jardin_apres);
    }
}
