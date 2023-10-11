#include"Jeu.h"
#include "controleur.h"
#include"vue.h"
#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;


Jeu::Jeu() {
  
    plateau=new Plateau();

    joueurs[1].setid(1);
    
   

    joueur_actuel = 0; // Initialisation du joueur actuel
    gagnant = 2; // Initialisation du gagnant a 2, donc a aucun des joueurs qui ont 0 et 1 comme indice 
}

Jeu::~Jeu(){
    
 delete plateau;  
} 

unsigned int Jeu::jete_de(){
    srand(time(NULL));
    unsigned int de;
    // genere des valeurs aléatoire pour le de (1 à 6) et retourne la valeur
    de = rand()% 6 +1;

    return de;

}


 void Jeu::set_gagnant(unsigned int i){
    gagnant=i;
 }

unsigned int Jeu::get_gagnant()const{
    return gagnant;
}


void Jeu::bouge(int x){
 
    int pos;
    pos =joueurs[joueur_actuel].getPosition() + x;
    if (pos <20){
        joueurs[joueur_actuel].setPosition(joueurs[joueur_actuel].getPosition() + x);
        cout<<"la nv pos du j est "<< joueurs[joueur_actuel].getPosition() <<endl;
    }else{
        pos= pos -20; //pour ne pas depasser les 20 cases
        joueurs[joueur_actuel].setPosition(pos);
        cout<<"la nv pos du j est "<< joueurs[joueur_actuel].getPosition() <<endl;
    }
    
} 



bool Jeu:: tour_suivant(){
    if(joueur_actuel==0){
        joueur_actuel=1;
    }
    else{
        joueur_actuel=0;
    }
    return true;

}

int Jeu::arrose_arbre(unsigned int id){
    int question=1;
    //prend la valeur actuelle d’eau, d'arbres et de jardins que le joueur possède
    int nb_eau_j=joueurs[id].getEau();
    int nb_arbre_j=joueurs[id].get_nbarbre();
    int nb_jardin_j=joueurs[id].get_nbjardin();
    int conso_jardin_j= 4 * nb_jardin_j; //le nb d’eau et de ressource qu’on a besoin pour arroser un jardin
    int reste_arroser;
    
    //boucle pour quand le nb de ressources du joueur est supérieur ou égale a la valeur que le joueur 
    //a besoin pour arroser les arbres qu’il a 
    if(nb_eau_j >= (nb_arbre_j + conso_jardin_j)){
        //modifier la valeur d’eau 
        joueurs[id].setEau(nb_eau_j - (nb_arbre_j + conso_jardin_j));
        //modifier la valeur du soleil
        joueurs[id].setSoleil(nb_eau_j - (nb_arbre_j + conso_jardin_j));
    }

    //boucle pour quand le nb de ressources est inférieur au nb de ressources que le joueur a besoin
    // pour arroser les arbres et jardin qu’il a 
    if(nb_eau_j < (nb_arbre_j + conso_jardin_j)){
        reste_arroser = (nb_arbre_j + conso_jardin_j) - nb_eau_j;
        if(nb_eau_j>0){
            joueurs[id].setEau(0); //son eau et son soleil deviennent nuls
            joueurs[id].setSoleil(0);
        }
        
        //parcourir les cases et prendre les cases propriete 
        for(int i=2; i<19 ; i++){
            //si c’est une CasePropriete
            if((i==2||i==3||i==4||i==6||i==7||i==11||i==12||i==13||i==17||i==18) && reste_arroser!=0){
                //prendre le propriétaire de la case
                int proprio_case=plateau->getCase(i).get_proprio();
                unsigned int proprietaire_case=(unsigned int) proprio_case;
                //prendre le nb d’arbre et de jardin dans la case
                int nb_arbre_case=plateau->getCase(i).get_nb_arbre();
                int nb_jardin_case=plateau->getCase(i).get_nb_jardin();
                //prendre la valeur d’eau pour le joueur de la case
                //ainsi que le nb_jardin et nb_arbre
                nb_eau_j=joueurs[id].getEau();
                nb_arbre_j=joueurs[id].get_nbarbre();
                nb_jardin_j=joueurs[id].get_nbjardin();
                //le nb de ressources qu’a besoin le jardin pour pouvoir être arrosé
                int valeur_jardin_case=4*nb_jardin_case;
                
                //si le propriétaire de la case est le joueur lui meme et qu’il a des arbres ou jardin
                if(proprietaire_case==id && (nb_arbre_case>0 || nb_jardin_case>0)){
                    //s'il reste des arbres non arroses
                    if(nb_arbre_case >= reste_arroser){
                        plateau->getCase(i).set_nb_arbre(nb_arbre_case - reste_arroser);
                        joueurs[id].set_nbarbre(nb_arbre_j - reste_arroser);
                        reste_arroser=0;
                        
                    }
                    else if((nb_arbre_case < reste_arroser) && (nb_arbre_case>0)){
                        plateau->getCase(i).set_nb_arbre(0);
                        joueurs[id].set_nbarbre(nb_arbre_j - nb_arbre_case);
                        reste_arroser = reste_arroser - nb_arbre_case;
                    }
                    else if(valeur_jardin_case >= reste_arroser){
                        plateau->getCase(i).set_nb_jardin(nb_jardin_case - 1);
                        joueurs[id].set_nbjardin(nb_jardin_j - nb_jardin_case);
                        joueurs[id].setEau(valeur_jardin_case-reste_arroser);
                        joueurs[id].setSoleil(valeur_jardin_case-reste_arroser);
                        reste_arroser=0;
                    }
                    else if((valeur_jardin_case < reste_arroser) && (nb_jardin_case>0)){
                        plateau->getCase(i).set_nb_jardin(0);
                        joueurs[id].set_nbjardin(nb_jardin_j - nb_jardin_case);
                        reste_arroser = reste_arroser - valeur_jardin_case;
                    }
                }
            }
        }
    }    
    if(id==0){
        return question=26;
    }

    if(id==1){
        return question=27;
    }   

    return question; 
}


int Jeu::joue_tour(bool &propriete_achetee,bool &non_achetee){
    int questions=-1;
    int joueur_adverse;
    if (joueur_actuel==0) joueur_adverse=1;
    else joueur_adverse=0;
    int i=joueurs[joueur_actuel].getPosition();
    int argent_actuel=joueurs[joueur_actuel].getArgent();
    int argent_actuel_adverse=joueurs[joueur_adverse].getArgent();
    int eau_actuel=joueurs[joueur_actuel].getEau();
    int soleil_actuel=joueurs[joueur_actuel].getSoleil();
    
    
    if (i==1 || i==10 || i==16 || i==19){  //s'il est sur une case Argent
        cout<<"on est dans la boucle case argent "<<endl;
        int montant_case=plateau->getCase(i).get_montant();
        
        if (montant_case<0){
            if(argent_actuel>=200) questions=3;    //si argent suffisant
            else if(argent_actuel<200) questions=25; //si argent pas suffisant
        } else questions=4; //"Vous avez gagne 200 euros!"
        
        cout<<"montant case argent "<< montant_case<<endl;;
        joueurs[joueur_actuel].setArgent (argent_actuel + montant_case);
        cout<<"montan gagne"<<joueurs[joueur_actuel].getArgent ()<<endl;
    }

    if(i==8 || i== 15){ //si on est sur une case mystere
        
        srand(time(NULL));
        int indice;
        indice= rand()%7;

       //int indice_joueur=rand()% 2;
        int eau_actuel=joueurs[joueur_actuel].getEau();
        int soleil_actuel=joueurs[joueur_actuel].getSoleil();
        int eau_adversaire=joueurs[joueur_adverse].getEau();
        int soleil_adversaire=joueurs[joueur_adverse].getSoleil();

        int eau_case=plateau->getCase(i).get_qe(indice); 
        int soleil_case=plateau->getCase(i).get_qs(indice); 

        //retourne l'indice de la phrase a afficher selon le nombre de ressources dans la case
        switch(eau_case){
            case 0:
                questions=10; //"Pas de changements."
                break;
            case 1:
                questions=7; // "Vous avez gagne 1 unitee d'eau et de soleil et votre adversaire en a gagnee."
                break;

            case 2:
                questions=8; //"Vous avez gagne 2 unitees d'eau et de soleil et votre adversaire en a gagnee."
                break;

            case 3:
                questions=9; //"Vous avez gagne 3 unitees d'eau et de soleil et votre adversaire en a gagnee."
                break; 

            case -1:
                questions=11; //"Vous avez perdu 1 unitee d'eau et de soleil et votre adversaire en a gagnee."
                break; 

            case -2:
                questions=12; //"Vous avez perdu 2 unitees d'eau et de soleil et votre adversaire en a gagnee."
                break; 

            case -3:
                questions=13; //"Vous avez perdu 3 unitees d'eau et de soleil et votre adversaire en a gagnee."
                break;                          
        }

    
        //set l'eau et le soleil des joueurs selon le nb de ressources dans la case
        joueurs[joueur_actuel].setEau(eau_actuel+eau_case);
        joueurs[joueur_adverse].setEau(eau_adversaire-eau_case);
        joueurs[joueur_actuel].setSoleil(soleil_actuel+soleil_case);
        joueurs[joueur_adverse].setSoleil(soleil_adversaire-soleil_case);
       

    }

    if (i==5 || i==9 || i==14){  // s'il est sur une case ressources
        int nb_eau = plateau->getCase(i).get_eau();
        int nb_soleil = plateau->getCase(i).get_soleil();
        if (nb_eau < 0){
            questions=5; //"Vous avez perdu 2 unites d'eau et de soleil!"
        } else questions=6; //"Vous avez gagne 2 unites d'eau et de soleil!"
        //set l'eau et le soleil du joueur selon nombre d'eau et de soleil de la case
        joueurs[joueur_actuel].setEau(eau_actuel + nb_eau);
        joueurs[joueur_actuel].setSoleil(soleil_actuel + nb_soleil);
    }

    //si on se trouve sur une casepropriete
    if (i==2 || i==3 || i==4 || i==6 || i==7 || i==11 ||i==12|| i==13|| i==17|| i==18 ) { // s'il est sur une case Propriete
        int proprietaire_case=plateau->getCase(i).get_proprio();
        unsigned int proprio_case=(unsigned int) proprietaire_case;
        cout<<"proprio case "<< proprio_case<<endl;
        int loyer_case=plateau->getCase(i).get_loyer();
        if(proprietaire_case == joueur_adverse && argent_actuel>=loyer_case){ // si le proprio est le joueur adverse
            joueurs[joueur_actuel].setArgent(argent_actuel - loyer_case);
            joueurs[joueur_adverse].setArgent(argent_actuel_adverse + loyer_case);
            cout<<"Il paye une taxe de "<<loyer_case<<endl;
            questions=17;//"Vous avez paye les taxes de passage"
            cout<<"lindice de la question est "<<questions<<endl;
        }
        if(proprietaire_case == joueur_adverse && argent_actuel<loyer_case){ //si proprio joueur adv et pas assez d'argent
            questions=24;//"Vous avez perdu :( Vous n'avez pas assez d'argent pour payer la taxe de passage."
        }    
        
        
        if(proprio_case == joueur_actuel) { //s'il est lui meme le proprio de la case


            int nb_arbre_case = plateau->getCase(i).get_nb_arbre();

            int nb_arbre_joueur = joueurs[joueur_actuel].get_nbarbre();

            int nb_jardin_case = plateau->getCase(i).get_nb_jardin();

            int nb_jardin_joueur = joueurs[joueur_actuel].get_nbjardin();

            if(nb_arbre_case<3 && argent_actuel>=100){ //si le nombre d'abre de la case est inferieur à 5 et s'il a l'argent necessaire pour l'acheter

                questions=1; //"Voulez-vous planter un arbre?"

                if(propriete_achetee==true){ //s'il a dit oui

                    cout<<"le nb d arbre avant l achat"<<nb_arbre_case<<endl;

                    plateau->getCase(i).set_nb_arbre(nb_arbre_case + 1);
                    cout<<"le nb d arbre de la case apres achat d arbre"<<nb_arbre_case<<endl;

                    joueurs[joueur_actuel].set_nbarbre(nb_arbre_joueur+1);

                    joueurs[joueur_actuel].setArgent(argent_actuel - 100);

                    int nv_loyer=plateau->getCase(i).calculer_loyer();
                    plateau->getCase(i).set_loyer(nv_loyer);
                    cout<<"Le nouveau loyer "<<plateau->getCase(i).get_loyer()<<endl;

                    propriete_achetee=false;

                    questions=15;//"Vous avez bien achete l'arbre"

                }

                if(non_achetee==true){
                    non_achetee=false;
                    questions=19; //"Vous n'avez pas achete l'arbre"
                    
                }   

            } 
            //s'il n'a pas assez d'argent pour acheter l'arbre
            else if(nb_arbre_case<3 && argent_actuel<100){
                propriete_achetee=false; 
                questions=22;   
            }  
            //s'il a deja 3 arbres sur la case et il a l'argent suffisant pour acheter un jardin
            else if(nb_arbre_case==3 && argent_actuel>=200){
                questions=2; //"veux-tu acheter un jardin?"

                if(propriete_achetee==true){ //si le joueur dit oui
                    plateau->getCase(i).set_nb_jardin(nb_jardin_case + 1);

                    joueurs[joueur_actuel].set_nbjardin(nb_jardin_joueur + 1);

                    joueurs[joueur_actuel].setArgent(argent_actuel - 200);

                    joueurs[joueur_actuel].set_nbarbre(nb_arbre_joueur - 3);

                    plateau->getCase(i).set_nb_arbre(0);

                    int nv_loyer=plateau->getCase(i).calculer_loyer();
                    plateau->getCase(i).set_loyer(nv_loyer);
                    cout<<"Le nouveau loyer avec jardin "<<plateau->getCase(i).get_loyer()<<endl;

                    propriete_achetee=false;

                    questions=16; //"Vous avez bien achete l'arbre"

                }
                if(non_achetee==true){
                    non_achetee=false;
                    questions=20; //"Vous n'avez pas achete le jardin
                    
                }      
            }
            else if(nb_arbre_case==3 && argent_actuel<200){ //s'il a 3 arbres mais pas l'argent suffisant
                propriete_achetee=false;
                questions=23; //"vous ne pouvez pas achete le jardin"
            }   

        }



        if(proprio_case == 2) { //si la case n'a pas de proprio
            questions=0; //"voulez-vous acheter le terrain"
            cout<<"la question de l'achat terrain"<<endl;
            if(propriete_achetee==true){ //s'il dit oui
                int prix_terrain=plateau->getCase(i).get_prix();
                if(argent_actuel>prix_terrain){ //s'il a l'argent suffisant
                    plateau->getCase(i).set_proprio(joueur_actuel);
                    cout<<"le proprietaire maintenant est :"<<plateau->getCase(i).get_proprio()<<endl;
                    joueurs[joueur_actuel].setArgent(argent_actuel - prix_terrain);
                    propriete_achetee=false;
                    questions=14; //"vous avez bien achete le terrain."
                }  
                if(argent_actuel<prix_terrain){ //s'il n'a pas l'argent suffisant
                    propriete_achetee=false; 
                    questions=21; //"vous n'avez pas pu acheter ce terrain."
                }      
            }
            if(non_achetee==true){ //s'il dit non
                non_achetee=false;
                questions=18; //"vous n'avez pas achete ce terrain."
                cout<<"non pour l'achat du terrain"<<endl;
                
            }
        }
    }
    return questions;

}


Joueur Jeu::getJoueurs(int id) const{
    return joueurs[id];
}

unsigned int Jeu::getJoueurActuel()const{
    return joueur_actuel;
}

void Jeu:: setJoueurActuel(unsigned int i){
    joueur_actuel=i;
}

Plateau* Jeu::getPlateau() const{
    return plateau;
}

void Jeu::testRegressionJeu(){
    
    //on teste la fonction jete_de()
    int valeur_de=jete_de();
    assert(valeur_de>0);
    assert(valeur_de<7);

    //on teste getJoueurs et la fonction bouge
    bouge(5);
    assert(getJoueurs(0).getPosition()==5);

    //on teste set et get_gagnant
    set_gagnant(3);
    assert(get_gagnant()==3);

    //on teste tour_suivant
    tour_suivant(); //le joueur actuel est 0 ainsi apres tour_suivant il doit etre 1
    assert(getJoueurActuel()==1);

    //on teste arrose_arbre
    joueurs[0].set_nbarbre(2);
    assert(getJoueurs(0).get_nbarbre()==2);
    int eau_avant_arrose=getJoueurs(0).getEau();
    arrose_arbre(0);
    assert(getJoueurs(0).getEau()==(eau_avant_arrose - 2));

    //on teste joue_tour
    int argent_avant_jouetour= getJoueurs(1).getArgent();
    bouge(1);
    bool propriete_achetee=false;
    bool non_achetee=false;
    joue_tour(propriete_achetee,non_achetee);
    unsigned int argent_av_jouetour=(unsigned int)argent_avant_jouetour;
    assert(getJoueurs(1).getArgent()==argent_av_jouetour + 200);

    bouge(7); //on est sur une Case Enigme
    int question=joue_tour(propriete_achetee,non_achetee);
    assert(question==10 || question==7 || question==8 ||question==9||question==11
    ||question==12||question==13);

    bouge(1); //on est sur une case Ressources
    question=joue_tour(propriete_achetee,non_achetee);
    assert(question==5 || question==6);

    bouge(2);
    non_achetee=true;
    question=joue_tour(propriete_achetee,non_achetee);
    assert(question==18);
}