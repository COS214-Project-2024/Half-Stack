#include "Residential.h"

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
	std::cout << "Residential building is consuming resources." << std::endl;
}

std::vector<Citizen *> Residential::getResidents()
{
    return residents;
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
	return new Estate(capacity, location);
}

void Estate::increaseSatisfaction()
{
    std::cout << "Estate has neutral satisfaction for residents." << std::endl;
}

void Estate::consumeResources()
{
    std::cout << "Estate consumes basic resources." << std::endl;
}
