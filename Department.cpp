#include "Department.h"
#include <iostream>

/**
 * @brief Adds a Building to the Department's collection.
 * 
 * @param b Pointer to the Building to be added.
 */
void Department::addBuilding(Building* b) 
{
	this->buildings.push_back(b);
}

/**
 * @brief Removes a Building from the Department's collection.
 * 
 * Searches for the specified Building and removes it if found.
 * 
 * @param b Pointer to the Building to be removed.
 */
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

/**
 * @brief Updates the Department's buildings.
 * 
 * Prints a message indicating the update process and calls the consumeResources()
 * method for each building in the collection.
 */
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