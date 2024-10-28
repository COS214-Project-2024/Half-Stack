#include "Citizen.h"

Citizen::Citizen(std::string name, int age)
{
    this->name = name;
    this->age = age;
}

void Citizen::payTax(std::string tax)
{

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