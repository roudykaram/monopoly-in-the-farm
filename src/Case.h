#include <string>
#ifndef CASE_H
#define CASE_H



using namespace std;

class Case{
    protected:

    int pos;
    std::string type;
     

    public:

    /**
     * @brief Constructeur de Case
     * 
     */
    Case();
   
    /**
     * @brief Constructeur par copie avec l'indice et le type en parametre
     * 
     * @param indice 
     * @param t 
     */
    Case(int indice, std::string t);

    
    /**
     * @brief Destructeur de Case
     * 
     */
    virtual ~Case();


    /**
     * @brief Mutateur du type
     * 
     * @param letype 
     */

    void set_type(std::string letype);

    /**
     * @brief Mutateur de Position
     * 
     * @return int 
     */
    int get_pos()const;

//fonctions CasePropriete

    virtual void set_prix(unsigned int i);

    virtual int get_prix()const;

    virtual  int get_proprio() const;

    virtual int get_loyer()const;

    virtual void set_proprio(int i);

    virtual int get_nb_arbre()const;

    virtual int get_nb_jardin()const;

    virtual void set_nb_jardin(int i);

    virtual void set_nb_arbre(int i);

    virtual int calculer_loyer();

    virtual void set_loyer(int nouveau_montant);
//fonction CaseArgent
    virtual int get_montant()const;
    virtual void set_montant(int montant);

//fonctions CaseRessources
    virtual int get_eau() const;   
    
    virtual int get_soleil() const; 

//fonctions CaseMystere
    virtual int get_qe(int i) const;

    virtual int get_qs(int i) const;

};



#endif