#include "Industrial.h"
#include <iostream>

Industrial::Industrial(int num, std::string l) : Building(num, l)
{
	
}

void Industrial::addCitizen(Citizen* c)
{
	employees.push_back(c);
}

void Industrial::removeCitizen(Citizen* c)
{
	for (std::vector<Citizen*>::iterator i = employees.begin(); i != employees.end(); i++)
    {
        if (*i == c)
        {
            i = employees.erase(i);
            return;
        }
    }
}

void Industrial::consumeResources()
{
    if (this->resourceManager->decreaseResourceLevels(40, 60, 20, 20, 20) == true)
    {
        std::cout << "Industrial building is consuming resources." << std::endl;
    }
    else
    {
        std::cout << "Need more Resources." << std::endl;

        //call upon other functions to produce more resources or buy more?
    }
}