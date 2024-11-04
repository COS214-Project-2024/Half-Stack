#include "Commercial.h"
#include "ResourceManager.h"
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
 * @brief Consumes resources required for the Commercial building based on the number of employees.
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
bool Commercial::consumeResources()
{
    ResourceManager* rm = ResourceManager::instance();
    int num = getNumEmployees();
    if (rm->decreaseResourceLevels(10*num, 10*num, 0, 0, 0) == true)
    {
        for (std::vector<Citizen*>::iterator i = employees.begin(); i != employees.end(); i++)
        {
            if ((*i)->getNoResources()==true)
            {
                (*i)->setNoResources(true);
                (*i)->setSatisfaction((*i)->getSatisfaction()->raiseStatus());
            }
        }
        return true;
        //std::cout << "Commercial building is consuming resources." << std::endl;
    }
    else
    {
        return false;
        //std::cout << "Need more Resources." << std::endl;

        //call upon other functions to produce more resources or buy more?
    }
}

int Commercial::getNumEmployees()
{
    int count=0;
    for (std::vector<Citizen*>::iterator i = employees.begin(); i != employees.end(); i++)
    {
        count++;
    }
    return count;
}

bool Commercial::isFull()
{
    if (getCapacity()==getNumEmployees())
    {
        return true;
    }

    return false;
}

Commercial::~Commercial()
 {
    for (std::vector<Citizen*>::iterator i = employees.begin(); i != employees.end(); i++)
    {
        if ((*i)!=NULL)
        {
            delete (*i);
        }
    }
 }
