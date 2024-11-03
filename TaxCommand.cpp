#include "TaxCommand.h"
#include "Government.h"

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
    Government* gov = Government::instance(" ");
    std::vector<Citizen*> citizens = gov->getCitizens();
    std::vector<Citizen*>::iterator it = citizens.begin();
    for(; it != citizens.end(); ++it)
    {
        if((*it)!=NULL)
        {
            (*it)->payTax("IncomeTax");
        }
    }
}

/**
 * @brief Executes the sales tax collection command for the assigned citizen.
 * 
 * This function triggers the citizen's tax payment for sales tax.
 */
void CollectSalesTax::execute()
{
    Government* gov = Government::instance(" ");
    std::vector<Citizen*> citizens = gov->getCitizens();
    std::vector<Citizen*>::iterator it = citizens.begin();
    for(; it != citizens.end(); ++it)
    {
        if((*it)!=NULL)
        {
            (*it)->payTax("SalesTax");
        }
    }
}

/**
 * @brief Executes the property tax collection command for the assigned citizen.
 * 
 * This function triggers the citizen's tax payment for property tax.
 */
void CollectPropertyTax::execute()
{
    Government* gov = Government::instance(" ");
    std::vector<Citizen*> citizens = gov->getCitizens();
    std::vector<Citizen*>::iterator it = citizens.begin();
    for(; it != citizens.end(); ++it)
    {
        if((*it)!=NULL)
        {
            (*it)->payTax("PropertyTax");
        }
    }
}
