#include "TaxCommand.h"

int TaxCommand::getStatus()
{
    return state;
}

void CollectIncomeTax::execute()
{
    citizen->payTax("incomeTax");
}

void CollectSalesTax::execute()
{
    citizen->payTax("SalesTax");
}

void CollectPropertyTax::execute()
{
    citizen->payTax("PropertyTax");
}