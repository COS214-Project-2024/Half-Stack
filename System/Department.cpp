#include "Department.h"

/**
 * @brief Constructor for the Department class.
 */
Department::Department()
{
	
}

/**
 * @brief Adds a building to the vector of department buildings.
 * @param b Pointer to the building.
 */
void Department::addBuilding(Building* b) 
{
	buildings.push_back(b);
}

/**
 * @brief Removes a building from the vector of department buildings.
 * @param b Pointer to the building.
 */
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

/**
 * @brief Updates the Department's buildings.
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