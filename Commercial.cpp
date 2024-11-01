#include "Commercial.h"
#include <iostream>

/**
 * @brief Constructs a new Commercial object.
 * 
 * Initializes a Commercial building with the specified capacity and location.
 * 
 * @param num The initial capacity of the Commercial building.
 * @param l The location of the Commercial building.
 */
Commercial::Commercial(int num, std::string l) : Building(num, l)
{
	
}

/**
 * @brief Adds a Citizen to the employees of the Commercial building.
 * 
 * @param c Pointer to the Citizen to be added.
 */
void Commercial::addCitizen(Citizen* c)
{
	employees.push_back(c);
}

/**
 * @brief Removes a Citizen from the employees of the Commercial building.
 * 
 * Searches for the specified Citizen and removes them from the employee list.
 * 
 * @param c Pointer to the Citizen to be removed.
 */
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

/**
 * @brief Consumes resources required for the operation of the Commercial building.
 * 
 * If sufficient resources are available, the building will consume them;
 * otherwise, a message will indicate that more resources are needed.
 */
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