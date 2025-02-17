#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <unordered_map>

/***************************************************
 * ENUMERATION: ExceptionCode
 * *************************************************
 * ROLE: Enumération pour les codes d'exception.
 * *************************************************
 * AUTHOR: Hugo MERY
 * DATE: 12/02/2025
 * ************************************************/
enum class ExceptionCode {
    ELEMENT_NOT_FOUND = 1, ///< Element not found in the tree.
    DUPLICATE_ELEMENT = 2, ///< Duplicate element in the tree.
    INVALID_OPERATION = 3  ///< Invalid operation.
};

/***************************************************
 * CLASSE: CException
 * *************************************************
 * ROLE: Classe pour gérer les exceptions.
 * *************************************************
 * AUTHOR: Hugo MERY
 * DATE: 12/02/2025
 * ************************************************/
class CException
{
    /* Attributes */
    private:
        ExceptionCode uiEXCCode; ///< Exception code.
        std::string sEXCDescription; ///< Exception description.

        /*********************************************
         * METHOD: getDefaultTitle
         * *******************************************
         * ENTREE: code, le code de l'exception.
         * NECESSITE: Rien.
         * SORTIE: Le titre par défaut pour le code d'exception.
         * ENTRAINE: Retourne le titre par défaut pour le code d'exception.
         *********************************************/
        static std::string getDefaultTitle(ExceptionCode code);

    /* Methods */
    public:
        /*********************************************
         * METHOD: CException
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Un objet exception est créé avec des valeurs par défaut.
         *********************************************/
        CException();

        /*********************************************
         * METHOD: CException
         * *******************************************
         * ENTREE: EXCException, l'objet exception à copier.
         * NECESSITE: EXCException doit être un objet valide de CException.
         * SORTIE: Rien.
         * ENTRAINE: Un nouvel objet exception est créé comme copie de EXCException.
         *********************************************/
        CException(const CException & EXCException);

        /*********************************************
         * METHOD: CException
         * *******************************************
         * ENTREE: uiCode, le code de l'exception.
         *         sDescription, la description de l'exception.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Un objet exception est créé avec le code et la description donnés.
         *********************************************/
        CException(ExceptionCode uiCode, const std::string & sDescription);

        /*********************************************
         * METHOD: ~CException
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: L'objet exception est détruit.
         *********************************************/
        ~CException() = default;

        /*********************************************
         * METHOD: getEXCCode
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: Le code de l'exception.
         * ENTRAINE: Retourne le code de l'exception.
         *********************************************/
        [[nodiscard]] ExceptionCode getEXCCode() const { return uiEXCCode; };

        /*********************************************
         * METHOD: getEXCDescription
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: La description de l'exception.
         * ENTRAINE: Retourne la description de l'exception.
         *********************************************/
        [[nodiscard]] std::string getEXCDescription() const { return sEXCDescription; };

        /*********************************************
         * METHOD: setEXCCode
         * *******************************************
         * ENTREE: uiCode, le code de l'exception.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Le code de l'exception est modifié.
         *********************************************/
        void setEXCCode(ExceptionCode uiCode) { uiEXCCode = uiCode; };

        /*********************************************
         * METHOD: setEXCDescription
         * *******************************************
         * ENTREE: sDescription, la description de l'exception.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: La description de l'exception est modifiée.
         *********************************************/
        void setEXCDescription(const std::string & sDescription) { sEXCDescription = sDescription; };

        /*********************************************
         * METHOD: display
         * *******************************************
         * ENTREE: Rien.
         * NECESSITE: Rien.
         * SORTIE: Rien.
         * ENTRAINE: Les détails de l'exception sont affichés sur la console.
         *********************************************/
        void display() const;
};

#include "ExceptionInline.h"

#endif //EXCEPTION_H
