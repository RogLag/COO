//
// Created by Hugo on 12/02/2025.
//

inline CException::CException()
{
    uiEXCCode = ExceptionCode::INVALID_OPERATION;
    sEXCTitle = getDefaultTitle(uiEXCCode);
    sEXCDescription = "";
}

inline CException::CException(const CException & EXCException)
{
    uiEXCCode = EXCException.uiEXCCode;
    sEXCTitle = EXCException.sEXCTitle;
    sEXCDescription = EXCException.sEXCDescription;
}

inline CException::CException(ExceptionCode uiCode, const std::string & sDescription)
{
    uiEXCCode = uiCode;
    sEXCTitle = getDefaultTitle(uiCode);
    sEXCDescription = sDescription;
}

inline std::string CException::getDefaultTitle(ExceptionCode code) const
{
    switch (code)
    {
        case ExceptionCode::ELEMENT_NOT_FOUND:
            return "Element Not Found";
        case ExceptionCode::DUPLICATE_ELEMENT:
            return "Duplicate Element";
        case ExceptionCode::INVALID_OPERATION:
            return "Invalid Operation";
        default:
            return "Unknown Exception";
    }
}