#include "ResidentialDepartment.h"

ResidentialDepartment::ResidentialDepartment()
{
	
}

void ResidentialDepartment::addBuilding(Building* b)
{
    residents.push_back(b);
}

void ResidentialDepartment::removeBuilding(Building* b)
{
	for (std::vector<Building*>::iterator i = residents.begin(); i != residents.end(); i++)
    {
        if (*i == b)
        {
            i = residents.erase(i);
            return;
        }
    }	
}

int ResidentialDepartment::getTotalBuildings()
{
    int counter = 0;
	for (std::vector<Building*>::iterator i = residents.begin(); i != residents.end(); i++)
    {
        counter++;
    }
    return counter;
}

int ResidentialDepartment::getTotalCapacity()
{
    int total = 0;
	for (std::vector<Building*>::iterator i = residents.begin(); i != residents.end(); i++)
    {
        total = total + (*i)->capacity;
    }
    return total;
}
