#include "Residential.h"
#include <iostream>

Residential::Residential(int num, std::string l) : Building(num, l)
{
	
}

void Residential::addCitizen(Citizen* c)
{
	residents.push_back(c);
}

void Residential::removeCitizen(Citizen* c)
{
	for (std::vector<Citizen*>::iterator i = residents.begin(); i != residents.end(); i++)
    {
        if (*i == c)
        {
            i = residents.erase(i);
            return;
        }
    }
}

void Residential::consumeResources()
{
    if (this->resourceManager->decreaseResourceLevels(15, 20, 0, 0, 10) == true)
    {
        std::cout << "Residential building is consuming resources." << std::endl;
    }
    else
    {
        std::cout << "Need more Resources." << std::endl;

        //call upon other functions to produce more resources or buy more?
    }
}

Estate::Estate(int num,  std::string l) : Residential(num, l)
{
	
}

void Estate::addBuilding(Residential* b)
{
	buildings.push_back(b);
}

void Estate::removeBuilding(Residential* b)
{
	for (std::vector<Residential*>::iterator i = buildings.begin(); i != buildings.end(); i++)
    {
        if (*i == b)
        {
            i = buildings.erase(i);
            return;
        }
    }
}

Building* Estate::build()
{
    if (this->resourceManager->decreaseResourceLevels(40, 100, 150, 200, 250) == true)
	{
		return new Estate(capacity, location);
	}
	else
	{
		return nullptr;
	}
}