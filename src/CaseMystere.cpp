#include"CaseMystere.h"

CaseMystere::CaseMystere(){
    int n=-3;
    //dans la 1ere on met -3, dans la 2eme -2....
    for (int i =0;i < 7 ;i++){
        qe[i]=n;
        qs[i]=n;
        n++;
    }
}


int CaseMystere::get_qe(int i ) const{
    return qe[i];
}

int CaseMystere::get_qs(int i) const{
    return qs[i];
}