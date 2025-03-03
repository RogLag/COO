#include "Exception.h"
#include "ArbreRecherche.h"
#include "ArbreAVL.h"

#include <iostream>

int main()
{
    try
    {
        const CException Exception(ExceptionCode::INVALID_OPERATION, "main : This is a test for INVALID_OPERATION");
        Exception.display();
        const CException Exception2(ExceptionCode::DUPLICATE_ELEMENT, "main : This is a second test for DUPLICATE_ELEMENT");
        Exception2.display();
        const CException Exception3(ExceptionCode::ELEMENT_NOT_FOUND, "main : This is a third test for ELEMENT_NOT_FOUND");
        Exception3.display();

        CSearchTree Tree(5);
        Tree.addElement(3);
        Tree.addElement(8);
        Tree.addElement(2);
        Tree.addElement(4);
        Tree.addElement(7);

        std::cout << "Is 3 in the tree? " << Tree.isInTree(3) << std::endl;
        std::cout << "Is 8 in the tree? " << Tree.isInTree(8) << std::endl;
        std::cout << "Is 9 in the tree? " << Tree.isInTree(9) << std::endl;

        Tree.removeElement(3);

        std::cout << "Is 3 in the tree? " << Tree.isInTree(3) << std::endl;
        std::cout << "Is 2 in the tree? " << Tree.isInTree(2) << std::endl;

        std::cout << "--------------------------------" << std::endl;

        CAVLTree Tree2(5);
        Tree2.addElement(3);
        Tree2.addElement(8);
        Tree2.addElement(2);
        Tree2.addElement(4);
        Tree2.addElement(7);

        std::cout << "Is 3 in the tree? " << Tree2.isInTree(3) << std::endl;
        std::cout << "Is 8 in the tree? " << Tree2.isInTree(8) << std::endl;
        std::cout << "Is 9 in the tree? " << Tree2.isInTree(9) << std::endl;

        Tree2.removeElement(3);

        std::cout << "Is 3 in the tree? " << Tree2.isInTree(3) << std::endl;
        std::cout << "Is 2 in the tree? " << Tree2.isInTree(2) << std::endl;

        const CBinaryTree * search2 = Tree2.searchElement(3);

        std::cout << search2 << std::endl;
    }
    catch (const CException & e)
    {
        e.display();
    }

    return 0;
}