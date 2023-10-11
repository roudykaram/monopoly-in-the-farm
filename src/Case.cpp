#include"Case.h"
#include<iostream>
using namespace std;


Case::Case(){
    pos=-1;
    type="NULL";
}
Case::Case(int indice, std::string t){
    pos=indice;
    type=t;

}

Case::~Case(){
    pos=-1;
    type="NULL";
}

void Case::set_type(std::string t){
    type=t;
}

int Case::get_pos()const{
    return pos;
}

//fonction CasePropriete
int Case::get_prix()const{
    return 0;
}

void Case::set_prix(unsigned int i){

}

 int Case::get_proprio()const{
    return 0 ;
}

int Case::get_loyer()const{
    return 0;
}

void Case::set_proprio(int i){

}

int Case:: get_nb_arbre()const{
    return 0;
}

void Case:: set_nb_arbre(int i){

}

int Case:: get_nb_jardin()const{
    return 0;
}

void Case:: set_nb_jardin(int i){

}

int Case::calculer_loyer(){
    return 0;
}

void Case::set_loyer(int nouveau_montant){

}

//fonction CaseArgent
int Case::get_montant()const{
    return 0;
   }

void Case::set_montant(int montant){

}   
//fonctions CaseRessources
int Case::get_eau() const{
    return 0;
}

int Case::get_soleil() const{
    return 0 ;
}
//fonctions CaseMystere
int Case::get_qs(int indice ) const{
    return 0;
}

int Case::get_qe(int indice ) const{
    return 0;
}
