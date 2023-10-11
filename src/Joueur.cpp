#include "Joueur.h"
#include "CasePropriete.h"
#include "assert.h"

Joueur::Joueur (){
    id =0;
    argent=1500;
    quantite_eau=5;
    quantite_soleil=5;
    nb_arbre=0;
    nb_jardin=0;
    
    position =0;
}
Joueur::Joueur(int idj){ 
    
    id =idj;
    argent=1500;
    quantite_eau=5;
    quantite_soleil=5;
    nb_arbre=0;
    nb_jardin=0; 

    position =0;

}

Joueur::~Joueur(){

}

unsigned int Joueur::getid () const{
    return id;    
} 

int Joueur::getEau()const{
    return quantite_eau;
}

int Joueur::get_nbarbre()const{
    return nb_arbre;
}

int Joueur::get_nbjardin()const{
    return nb_jardin;
}

void Joueur::set_nbjardin(int i){
    nb_jardin=i;
}

 void Joueur::set_nbarbre(int i){
    nb_arbre=i;
 }


int Joueur::getSoleil()const{
    return quantite_soleil;
}

unsigned int  Joueur::getArgent()const{
    return argent;
}

unsigned int Joueur::getPosition()const{
    return position;
}



void Joueur::setid (int idj){
    id=idj;
};

void Joueur::setEau (int x){
    quantite_eau=x;
}

void Joueur::setSoleil (int x){
    quantite_soleil=x;
}

void Joueur::setArgent (unsigned int x){
    argent=x;
}

void Joueur::setPosition (unsigned int x){
    position=x;
}

void Joueur::testRegressionJoueur(){
    //on teste que le constructeur marche
    //Joueur j;
    setid(1);
    assert(getid()==1); //test getid et setid

    set_nbarbre(2);
    assert(get_nbarbre()==2); //test get et set de nb_arbre

    set_nbjardin(3);
    assert(get_nbjardin()==3); //test get et set de nb_jardin

    setArgent(2500);
    assert(getArgent()==2500); // test get et set d'argent

    setEau(5);
    assert(getEau()==5);  //test get et set de quantite_eau

    setSoleil(6);
    assert(getSoleil()==6);  //test get et set de quantite_soleil

    setPosition(7);
    assert(getPosition()==7);  //test get et set de position

    
}