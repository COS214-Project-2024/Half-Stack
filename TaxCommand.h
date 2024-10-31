#ifndef TAXCOMMAND_H
#define TAXCOMMAND_H

#include <iostream>
#include <string>

#include "Citizen.h"

class TaxCommand
{
    private:
        int state;

    public:
        Citizen* citizen;
        virtual void execute() = 0;
        int getStatus();
};

class CollectIncomeTax : public TaxCommand
{
    public:
        void execute();
};

class CollectSalesTax : public TaxCommand
{
    public:
        void execute();
};

class CollectPropertyTax : public TaxCommand
{
    public:
        void execute();
};

#endif