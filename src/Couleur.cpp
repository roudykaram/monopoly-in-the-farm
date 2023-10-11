#include<iostream>
#include"Couleur.h"

using namespace std;

Couleur::Couleur(){
    r=255;
    g=255;
    b=255;
}

Couleur::Couleur(unsigned char nr,unsigned char ng,unsigned char nb){
    r=nr;
    g=ng;
    b=nb;

}

unsigned char Couleur::getRouge() const {
    return r;

}

unsigned char Couleur::getVert() const {
    return g;

}

unsigned char Couleur::getBleu() const {
    return b;

}

void Couleur::setRouge(unsigned char nr){
    r=nr;
}

void Couleur::setVert(unsigned char ng){
    g=ng;
}

void Couleur::setBleu(unsigned char nb){
    b=nb;
}
