#include "Landmark.h"
#include <iostream>

Landmark::Landmark(int num,  std::string l) : Building(num, l)
{
	
}

void Landmark::addCitizen(Citizen* c)
{
	employees.push_back(c);
}

void Landmark::removeCitizen(Citizen* c)
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

void Landmark::consumeResources()
{
    if (this->resourceManager->decreaseResourceLevels(5, 15, 0, 0, 0) == true)
    {
        std::cout << "Landmark building is consuming resources." << std::endl;
    }
    else
    {
        std::cout << "Need more Resources." << std::endl;

        //call upon other functions to produce more resources or buy more?
    }
}