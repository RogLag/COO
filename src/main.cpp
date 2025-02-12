#include "Exception.h"
#include "ArbreRecherche.h"

#include <iostream>

int main()
{
    try
    {
        const CException Exception(ExceptionCode::INVALID_OPERATION, "This is a test");
        Exception.display();
        const CException Exception2(ExceptionCode::DUPLICATE_ELEMENT, "This is another test");
        Exception2.display();
        const CException Exception3(ExceptionCode::ELEMENT_NOT_FOUND, "This is a third test");
        Exception3.display();

        CSearchTree Tree(5);
        Tree.addElement(3);
        Tree.addElement(8);
        Tree.addElement(2);
        Tree.addElement(4);
        Tree.addElement(7);

        std::cout << "Is 3 in the tree? " << Tree.isInArbre(3) << std::endl;
        std::cout << "Is 8 in the tree? " << Tree.isInArbre(8) << std::endl;
        std::cout << "Is 9 in the tree? " << Tree.isInArbre(9) << std::endl;

        Tree.removeElement(3);

        std::cout << "Is 3 in the tree? " << Tree.isInArbre(3) << std::endl;
        std::cout << "Is 2 in the tree? " << Tree.isInArbre(2) << std::endl;
    }
    catch (const CException & e)
    {
        e.display();
    }

    return 0;
}