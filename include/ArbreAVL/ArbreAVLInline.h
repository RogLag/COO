/*********************************************
 * METHOD: CAVLTree
 * *******************************************
 * ENTREE: Rien.
 * NECESSITE: Rien.
 * SORTIE: Rien.
 * ENTRAINE: Un nouvel arbre AVL est créé.
 *********************************************/
inline CAVLTree::CAVLTree()
{
    setARBElement(0);
    setARBGauche(nullptr);
    setARBDroit(nullptr);
}

/*********************************************
 * METHOD: CAVLTree
 * *******************************************
 * ENTREE: ARBArbre, l'arbre AVL à copier.
 * NECESSITE: ARBArbre doit être un objet valide de CAVLTree.
 * SORTIE: Rien.
 * ENTRAINE: Un nouvel arbre AVL est créé comme copie de ARBArbre.
 *********************************************/
inline CAVLTree::CAVLTree(const CAVLTree & ARBArbre)
{
    setARBElement(ARBArbre.getARBElement());

    if (ARBArbre.getARBGauche() != nullptr)
    {
        setARBGauche(new CAVLTree(*(static_cast<CAVLTree*>(ARBArbre.getARBGauche()))));
    }
    else
    {
        setARBGauche(nullptr);
    }

    if (ARBArbre.getARBDroit() != nullptr)
    {
        setARBDroit(new CAVLTree(*(static_cast<CAVLTree*>(ARBArbre.getARBDroit()))));
    }
    else
    {
        setARBDroit(nullptr);
    }
}

/*********************************************
 * METHOD: CAVLTree
 * *******************************************
 * ENTREE: iElement, l'élément racine de l'arbre AVL.
 * NECESSITE: Rien.
 * SORTIE: Rien.
 * ENTRAINE: Un nouvel arbre AVL est créé avec l'élément racine donné.
 *********************************************/
inline CAVLTree::CAVLTree(int iElement)
{
    setARBElement(iElement);
    setARBGauche(nullptr);
    setARBDroit(nullptr);
}

/*********************************************
 * METHOD: ~CAVLTree
 * *******************************************
 * ENTREE: Rien.
 * NECESSITE: Rien.
 * SORTIE: Rien.
 * ENTRAINE: L'arbre AVL est détruit.
 *********************************************/
inline CAVLTree::~CAVLTree()
{
    if (getARBGauche() != nullptr)
    {
        delete (CAVLTree*)getARBGauche();
    }

    if (getARBDroit() != nullptr)
    {
        delete (CAVLTree*)getARBDroit();
    }
}