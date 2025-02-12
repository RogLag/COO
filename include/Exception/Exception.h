//
// Created by Hugo on 12/02/2025.
//

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

/**
 * @enum ExceptionCode
 * @brief Enum for exception codes with a non exhaustive list of possible values.
 */
enum class ExceptionCode {
    ELEMENT_NOT_FOUND = 1, ///< Element not found in the tree.
    DUPLICATE_ELEMENT = 2, ///< Duplicate element in the tree.
    INVALID_OPERATION = 3  ///< Invalid operation.
};

/**
 * @class CException
 * @brief Class for handling exceptions.
 */
class CException
{
    /* Attributes */
    private:
        ExceptionCode uiEXCCode; ///< Exception code.
        std::string sEXCDescription; ///< Exception description.

        /**
         * @brief Get the default title for the given exception code.
         * @param code The exception code.
         * @return The default title for the exception code.
         */
        std::string getDefaultTitle(ExceptionCode code) const;

    /* Methods */
    public:
        /**
         * @brief Default constructor.
         * @pre None.
         * @post Exception object is created with default values.
         */
        CException();

        /**
         * @brief Copy constructor.
         * @param EXCException The exception object to copy.
         * @pre EXCException must be a valid CException object.
         * @post A new exception object is created as a copy of EXCException.
         */
        CException(const CException & EXCException);

        /**
         * @brief Parameterized constructor.
         * @param uiCode The exception code.
         * @param sDescription The exception description.
         * @pre None.
         * @post Exception object is created with the given code and description.
         */
        CException(ExceptionCode uiCode, const std::string & sDescription);

        /**
         * @brief Destructor.
         * @pre None.
         * @post Exception object is destroyed.
         */
        ~CException() = default;

        /**
         * @brief Get the exception code.
         * @return The exception code.
         * @pre None.
         * @post Returns the exception code.
         */
        [[nodiscard]] ExceptionCode getEXCCode() const { return uiEXCCode; };

        /**
         * @brief Get the exception description.
         * @return The exception description.
         * @pre None.
         * @post Returns the exception description.
         */
        [[nodiscard]] std::string getEXCDescription() const { return sEXCDescription; };

        /**
         * @brief Set the exception code.
         * @param uiCode The exception code.
         * @pre None.
         * @post The exception code is set to uiCode.
         */
        void setEXCCode(ExceptionCode uiCode) { uiEXCCode = uiCode; };

        /**
         * @brief Set the exception description.
         * @param sDescription The exception description.
         * @pre None.
         * @post The exception description is set to sDescription.
         */
        void setEXCDescription(const std::string & sDescription) { sEXCDescription = sDescription; };

        /**
         * @brief Display the exception details.
         * @pre None.
         * @post Exception details are displayed on the console.
         */
        void display() const;
};

#include "ExceptionInline.h"

#endif //EXCEPTION_H
