//
// Created by Hugo on 12/02/2025.
//

#include "ArbreRecherche.h"
#include "Exception.h"

/*********************************************
 * METHOD: isInArbre
 * *******************************************
 * ENTREE: iElement, l'élément à rechercher.
 * NECESSITE: Rien.
 * SORTIE: Un booléen.
 * ENTRAINE: Retourne vrai si l'élément est dans l'arbre, faux sinon.
 *********************************************/
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

/*********************************************
 * METHOD: addElement
 * *******************************************
 * ENTREE: iElement, l'élément à ajouter.
 * NECESSITE: Rien.
 * SORTIE: Rien.
 * ENTRAINE: Ajoute l'élément à l'arbre.
 *           Lève une exception si l'élément est déjà présent.
 *********************************************/
void CSearchTree::addElement(int iElement)
{
    if (getARBElement() == iElement)
    {
        throw CException(ExceptionCode::DUPLICATE_ELEMENT, "CSearchTree::addElement : The element already exists in the tree.");
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

/*********************************************
 * METHOD: removeElement
 * *******************************************
 * ENTREE: iElement, l'élément à supprimer.
 * NECESSITE: Rien.
 * SORTIE: Rien.
 * ENTRAINE: Supprime l'élément de l'arbre.
 *********************************************/
void CSearchTree::removeElement(int iElement)
{
    if (!isInArbre(iElement))
    {
        throw CException(ExceptionCode::ELEMENT_NOT_FOUND, "CSearchTree::removeElement : The element does not exist in the tree.");
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

/*********************************************
 * METHOD: searchElement
 * *******************************************
 * ENTREE: iElement, l'élément à rechercher.
 * NECESSITE: Rien.
 * SORTIE: Un pointeur sur l'élément recherché.
 * ENTRAINE: Retourne un pointeur sur l'élément recherché.
 *********************************************/
CBinaryTree * CSearchTree::searchElement(int iElement) const
{
    if (getARBElement() == iElement)
    {
        return (CSearchTree *) this;
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

    throw CException(ExceptionCode::ELEMENT_NOT_FOUND, "CSearchTree::searchElement : The element does not exist in the tree.");
}