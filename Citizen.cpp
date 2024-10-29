#include "Citizen.h"

Citizen::Citizen(std::string name, int age)
{
    this->name = name;
    this->age = age;
}

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