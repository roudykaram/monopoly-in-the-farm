
#include "Case.h"
#ifndef _CASERESSOURCES_H
#define  _CASERESSOURCES_H


    class CaseRessources: public Case {
        private:

        int q_eau;
        int q_soleil;
    
        public:
        

        /**
         * @brief Constructeur de CaseRessources
         * 
         * @param e 
         * @param s 
         * @param position 
         * @param letype 
         */
        CaseRessources(int e, int s, int position, std::string letype);


        /**
         * @brief Destructeur de CaseRessources
         * 
         */
        ~CaseRessources();


        /**
         * @brief Accesseur de quantite_eau
         * 
         * @return int 
         */

        int get_eau() const ;
        


        /**
         * @brief Accesseur de quantite_soleil
         * 
         * @return int 
         */
        int get_soleil() const;

        




    };
#endif


