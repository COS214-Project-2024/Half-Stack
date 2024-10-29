#include "Commercial.h"
#include <iostream>

Commercial::Commercial(int num, std::string l) : Building(num, l)
{
	
}

void Commercial::addCitizen(Citizen* c)
{
	employees.push_back(c);
}

void Commercial::removeCitizen(Citizen* c)
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

void Commercial::consumeResources()
{
    if (this->resourceManager->decreaseResourceLevels(30, 50, 0, 0, 0) == true)
    {
        std::cout << "Commercial building is consuming resources." << std::endl;
    }
    else
    {
        std::cout << "Need more Resources." << std::endl;

        //call upon other functions to produce more resources or buy more?
    }
}