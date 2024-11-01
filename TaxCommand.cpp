#include "TaxCommand.h"

/**
 * @brief Retrieves the current status of the tax command.
 * 
 * @return An integer representing the current state of the tax command.
 */
int TaxCommand::getStatus()
{
    return state;
}

/**
 * @brief Executes the income tax collection command for the assigned citizen.
 * 
 * This function triggers the citizen's tax payment for income tax.
 */
void CollectIncomeTax::execute()
{
    citizen->payTax("incomeTax");
}

/**
 * @brief Executes the sales tax collection command for the assigned citizen.
 * 
 * This function triggers the citizen's tax payment for sales tax.
 */
void CollectSalesTax::execute()
{
    citizen->payTax("SalesTax");
}

/**
 * @brief Executes the property tax collection command for the assigned citizen.
 * 
 * This function triggers the citizen's tax payment for property tax.
 */
void CollectPropertyTax::execute()
{
    citizen->payTax("PropertyTax");
}
