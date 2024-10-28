#ifndef TAXCOMMAND_H
#define TAXCOMMAND_H

#include <iostream>
#include <string>

class TaxCommand
{
    private:
        int state;

    public:
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