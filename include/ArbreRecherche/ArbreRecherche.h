//
// Created by Hugo on 12/02/2025.
//

#ifndef ARBRERECHERCHE_H
#define ARBRERECHERCHE_H

#include "ArbreBinaire.h"

/**
 * @class CSearchTree
 * @brief Class for a binary search tree.
 */
class CSearchTree : public CBinaryTree
{
    /* Methods */
    public:
        /**
         * @brief Default constructor.
         * @pre None.
         * @post A new search tree is created with default values.
         */
        CSearchTree();

        /**
         * @brief Copy constructor.
         * @param ARBArbre The search tree to copy.
         * @pre ARBArbre must be a valid CSearchTree object.
         * @post A new search tree is created as a copy of ARBArbre.
         */
        CSearchTree(const CSearchTree & ARBArbre);

        /**
         * @brief Parameterized constructor.
         * @param iElement The root element of the search tree.
         * @pre None.
         * @post A new search tree is created with the given root element.
         */
        explicit CSearchTree(int iElement);

        /**
         * @brief Destructor.
         * @pre None.
         * @post The search tree is destroyed.
         */
        ~CSearchTree() override;

        /**
         * @brief Check if an element is in the tree.
         * @param iElement The element to search for.
         * @return True if the element is in the tree, false otherwise.
         * @pre None.
         * @post Returns true if the element is found, false otherwise.
         */
        [[nodiscard]] bool isInArbre(int iElement) const override;

        /**
         * @brief Add an element to the tree.
         * @param iElement The element to add.
         * @pre None.
         * @post The element is added to the tree.
         * @throws CException if the element already exists in the tree.
         */
        void addElement(int iElement) override;

        /**
         * @brief Remove an element from the tree.
         * @param iElement The element to remove.
         * @pre None.
         * @post The element is removed from the tree.
         * @throws CException if the element does not exist in the tree.
         */
        void removeElement(int iElement) override;

        /**
         * @brief Search for an element in the tree.
         * @param iElement The element to search for.
         * @return A pointer to the node containing the element, or nullptr if not found.
         * @pre None.
         * @post Returns a pointer to the node containing the element, or nullptr if not found.
         * @throws CException if the element does not exist in the tree.
         */
        [[nodiscard]] CBinaryTree * searchElement(int iElement) const override;
};

#include "ArbreRechercheInline.h"

#endif //ARBRERECHERCHE_H
