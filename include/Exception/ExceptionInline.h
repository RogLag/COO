/*********************************************
 * METHOD: CException
 * *******************************************
 * ENTREE: Rien.
 * NECESSITE: Rien.
 * SORTIE: Rien.
 * ENTRAINE: Un objet exception est créé avec des valeurs par défaut.
 *********************************************/
inline CException::CException()
{
    uiEXCCode = ExceptionCode::INVALID_OPERATION;
    sEXCDescription = "";
}

/*********************************************
 * METHOD: CException
 * *******************************************
 * ENTREE: EXCException, l'objet exception à copier.
 * NECESSITE: EXCException doit être un objet valide de CException.
 * SORTIE: Rien.
 * ENTRAINE: Un nouvel objet exception est créé comme copie de EXCException.
 *********************************************/
inline CException::CException(const CException & EXCException)
{
    uiEXCCode = EXCException.uiEXCCode;
    sEXCDescription = EXCException.sEXCDescription;
}

/*********************************************
 * METHOD: CException
 * *******************************************
 * ENTREE: uiCode, le code de l'exception.
 *         sDescription, la description de l'exception.
 * NECESSITE: Rien.
 * SORTIE: Rien.
 * ENTRAINE: Un objet exception est créé avec le code et la description donnés.
 *********************************************/
inline CException::CException(ExceptionCode uiCode, const std::string & sDescription)
{
    uiEXCCode = uiCode;
    sEXCDescription = sDescription;
}

/*********************************************
 * METHOD: getDefaultTitle
 * *******************************************
 * ENTREE: code, le code de l'exception.
 * NECESSITE: Rien.
 * SORTIE: Le titre par défaut pour le code d'exception.
 * ENTRAINE: Retourne le titre par défaut pour le code d'exception.
 *********************************************/
inline std::string CException::getDefaultTitle(ExceptionCode code)
{
    static const std::unordered_map<ExceptionCode, std::string> exceptionTitles = {
        {ExceptionCode::ELEMENT_NOT_FOUND, "Element Not Found"},
        {ExceptionCode::DUPLICATE_ELEMENT, "Duplicate Element"},
        {ExceptionCode::INVALID_OPERATION, "Invalid Operation"}
    };

    auto it = exceptionTitles.find(code);
    if (it != exceptionTitles.end()) {
        return it->second;
    } else {
        return "Unknown Exception";
    }
}