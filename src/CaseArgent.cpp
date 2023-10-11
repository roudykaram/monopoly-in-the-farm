#include <iostream>
#include "CaseArgent.h"

CaseArgent::CaseArgent(int argent,int position,std::string letype){
    montant=argent;
    pos=position;
    type=letype;
}


int CaseArgent::get_montant()const{
    return montant;
};

void CaseArgent::set_montant(int monnaie){
    montant=monnaie;
};
