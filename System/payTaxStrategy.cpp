#include "payTaxStrategy.h"
#include "Government.h"
#include "PublicServicesDepartment.h"
#include "ResourceManager.h"

/**
 * @brief Implements the payment of income tax.
 * 
 * Retrieves the Government singleton instance, then accesses the ResourceManager
 * and PublicServicesDepartment to increase the budget using the income tax amount.
 */
void payIncomeTax::pay()
{
    Government* gov = Government::instance("gov");
    ResourceManager* rm = gov->getResourceManager();
    PublicServicesDepartment* ps = gov->getPublicServicesDepartment();
    rm->increaseBudget(ps->getIncomeTax());
}

/**
 * @brief Implements the payment of sales tax.
 * 
 * Retrieves the Government singleton instance, then accesses the ResourceManager
 * and PublicServicesDepartment to increase the budget using the sales tax amount.
 */
void paySalesTax::pay()
{
    Government* gov = Government::instance("gov");
    ResourceManager* rm = gov->getResourceManager();
    PublicServicesDepartment* ps = gov->getPublicServicesDepartment();
    rm->increaseBudget(ps->getSalesTax());
}

/**
 * @brief Implements the payment of property tax.
 * 
 * Retrieves the Government singleton instance, then accesses the ResourceManager
 * and PublicServicesDepartment to increase the budget using the property tax amount.
 */
void payPropertyTax::pay()
{
    Government* gov = Government::instance("gov");
    ResourceManager* rm = gov->getResourceManager();
    PublicServicesDepartment* ps = gov->getPublicServicesDepartment();
    rm->increaseBudget(ps->getPropertyTax());
}
