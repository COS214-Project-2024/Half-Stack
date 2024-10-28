#include "TaxCommand.h"

int TaxCommand::getStatus()
{
    return state;
}

void CollectIncomeTax::execute()
{
    PublicDepart->collectTax("incomeTax");
}

void CollectSalesTax::execute()
{
    PublicDepart->collectTax("SalesTax");
}

void CollectPropertyTax::execute()
{
    PublicDepart->collectTax("PropertyTax");
}