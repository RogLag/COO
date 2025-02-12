//
// Created by Hugo on 12/02/2025.
//

#include "ArbreRecherche.h"
#include "Exception.h"

/**
 * @brief Check if an element is in the tree.
 * @param iElement The element to search for.
 * @return True if the element is in the tree, false otherwise.
 * @pre None.
 * @post Returns true if the element is found, false otherwise.
 */
bool CSearchTree::isInArbre(int iElement) const
{
    if (getARBElement() == iElement)
    {
        return true;
    }
    else if (getARBElement() > iElement)
    {
        if (getARBGauche() != nullptr)
        {
            return getARBGauche()->isInArbre(iElement);
        }
    }
    else
    {
        if (getARBDroit() != nullptr)
        {
            return getARBDroit()->isInArbre(iElement);
        }
    }

    return false;
}

/**
 * @brief Add an element to the tree.
 * @param iElement The element to add.
 * @pre None.
 * @post The element is added to the tree.
 * @throws CException if the element already exists in the tree.
 */
void CSearchTree::addElement(int iElement)
{
    if (getARBElement() == iElement)
    {
        throw CException(ExceptionCode::DUPLICATE_ELEMENT, "The element already exists in the tree.");
    }
    else if (getARBElement() > iElement)
    {
        if (getARBGauche() != nullptr)
        {
            getARBGauche()->addElement(iElement);
        }
        else
        {
            setARBGauche(new CSearchTree(iElement));
        }
    }
    else
    {
        if (getARBDroit() != nullptr)
        {
            getARBDroit()->addElement(iElement);
        }
        else
        {
            setARBDroit(new CSearchTree(iElement));
        }
    }
}

/**
 * @brief Remove an element from the tree.
 * @param iElement The element to remove.
 * @pre None.
 * @post The element is removed from the tree.
 * @throws CException if the element does not exist in the tree.
 */
void CSearchTree::removeElement(int iElement)
{
    if (!isInArbre(iElement))
    {
        throw CException(ExceptionCode::ELEMENT_NOT_FOUND, "The element does not exist in the tree.");
    }

    if (getARBElement() == iElement)
    {
        if (getARBGauche() != nullptr)
        {
            if (getARBGauche()->getARBDroit() != nullptr)
            {
                CBinaryTree * pTemp = getARBGauche()->getARBDroit();
                setARBElement(pTemp->getARBElement());
                getARBGauche()->setARBDroit(pTemp->getARBGauche());
                getARBGauche()->setARBGauche(pTemp->getARBGauche());
                delete pTemp;
            }
            else
            {
                CBinaryTree * pTemp = getARBGauche();
                setARBElement(pTemp->getARBElement());
                setARBGauche(pTemp->getARBGauche());
                delete pTemp;
            }
        }
        else if (getARBDroit() != nullptr)
        {
            if (getARBDroit()->getARBGauche() != nullptr)
            {
                CBinaryTree * pTemp = getARBDroit()->getARBGauche();
                setARBElement(pTemp->getARBElement());
                getARBDroit()->setARBGauche(pTemp->getARBDroit());
                getARBDroit()->setARBDroit(pTemp->getARBDroit());
                delete pTemp;
            }
            else
            {
                CBinaryTree * pTemp = getARBDroit();
                setARBElement(pTemp->getARBElement());
                setARBDroit(pTemp->getARBDroit());
                delete pTemp;
            }
        }
        else
        {
            delete this;
        }
    }
    else if (getARBElement() > iElement)
    {
        if (getARBGauche() != nullptr)
        {
            getARBGauche()->removeElement(iElement);
        }
    }
    else
    {
        if (getARBDroit() != nullptr)
        {
            getARBDroit()->removeElement(iElement);
        }
    }
}

/**
 * @brief Search for an element in the tree.
 * @param iElement The element to search for.
 * @return A pointer to the node containing the element, or nullptr if not found.
 * @pre None.
 * @post Returns a pointer to the node containing the element, or nullptr if not found.
 * @throws CException if the element does not exist in the tree.
 */
CBinaryTree * CSearchTree::searchElement(int iElement) const
{
    if (getARBElement() == iElement)
    {
        return const_cast<CSearchTree *>(this);
    }
    else if (getARBElement() > iElement)
    {
        if (getARBGauche() != nullptr)
        {
            return getARBGauche()->searchElement(iElement);
        }
    }
    else
    {
        if (getARBDroit() != nullptr)
        {
            return getARBDroit()->searchElement(iElement);
        }
    }

    throw CException(ExceptionCode::ELEMENT_NOT_FOUND, "The element does not exist in the tree.");
}