#include "Citizen.h"

Citizen::Citizen(std::string name, int age)
{
    this->name = name;
    this->age = age;
}

/**
 * @brief Processes tax payment for the citizen based on the specified tax type.
 * 
 * This function outputs a message indicating which type of tax was paid by the citizen.
 * If an unrecognized tax type is provided, it outputs "invalid input."
 * 
 * @param tax A string representing the type of tax. Expected values are:
 *            - "incomeTax" for income tax
 *            - "SalesTax" for sales tax
 *            - "PropertyTax" for property tax
 * 
 * - Outputs a message in the format:
 *   - "<name> payed income tax." if `tax` is "incomeTax"
 *   - "<name> payed sales tax." if `tax` is "SalesTax"
 *   - "<name> payed property tax." if `tax` is "PropertyTax"
 *   - "invalid input." for any other value
 */
void Citizen::payTax(std::string tax)
{
    if(tax=="incomeTax")
    {
         std::cout << this->name << "payed income tax." << std::endl;
    }
    else if(tax=="SalesTax")
    {
        std::cout << this->name << "payed sales tax." << std::endl;
    }
    else if(tax=="PropertyTax")
    {
        std::cout << this->name << "payed property tax." << std::endl;
    }
    else
    {
        std::cout << "invalid input." << std::endl;
    }
}

void Citizen::startWork()
{

}

void Citizen::goHome()
{

}

Employment* Citizen::getEmployment()
{
    return this->employment;
}

void Citizen::setEmployment(Employment* e)
{
    this->employment = e;
}

Satisfaction* Citizen::getSatisfaction()
{
    return this->satisfaction;
}

void Citizen::setSatisfaction(Satisfaction* s)
{
    this->satisfaction = s;
}

void Citizen::getJob()
{
    
}