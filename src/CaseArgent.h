#include "Case.h"
#ifndef _CASEARGENT_H
#define _CASEARGENT_H

class CaseArgent: public Case{

    private:

    int montant;


    public:

    /**
     * @brief Constructeur de CaseArgent
     * 
     * @param argent 
     * @param position 
     * @param letype 
     */
    CaseArgent(int argent, int position, std::string letype);

    /**
     * @brief Accesseur de montant
     * 
     * @return int 
     */
    virtual int get_montant()const;

    /**
     * @brief Mutateur de montant
     * 
     * @param monnaie 
     */
    void set_montant(int monnaie);


};

#endif