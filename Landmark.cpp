#include "Landmark.h"
#include <iostream>

/**
 * @brief Constructs a Landmark building with the specified parameters.
 * 
 * @param num The number associated with the building (e.g., ID).
 * @param l The location of the building.
 */
Landmark::Landmark(int num,  std::string l) : Building(num, l)
{
	
}

/**
 * @brief Adds a Citizen to the Landmark building's workforce.
 * 
 * @param c Pointer to the Citizen to be added.
 */
void Landmark::addCitizen(Citizen* c)
{
	employees.push_back(c);
}

/**
 * @brief Removes a Citizen from the Landmark building's workforce.
 * 
 * Searches for the specified Citizen and removes them if found.
 * 
 * @param c Pointer to the Citizen to be removed.
 */
void Landmark::removeCitizen(Citizen* c)
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
 * @brief Consumes resources required for the operation of the Landmark building.
 * 
 * Decreases the resource levels and prints a message indicating whether 
 * resources are available or if more are needed.
 */
void Landmark::consumeResources()
{
    if (this->resourceManager->decreaseResourceLevels(5, 15, 0, 0, 0) == true)
    {
        std::cout << "Landmark building is consuming resources." << std::endl;
    }
    else
    {
        std::cout << "Need more Resources." << std::endl;

        //call upon other functions to produce more resources or buy more?
    }
}