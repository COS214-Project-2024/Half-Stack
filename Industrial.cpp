#include "Industrial.h"
#include <iostream>

/**
 * @brief Constructs an Industrial building with the specified parameters.
 * 
 * @param num The number associated with the building (e.g., ID).
 * @param l The location of the building.
 */
Industrial::Industrial(int num, std::string l) : Building(num, l)
{
	
}

/**
 * @brief Adds a Citizen to the Industrial building's workforce.
 * 
 * @param c Pointer to the Citizen to be added.
 */
void Industrial::addCitizen(Citizen* c)
{
	employees.push_back(c);
}

/**
 * @brief Removes a Citizen from the Industrial building's workforce.
 * 
 * Searches for the specified Citizen and removes them if found.
 * 
 * @param c Pointer to the Citizen to be removed.
 */
void Industrial::removeCitizen(Citizen* c)
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
 * @brief Consumes resources required for the operation of the Industrial building.
 * 
 * Decreases the resource levels and prints a message indicating whether 
 * resources are available or if more are needed.
 */
void Industrial::consumeResources()
{
    if (this->resourceManager->decreaseResourceLevels(40, 60, 20, 20, 20) == true)
    {
        std::cout << "Industrial building is consuming resources." << std::endl;
    }
    else
    {
        std::cout << "Need more Resources." << std::endl;

        //call upon other functions to produce more resources or buy more?
    }
}