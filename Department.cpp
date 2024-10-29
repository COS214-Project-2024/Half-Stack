#include "Department.h"

Department::Department()
{
	
}

void Department::addBuilding(Building* b) 
{
	buildings.push_back(b);
}

void Department::removeBuilding(Building* b) 
{
	for (std::vector<Building*>::iterator i = buildings.begin(); i != buildings.end(); i++)
    {
        if (*i == b)
        {
            i = buildings.erase(i);
            return;
        }
    }
}