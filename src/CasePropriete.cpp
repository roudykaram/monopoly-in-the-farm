#include"CasePropriete.h"
#include"Joueur.h"
#include"Couleur.h"


CasePropriete::CasePropriete() {

    
    prix=0;
    pos=0;
    type="Case Propriete";
    loyer=0;
    nb_arbre=0;
    nb_jardin=0;
    proprio=1;
}

CasePropriete::CasePropriete(int pr,int position, std::string type, int l, int propri, int nba, int nbj)
{
    prix=pr;
    pos=position;
    type="Case Propriete";
    loyer=l;
    nb_arbre=nba;
    nb_jardin=nbj;
    proprio=propri;

}

CasePropriete::~CasePropriete(){

    prix=0;
    loyer=0;
    nb_arbre=0;
    nb_jardin=0;
    proprio=0;
    

}

int CasePropriete::get_loyer()const{
    return loyer;
}

void CasePropriete::set_loyer(int nv_loyer){
    loyer=nv_loyer;

}

int CasePropriete::calculer_loyer(){
    int nv_loyer=loyer;
    
    if (nb_arbre!=0){   //chaque arbre rajoute 40 euros au loyer
        nv_loyer=50 + nb_arbre*40;
    }
    
    if(nb_jardin==1){ //un jardin rajoute 300 euros au loyer
        nv_loyer=50 + 300;
    }
    return nv_loyer;
}

  void CasePropriete:: set_nb_arbre(int i){
    nb_arbre=i;
  }

  int CasePropriete:: get_nb_arbre()const{
    return nb_arbre;
  }

 void CasePropriete:: set_nb_jardin(int i){
    nb_jardin=i;
  }

  int CasePropriete:: get_nb_jardin()const{
    return nb_jardin;
  } 

int CasePropriete::get_prix()const{
    return prix;   
}

void CasePropriete::set_prix(unsigned int x){
    prix=x;   
}

 int CasePropriete::get_proprio()const{
    return proprio;
}

void CasePropriete::set_proprio(int i){
    proprio = i;
}

