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
