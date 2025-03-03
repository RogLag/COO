//
// Created by Hugo on 24/02/2025.
//

#ifndef ARBREAVL_H
#define ARBREAVL_H

#include "ArbreBinaire.h"

/***************************************************
 * CLASSE: CAVLTree
 * *************************************************
 * ROLE: Classe qui permet de représenter un arbre
 *     AVL.
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

class CAVLTree : public CBinaryTree
{
    /* Methods */
    private:
      	/*********************************************
         * METHOD: balanceTree
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Equilibre l'arbre AVL.
         *********************************************/
        void balanceTree();

        bool checkBalance() const;

        int getHeight() const;

        /*********************************************
         * METHOD: rotateLeft
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Fais une rotation à gauche.
         *********************************************/
        void rotateLeft();

        /*********************************************
         * METHOD: rotateRight
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Fais une rotation à droite.
         *********************************************/
        void rotateRight();

    public:
        /*********************************************
         * METHOD: CAVLTree
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Un nouvel arbre AVL est créé.
         *********************************************/
        CAVLTree();

        /*********************************************
         * METHOD: CAVLTree
         * *******************************************
         * ENTREE: ARBArbre, l'arbre AVL à copier.
         * NECESSITE: ARBArbre doit être un objet valide de CAVLTree.
         * SORTIE: Rien.
         * ENTRAINE: Un nouvel arbre AVL est créé comme copie de ARBArbre.
         *********************************************/
        CAVLTree(const CAVLTree & ARBArbre);

        /*********************************************
         * METHOD: CAVLTree
         * *******************************************
         * ENTREE: iElement, l'élément racine de l'arbre AVL.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Un nouvel arbre AVL est créé avec l'élément racine donné.
         *********************************************/
        explicit CAVLTree(int iElement);

        /*********************************************
         * METHOD: ~CAVLTree
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: L'arbre AVL est détruit.
         *********************************************/
        ~CAVLTree() override;

        /*********************************************
         * METHOD: isInTree
         * *******************************************
         * ENTREE: iElement, l'élément à rechercher.
         * NECESSITE: Rien.
         * SORTIE: Un booléen.
         * ENTRAINE: Retourne vrai si l'élément est dans l'arbre, faux sinon.
         *********************************************/
        [[nodiscard]] bool isInTree(int iElement) const override;

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

#include "ArbreAVLInline.h"

#endif //ARBREAVL_H
