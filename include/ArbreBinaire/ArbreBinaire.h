//
// Created by Hugo on 12/02/2025.
//

#ifndef ARBREBINAIRE_H
#define ARBREBINAIRE_H

class CBinaryTree
{
    /* Attributes */
    private:
        int iBTRElement;
        CBinaryTree * pBTRGauche;
        CBinaryTree * pBTRDroit;

    /* Methods */
    public:
        /* Constructor */
        CBinaryTree() = default;
        CBinaryTree(const CBinaryTree & BTRArbre) = default;

        /* Destructor */
        virtual ~CBinaryTree() = default;

        /* Getters */
        [[nodiscard]] int getARBElement() const { return iBTRElement; };
        [[nodiscard]] CBinaryTree * getARBGauche() const { return pBTRGauche; };
        [[nodiscard]] CBinaryTree * getARBDroit() const { return pBTRDroit; };

        /* Setters */
        void setARBElement(const int iElement) { iBTRElement = iElement; };
        void setARBGauche(CBinaryTree * pGauche) { pBTRGauche = pGauche; };
        void setARBDroit(CBinaryTree * pDroit) { pBTRDroit = pDroit; };

        /* Methods */
        [[nodiscard]] virtual bool isInArbre(int iElement) const = 0;
        virtual void addElement(int iElement) = 0;
        virtual void removeElement(int iElement) = 0;
        [[nodiscard]] virtual CBinaryTree * searchElement(int iElement) const = 0;

};

#endif //ARBREBINAIRE_H
