#ifndef PAY_TAX_STRATEGY_H
#define PAY_TAX_STRATEGY_H

class payTaxStrategy
{
    public:
        virtual void pay()=0;
        virtual ~payTaxStrategy() {};
};

class payIncomeTax: public payTaxStrategy
{
    public:
        void pay();
};

class payPropertyTax: public payTaxStrategy
{
    public:
        void pay();
};

class paySalesTax: public payTaxStrategy
{
    public:
        void pay();
};

#endif