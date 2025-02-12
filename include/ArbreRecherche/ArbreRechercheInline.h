//
// Created by Hugo on 12/02/2025.
//

inline CSearchTree::CSearchTree()
{
    setARBElement(0);
    setARBGauche(nullptr);
    setARBDroit(nullptr);
}

inline CSearchTree::CSearchTree(const CSearchTree & ARBArbre)
{
    setARBElement(ARBArbre.getARBElement());
    setARBGauche(ARBArbre.getARBGauche());
    setARBDroit(ARBArbre.getARBDroit());
}

inline CSearchTree::CSearchTree(int iElement)
{
    setARBElement(iElement);
    setARBGauche(nullptr);
    setARBDroit(nullptr);
}

inline CSearchTree::~CSearchTree()
{
    if (getARBGauche() != nullptr)
    {
        delete getARBGauche();
    }

    if (getARBDroit() != nullptr)
    {
        delete getARBDroit();
    }
}

