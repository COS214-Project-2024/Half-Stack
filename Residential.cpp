#include "Residential.h"
#include <iostream>

/**
 * @brief Constructs a Residential object with a specified number and location.
 * 
 * @param num The capacity or number of residents that the residential building can hold.
 * @param loc The location of the residential building.
 */
Residential::Residential(int num, std::string l) : Building(num, l)
{
	
}

/**
 * @brief Adds a citizen to the list of residents.
 * 
 * @param c Pointer to the citizen to be added.
 */
void Residential::addCitizen(Citizen* c)
{
	residents.push_back(c);
}

/**
 * @brief Removes a citizen from the list of residents.
 * 
 * @param c Pointer to the citizen to be removed.
 */
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

/**
 * @brief Consumes resources necessary for the residential building's operation.
 */
void Residential::consumeResources()
{
    if (this->resourceManager->decreaseResourceLevels(15, 20, 0, 0, 10) == true)
    {
        std::cout << "Residential building is consuming resources." << std::endl;
    }
    else
    {
        std::cout << "Need more Resources." << std::endl;

        //call upon other functions to produce more resources or buy more?
    }
}

/**
 * @brief Gets the residents of a building.
 * 
 * @return Pointer to a vector of citizens.
 */
std::vector<Citizen*> Residential::getResidents()
{
    return residents;
}

/**
 * @brief Destroys the Residential object and releases resources.
 */
Residential::~Residential()
{
    for (Citizen* c : residents)
    {
        delete c;
    }
}

/**
 * @brief Constructs an Estate object with a specified number and location.
 * 
 * @param num The capacity or number of residents that the estate can hold.
 * @param loc The location of the estate.
 */
Estate::Estate(int num,  std::string l) : Residential(num, l)
{
	
}

/**
 * @brief Adds a residential building to the estate.
 * 
 * @param b Pointer to the residential building to be added.
 */
void Estate::addBuilding(Residential* b)
{
	buildings.push_back(b);
}

/**
 * @brief Removes a residential building from the estate.
 * 
 * @param b Pointer to the residential building to be removed.
 */
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

/**
 * @brief Builds a new Estate if resources are sufficient.
 * 
 * @return Building* Pointer to the newly created Estate if successful, or nullptr if resources are insufficient.
 */
Building* Estate::build()
{
    if (this->resourceManager->decreaseResourceLevels(40, 100, 150, 200, 250) == true)
	{
		return new Estate(capacity, location);
	}
	else
	{
		return nullptr;
	}
}

/**
 * @brief Destroys the Estate object and releases resources.
 */
Estate::~Estate()
{
    for (Residential* b : buildings)
    {
        delete b;
    }
}
