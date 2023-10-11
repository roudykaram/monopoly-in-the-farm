#include "CaseRessources.h"


CaseRessources::CaseRessources(int e, int s, int position, std::string letype){
    q_eau=e;
    q_soleil=s;
    pos=position;
    type=letype;
}

CaseRessources::~CaseRessources(){
    q_eau=0;
    q_soleil=0;
    pos=-1;
    type="NULL";
}

int CaseRessources::get_eau() const{
    return q_eau;
}

int CaseRessources::get_soleil() const{
    return q_soleil;
}