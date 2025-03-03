#include "ArbreAVL.h"
#include "Exception.h"

int CAVLTree::getHeight() const
{
    int iLeftHeight = 0;
    int iRightHeight = 0;

    if (getARBGauche() != nullptr)
    {
        iLeftHeight = ((CAVLTree*)getARBGauche())->getHeight();
    }

    if (getARBDroit() != nullptr)
    {
        iRightHeight = ((CAVLTree*)getARBDroit())->getHeight();
    }

    return 1 + std::max(iLeftHeight, iRightHeight);
}

bool CAVLTree::checkBalance() const
{
    int iLeftHeight = 0;
    int iRightHeight = 0;

    if (getARBGauche() != nullptr)
    {
        iLeftHeight = ((CAVLTree*)getARBGauche())->getHeight();
    }

    if (getARBDroit() != nullptr)
    {
        iRightHeight = ((CAVLTree*)getARBDroit())->getHeight();
    }

    return abs(iLeftHeight - iRightHeight) <= 1;
}

void CAVLTree::balanceTree() 
{
    if (!checkBalance())
    {
        if (getARBGauche() != nullptr)
        {
            if (!((CAVLTree*)getARBGauche())->checkBalance())
            {
                if (getARBGauche()->getARBElement() > getARBElement())
                {
                    ((CAVLTree*)getARBGauche())->rotateLeft();
                }
            }
        }
        if (getARBDroit() != nullptr)
        {
            if (!((CAVLTree*)getARBDroit())->checkBalance())
            {
                if (getARBDroit()->getARBElement() < getARBElement())
                {
                    ((CAVLTree*)getARBDroit())->rotateRight();
                }
            }
        }
        if (getARBGauche() != nullptr)
        {
            if (getARBGauche()->getARBElement() > getARBElement())
            {
                rotateLeft();
            }
        }
        if (getARBDroit() != nullptr)
        {
            if (getARBDroit()->getARBElement() < getARBElement())
            {
                rotateRight();
            }
        }
    }
}

void CAVLTree::rotateLeft() 
{
    CBinaryTree* rightChild = getARBDroit();
    if (!rightChild) return;

    setARBDroit(rightChild->getARBGauche());
    rightChild->setARBGauche(this);

    int tempElement = getARBElement();
    setARBElement(rightChild->getARBElement());
    rightChild->setARBElement(tempElement);

    CBinaryTree* tempRight = rightChild->getARBDroit();
    rightChild->setARBDroit(tempRight);
}

void CAVLTree::rotateRight() 
{
    CBinaryTree* leftChild = getARBGauche();
    if (!leftChild) return;

    setARBGauche(leftChild->getARBDroit());
    leftChild->setARBDroit(this);

    int tempElement = getARBElement();
    setARBElement(leftChild->getARBElement());
    leftChild->setARBElement(tempElement);

    CBinaryTree* tempLeft = leftChild->getARBGauche();
    leftChild->setARBGauche(tempLeft);
}

bool CAVLTree::isInTree(int iElement) const 
{
    if (getARBElement() == iElement)
    {
        return true;
    }
    else if (getARBElement() > iElement)
    {
        if (getARBGauche() != nullptr)
        {
            return getARBGauche()->isInTree(iElement);
        }
    }
    else
    {
        if (getARBDroit() != nullptr)
        {
            return getARBDroit()->isInTree(iElement);
        }
    }

    return false;
}

void CAVLTree::addElement(int iElement) 
{
    if (getARBElement() == iElement)
    {
        throw CException(ExceptionCode::DUPLICATE_ELEMENT, "CAVLTree::addElement : The element already exists in the tree.");
    }
    else if (getARBElement() > iElement)
    {
        if (getARBGauche() != nullptr)
        {
            getARBGauche()->addElement(iElement);
        }
        else
        {
            setARBGauche(new CAVLTree(iElement));
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
            setARBDroit(new CAVLTree(iElement));
        }
    }
    balanceTree();
}

void CAVLTree::removeElement(int iElement) 
{
    if (!isInTree(iElement))
    {
        throw CException(ExceptionCode::ELEMENT_NOT_FOUND, "CAVLTree::removeElement : The element does not exist in the tree.");
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
    balanceTree();
}

CBinaryTree* CAVLTree::searchElement(int iElement) const {
    if (getARBElement() == iElement)
    {
        return (CAVLTree *) this;
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

    throw CException(ExceptionCode::ELEMENT_NOT_FOUND, "CAVLTree::searchElement : The element does not exist in the tree.");
}
