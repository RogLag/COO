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
    setARBGauche(ARBArbre.getARBGauche());
    setARBDroit(ARBArbre.getARBDroit());
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
        delete getARBGauche();
    }

    if (getARBDroit() != nullptr)
    {
        delete getARBDroit();
    }
}

