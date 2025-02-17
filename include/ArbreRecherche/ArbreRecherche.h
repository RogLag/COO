#ifndef ARBRERECHERCHE_H
#define ARBRERECHERCHE_H

#include "ArbreBinaire.h"

/***************************************************
 * CLASSE: CSearchTree
 * *************************************************
 * ROLE: Classe qui permet de représenter un arbre
 *     binaire de recherche.
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

class CSearchTree : public CBinaryTree
{
    /* Methods */
    public:
        /*********************************************
         * METHOD: CSearchTree
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Un nouvel arbre de recherche est créé.
         *********************************************/
        CSearchTree();

        /*********************************************
         * METHOD: CSearchTree
         * *******************************************
         * ENTREE: ARBArbre, l'arbre de recherche à copier.
         * NECESSITE: ARBArbre doit être un objet valide de CSearchTree.
         * SORTIE: Rien.
         * ENTRAINE: Un nouvel arbre de recherche est créé comme copie de ARBArbre.
         *********************************************/
        CSearchTree(const CSearchTree & ARBArbre);

        /*********************************************
         * METHOD: CSearchTree
         * *******************************************
         * ENTREE: iElement, l'élément racine de l'arbre de recherche.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Un nouvel arbre de recherche est créé avec l'élément racine donné.
         *********************************************/
        explicit CSearchTree(int iElement);

        /*********************************************
         * METHOD: ~CSearchTree
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: L'arbre de recherche est détruit.
         *********************************************/
        ~CSearchTree() override;

        /*********************************************
         * METHOD: isInArbre
         * *******************************************
         * ENTREE: iElement, l'élément à rechercher.
         * NECESSITE: Rien.
         * SORTIE: Un booléen.
         * ENTRAINE: Retourne vrai si l'élément est dans l'arbre, faux sinon.
         *********************************************/
        [[nodiscard]] bool isInArbre(int iElement) const override;

        /*********************************************
         * METHOD: addElement
         * *******************************************
         * ENTREE: iElement, l'élément à ajouter.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Ajoute l'élément à l'arbre.
         *           Lève une exception si l'élément est déjà présent.
         *********************************************/
        void addElement(int iElement) override;

        /*********************************************
         * METHOD: removeElement
         * *******************************************
         * ENTREE: iElement, l'élément à supprimer.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Supprime l'élément de l'arbre.
         *********************************************/
        void removeElement(int iElement) override;

        /*********************************************
         * METHOD: searchElement
         * *******************************************
         * ENTREE: iElement, l'élément à rechercher.
         * NECESSITE: Rien.
         * SORTIE: Un pointeur sur l'élément recherché.
         * ENTRAINE: Retourne un pointeur sur l'élément recherché.
         *********************************************/
        [[nodiscard]] CBinaryTree * searchElement(int iElement) const override;
};

#include "ArbreRechercheInline.h"

#endif //ARBRERECHERCHE_H
