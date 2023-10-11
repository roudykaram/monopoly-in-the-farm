#ifndef _COULEUR_H
#define  _COULEUR_H


class Couleur {

    private:

    unsigned char r,g,b;

    public:
    Couleur();
    /**
     * @brief Construct a new Couleur object
     * 
     * @param nr 
     * @param ng 
     * @param nb 
     */
    Couleur(unsigned char nr, unsigned char ng, unsigned char nb);
    
    /**
     * @brief recupere la composante rouge de la couleur
     * 
     * @return unsigned char 
     */
    unsigned char getRouge() const;

    /**
     * @brief Get the Vert object
     * 
     * @return unsigned char 
     */
    unsigned char getVert()const ;


    /**
     * @brief Get the Bleu object
     * 
     * @return unsigned char 
     */
    unsigned char getBleu()const;


    /**
     * @brief Set the Rouge object
     * 
     * @param nr 
     */
    void setRouge(unsigned char nr);

    /**
     * @brief Set the Vert object
     * 
     * @param ng 
     */

    void setVert(unsigned char ng);


    /**
     * @brief Set the Bleu object
     * 
     * @param nb 
     */

    void setBleu(unsigned char nb);


};

#endif