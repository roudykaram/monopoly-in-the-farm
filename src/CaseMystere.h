
#include"Case.h"
#include <string>
#ifndef _CASEMYSTERE_H
#define  _CASEMYSTERE_H



class CaseMystere: public Case{
    private:

    int qe[7]; //quantite d'eau
    int qs[7]; //quantite de soleil

    public:

    /**
     * @brief Constructeur par defaut de la classe CaseMystere
     * 
     */
    CaseMystere();

    /**
     * @brief Accesseur de la quantite d'eau qe
     * 
     * @param i 
     * @return int 
     */
    int get_qe(int i) const;

    /**
     * @brief Accesseur de la quantite de soleil qs
     * 
     * @param i 
     * @return int 
     */
    int get_qs(int i) const;
};

#endif





























