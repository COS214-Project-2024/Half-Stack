#include "Residential.h"
#include "ResourceManager.h"
#include <iostream>

/**
 * @brief Constructs a Residential object with a specified number and location.
 * 
 * @param num The capacity or number of residents that the residential building can hold.
 * @param loc The location of the residential building.
 */
Residential::Residential(int num, std::string l) : Building(num, l)
{
	water=15;
    energy=20;
    mats=10;
}

/**
 * @brief Adds a citizen to the list of residents.
 * 
 * @param c Pointer to the citizen to be added.
 */
void Residential::addCitizen(Citizen* c)
{
    if (getNumResidents() != getCapacity())
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
 * @brief Consumes resources required for the Residential building based on the number of employees.
 * 
 * This function attempts to decrease the resource levels in the ResourceManager instance based on the 
 * number of employees in the building. If the resources are successfully decreased, it iterates over 
 * the list of employees and updates their resource status and satisfaction levels if they lack resources.
 * 
 * @return true if resources were successfully consumed; false if resources are insufficient.
 * 
 * The function decreases water and energy resources based on a factor of 10 per employee. 
 * If resources are available, it sets the `NoResources` flag to true for each employee lacking resources 
 * and raises their satisfaction status.
 * 
 * If the resources are insufficient, the function returns false, and alternative methods to acquire resources 
 * (such as production or purchasing) could be implemented as additional logic.
 */
bool Residential::consumeResources()
{
    ResourceManager* rm = ResourceManager::instance();
    if (rm->decreaseResourceLevels(water*getNumResidents(), energy*getNumResidents(), 0, 0,0) == true)
    {
        for (std::vector<Citizen*>::iterator i = residents.begin(); i != residents.end(); i++)
        {
            if ((*i)->getNoResources()==true)
            {
                (*i)->setNoResources(true);
                (*i)->getSatisfaction()->raiseStatus();
            }
        }
        //std::cout << "Residential building is consuming resources." << std::endl;
        return true;
    }
    else
    {
        //std::cout << "Need more Resources." << std::endl;
        return false;

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
 * @brief Gets the number of residents in a building.
 * 
 * @return number of residents in building
 */
int Residential::getNumResidents()
{
    int count=0;
    for (std::vector<Citizen*>::iterator i = residents.begin(); i != residents.end(); i++)
    {
        count++;
    }
    return count;
}

/**
 * @brief determines if the building is at max capacity with regards to the amount of residents
 * 
 * @return if builing can house more citizens or not
 */
bool Residential::isFull()
{
    if (getCapacity()==getNumResidents())
    {
        return true;
    }

    return false;
}

/**
 * @brief increaese water if amenity is added
 */
void Residential::increaseWaterConsumption(int num)
{
    water += num;
}
/**
 * @brief increaese power if amenity is added
 */
void Residential::increasePowerConsumption(int num)
{
    energy +=num;
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
    ResourceManager* rm = ResourceManager::instance();
    if (rm->decreaseResourceLevels(40, 100, 150, 200, 250) == true)
	{
		return new Estate(capacity, location);
	}
	else
	{
		return nullptr;
	}
}

/**
* @brief destructor for estate
*/
Estate::~Estate()
{
    for (std::vector<Residential*>::iterator i = buildings.begin(); i != buildings.end(); i++)
    {
        if (*i !=NULL)
        {
            delete (*i);
            (*i)=NULL;
        }
    }
}
