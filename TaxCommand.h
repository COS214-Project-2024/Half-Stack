#ifndef TAXCOMMAND_H
#define TAXCOMMAND_H

#include <iostream>
#include <string>

#include "Citizen.h"

/**
 * @brief Abstract base class representing a tax command.
 */
class TaxCommand
{
    private:
        int state; 

    public:
        Citizen* citizen;

        /**
         * @brief Executes the tax command.
         * 
         * This is a pure virtual function that must be overridden by derived classes.
         */
        virtual void execute() = 0;

        /**
         * @brief Gets the current status of the tax command.
         * 
         * @return int The status of the command.
         */
        int getStatus();
};

/**
 * @brief Command for collecting income tax.
 */
class CollectIncomeTax : public TaxCommand
{
    public:
        /**
         * @brief Executes the income tax collection command.
         * 
         * This method implements the logic for collecting income tax from the citizen.
         */
        void execute();
};

/**
 * @brief Command for collecting sales tax.
 */
class CollectSalesTax : public TaxCommand
{
    public:
        /**
         * @brief Executes the sales tax collection command.
         * 
         * This method implements the logic for collecting sales tax from the citizen.
         */
        void execute();
};

/**
 * @brief Command for collecting property tax.
 */
class CollectPropertyTax : public TaxCommand
{
    public:
        /**
         * @brief Executes the property tax collection command.
         * 
         * This method implements the logic for collecting property tax from the citizen.
         */
        void execute();
};

#endif
