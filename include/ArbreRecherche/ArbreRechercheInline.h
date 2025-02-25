/*********************************************
 * METHOD: CSearchTree
 * *******************************************
 * ENTREE: Rien.
 * NECESSITE: Rien.
 * SORTIE: Rien.
 * ENTRAINE: Un nouvel arbre de recherche est créé.
 *********************************************/
inline CSearchTree::CSearchTree()
{
    setARBElement(0);
    setARBGauche(nullptr);
    setARBDroit(nullptr);
}

/*********************************************
 * METHOD: CSearchTree
 * *******************************************
 * ENTREE: ARBArbre, l'arbre de recherche à copier.
 * NECESSITE: ARBArbre doit être un objet valide de CSearchTree.
 * SORTIE: Rien.
 * ENTRAINE: Un nouvel arbre de recherche est créé comme copie de ARBArbre.
 *********************************************/
inline CSearchTree::CSearchTree(const CSearchTree & ARBArbre)
{
    setARBElement(ARBArbre.getARBElement());
    
    if (ARBArbre.getARBGauche() != nullptr)
    {
        setARBGauche(new CSearchTree(*(static_cast<CSearchTree*>(ARBArbre.getARBGauche()))));
    }
    else
    {
        setARBGauche(nullptr);
    }

    if (ARBArbre.getARBDroit() != nullptr)
    {
        setARBDroit(new CSearchTree(*(static_cast<CSearchTree*>(ARBArbre.getARBDroit()))));
    }
    else
    {
        setARBDroit(nullptr);
    }
}

/*********************************************
 * METHOD: CSearchTree
 * *******************************************
 * ENTREE: iElement, l'élément racine de l'arbre de recherche.
 * NECESSITE: Rien.
 * SORTIE: Rien.
 * ENTRAINE: Un nouvel arbre de recherche est créé avec l'élément racine donné.
 *********************************************/
inline CSearchTree::CSearchTree(int iElement)
{
    setARBElement(iElement);
    setARBGauche(nullptr);
    setARBDroit(nullptr);
}

/*********************************************
 * METHOD: ~CSearchTree
 * *******************************************
 * ENTREE: Rien.
 * NECESSITE: Rien.
 * SORTIE: Rien.
 * ENTRAINE: L'arbre de recherche est détruit.
 *********************************************/
inline CSearchTree::~CSearchTree()
{
    if (getARBGauche() != nullptr)
    {
        delete (CSearchTree*)getARBGauche();
    }

    if (getARBDroit() != nullptr)
    {
        delete (CSearchTree*)getARBDroit();
    }
}

