#ifndef TAXCOMMAND_H
#define TAXCOMMAND_H

#include <iostream>
#include <string>

#include "Citizen.h"

class TaxCommand
{
    private:
        int state; ///< Current state of the command.

    public:
        /**
         * @brief Executes the tax command.
         *
         * Pure virtual function to be implemented by derived classes. 
         * Executes the tax collection logic for the specified tax type.
         */
        virtual void execute() = 0;

        /**
         * @brief Gets the current state of the command.
         * @return The integer representing the state of the command.
         */
        int getStatus();

        /**
         * @brief Virtual destructor for TaxCommand.
         *
         * Ensures proper cleanup of derived classes when a TaxCommand pointer is deleted.
         */
        virtual ~TaxCommand() {};
};

/**
 * @class CollectIncomeTax
 * @brief Concrete command class for collecting income tax.
 *
 * Implements the `execute()` method to handle the collection of income tax.
 */
class CollectIncomeTax : public TaxCommand
{
    public:
        /**
         * @brief Executes the income tax collection.
         *
         * Implements the tax collection logic for income tax.
         */
        void execute();
};

/**
 * @class CollectSalesTax
 * @brief Concrete command class for collecting sales tax.
 *
 * Implements the `execute()` method to handle the collection of sales tax.
 */
class CollectSalesTax : public TaxCommand
{
    public:
        /**
         * @brief Executes the sales tax collection.
         *
         * Implements the tax collection logic for sales tax.
         */
        void execute();
};

/**
 * @class CollectPropertyTax
 * @brief Concrete command class for collecting property tax.
 *
 * Implements the `execute()` method to handle the collection of property tax.
 */
class CollectPropertyTax : public TaxCommand
{
    public:
        /**
         * @brief Executes the property tax collection.
         *
         * Implements the tax collection logic for property tax.
         */
        void execute();
};

#endif
