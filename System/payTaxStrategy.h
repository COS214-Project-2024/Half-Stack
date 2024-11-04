#ifndef PAY_TAX_STRATEGY_H
#define PAY_TAX_STRATEGY_H

/**
 * @class payTaxStrategy
 * @brief Abstract base class for tax payment strategies.
 * 
 * This class defines a strategy interface for paying different types of taxes.
 */
class payTaxStrategy
{
public:
    /**
     * @brief Pure virtual function for paying tax.
     * 
     * This function must be implemented by derived classes to define specific tax payment behavior.
     */
    virtual void pay() = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~payTaxStrategy() {};
};

/**
 * @class payIncomeTax
 * @brief Concrete strategy class for paying income tax.
 * 
 * Implements the tax payment behavior for income tax.
 */
class payIncomeTax : public payTaxStrategy
{
public:
    /**
     * @brief Implements the payment of income tax.
     * 
     * Increases the budget of the Public Services Department by the income tax amount.
     */
    void pay();
};

/**
 * @class payPropertyTax
 * @brief Concrete strategy class for paying property tax.
 * 
 * Implements the tax payment behavior for property tax.
 */
class payPropertyTax : public payTaxStrategy
{
public:
    /**
     * @brief Implements the payment of property tax.
     * 
     * Increases the budget of the Public Services Department by the property tax amount.
     */
    void pay();
};

/**
 * @class paySalesTax
 * @brief Concrete strategy class for paying sales tax.
 * 
 * Implements the tax payment behavior for sales tax.
 */
class paySalesTax : public payTaxStrategy
{
public:
    /**
     * @brief Implements the payment of sales tax.
     * 
     * Increases the budget of the Public Services Department by the sales tax amount.
     */
    void pay();
};

#endif
