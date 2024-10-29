#include "Department.h"
#include <iostream>

void Department::addBuilding(Building* b) 
{
	this->buildings.push_back(b);
}

void Department::removeBuilding(Building* b) 
{
	std::vector<Building*>::iterator it = this->buildings.begin();
	for( ; it != this->buildings.end(); ++it)
	{
		if(*it == b)
		{
			this->buildings.erase(it);
		}
	}
}

void Department::update()
{
	std::cout << "Department is updating its buildings." << std::endl;

    for (Building* building : buildings) 
	{
        if (building) 
		{
            building->consumeResources(); 
        }
    }
}