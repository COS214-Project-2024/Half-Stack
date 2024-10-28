#include "Citizen.h"

Citizen::Citizen(std::string name, int age)
{
    this->name = name;
    this->age = age;
    this->employment = new Unemployed();
    this->satisfaction = new Neutral();
}

void Citizen::payTax(std::string tax)
{

}

void Citizen::startWork()
{
    if (this->employment->getStatus() == "Employed")
    {
        std::cout << this->name << " is starting work." << std::endl;   //Start job if has job
    }
    else
    {
        this->employment = this->employment->toggleStatus();            //Get the job to start work.
        std::cout << this->name << " now has the job and will start work." << std::endl;
    }
    
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
    if (this->employment->getStatus() == "Unemployed")
    {
        std::cout << this->name << " obtaind a job." << std::endl;
        this->employment = employment->toggleStatus();
    }
    else
    {
        std::cout << this->name << " already has a job. " << this->name << "cannot obtain a job if he has one already." << std::endl;
    }
}
