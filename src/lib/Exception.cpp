//
// Created by Hugo on 12/02/2025.
//

#include "Exception.h"
#include <iostream>

/*********************************************
 * METHOD: display
 * *******************************************
 * ENTREE: Rien.
 * NECESSITE: Rien.
 * SORTIE: Rien.
 * ENTRAINE: Les détails de l'exception sont affichés sur la console.
 *********************************************/
void CException::display() const
{
    std::endl(std::cout);
    std::cout << "Exception" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Code: " << (const int)(uiEXCCode) << std::endl;
    std::cout << "Title: " << getDefaultTitle(uiEXCCode) << std::endl;
    std::cout << sEXCDescription << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::endl(std::cout);
}