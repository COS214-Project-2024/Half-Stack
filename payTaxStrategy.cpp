#include "payTaxStrategy.h"
#include "Government.h"
#include "PublicServicesDepartment.h"
#include "ResourceManager.h"

void payIncomeTax::pay()
{
    Government* gov = Government::instance("gov");
    //Government* gov;

    ResourceManager* rm = gov->getResourceManager();
    PublicServicesDepartment* ps = gov->getPublicServicesDepartment();
    rm->increaseBudget(ps->getIncomeTax());
}

void paySalesTax::pay()
{
    Government* gov = Government::instance("gov");
    //Government* gov;
    ResourceManager* rm = gov->getResourceManager();
    PublicServicesDepartment* ps = gov->getPublicServicesDepartment();
    rm->increaseBudget(ps->getSalesTax());
}

void payPropertyTax::pay()
{
    Government* gov = Government::instance("gov");
    //Government* gov;
    ResourceManager* rm = gov->getResourceManager();
    PublicServicesDepartment* ps = gov->getPublicServicesDepartment();
    rm->increaseBudget(ps->getPropertyTax());
}
