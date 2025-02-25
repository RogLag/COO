//
// Created by Hugo on 12/02/2025.
//

#ifndef ARBREBINAIRE_H
#define ARBREBINAIRE_H

/***************************************************
 * CLASSE: CBinaryTree
 * *************************************************
 * ROLE: Classe abstraite qui permet de représenter
 *     un arbre binaire.
 * *************************************************
 * AUTHOR: Hugo MERY
 * DATE: 12/02/2025
 * ************************************************/

/*
 * TYPES:
 * Pas de types spécifiques à déclarer.
 */

/*
 * VARIABLES:
 * Pas de variables globales spécifiques à déclarer.
 */

class CBinaryTree
{
    /* Attributes */
    private:
        int iBTRElement;
        CBinaryTree * pBTRGauche;
        CBinaryTree * pBTRDroit;

    /* Methods */
    public:
        /*********************************************
         * METHOD: CBinaryTree
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Un nouvel arbre binaire est créé.
         *********************************************/
        CBinaryTree() = default;

        /*********************************************
         * METHOD: CBinaryTree
         * *******************************************
         * ENTREE: BTRArbre, l'arbre binaire à copier.
         * NECESSITE: BTRArbre doit être un objet valide de CBinaryTree.
         * SORTIE: Rien.
         * ENTRAINE: Un nouvel arbre binaire est créé comme copie de BTRArbre.
         *********************************************/
        CBinaryTree(const CBinaryTree & BTRArbre) = default;

        /*********************************************
         * METHOD: ~CBinaryTree
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: L'arbre binaire est détruit.
         *********************************************/
        virtual ~CBinaryTree() = default;

        /*********************************************
         * METHOD: getARBElement
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: L'élément de l'arbre.
         * ENTRAINE: L'élément de l'arbre est retourné.
         *********************************************/
        [[nodiscard]] int getARBElement() const { return iBTRElement; };

        /*********************************************
         * METHOD: getARBGauche
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: Le sous-arbre gauche.
         * ENTRAINE: Le sous-arbre gauche est retourné.
         *********************************************/
        [[nodiscard]] CBinaryTree * getARBGauche() const { return pBTRGauche; };

        /*********************************************
         * METHOD: getARBDroit
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: Le sous-arbre droit.
         * ENTRAINE: Le sous-arbre droit est retourné.
         *********************************************/
        [[nodiscard]] CBinaryTree * getARBDroit() const { return pBTRDroit; };


        /*********************************************
         * METHOD: setARBElement
         * *******************************************
         * ENTREE: iElement, l'élément de l'arbre.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: L'élément de l'arbre est modifié.
         *********************************************/
        void setARBElement(const int iElement) { iBTRElement = iElement; };

        /*********************************************
         * METHOD: setARBGauche
         * *******************************************
         * ENTREE: pGauche, le sous-arbre gauche.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Le sous-arbre gauche est modifié.
         *********************************************/
        void setARBGauche(CBinaryTree * pGauche) { pBTRGauche = pGauche; };

        /*********************************************
         * METHOD: setARBDroit
         * *******************************************
         * ENTREE: pDroit, le sous-arbre droit.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Le sous-arbre droit est modifié.
         *********************************************/
        void setARBDroit(CBinaryTree * pDroit) { pBTRDroit = pDroit; };


        /*********************************************************************
         * METHOD: isInTree
         * *******************************************************************
         * ENTREE: iElement, l'élément à rechercher.
         * NECESSITE: Rien.
         * SORTIE: Un booléen.
         * ENTRAINE: Retourne vrai si l'élément est dans l'arbre, faux sinon.
         *********************************************************************/
        [[nodiscard]] virtual bool isInTree(int iElement) const = 0;

        /*********************************************************************
         * METHOD: addElement
         * *******************************************************************
         * ENTREE: iElement, l'élément à ajouter.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Ajoute l'élément à l'arbre.
         *           Lève une exception si l'élément est déjà présent.
         *********************************************************************/
        virtual void addElement(int iElement) = 0;

        /*********************************************************************
         * METHOD: removeElement
         * *******************************************************************
         * ENTREE: iElement, l'élément à supprimer.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Supprime l'élément de l'arbre.
         *********************************************************************/
        virtual void removeElement(int iElement) = 0;

        /*********************************************************************
         * METHOD: searchElement
         * *******************************************************************
         * ENTREE: iElement, l'élément à rechercher.
         * NECESSITE: Rien.
         * SORTIE: Un pointeur sur l'élément recherché.
         * ENTRAINE: Retourne un pointeur sur l'élément recherché.
         *********************************************************************/
        [[nodiscard]] virtual CBinaryTree * searchElement(int iElement) const = 0;

};

#endif //ARBREBINAIRE_H
