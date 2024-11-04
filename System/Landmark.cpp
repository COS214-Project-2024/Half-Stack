#include "Landmark.h"
#include "ResourceManager.h"
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
bool Landmark::consumeResources()
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
        //std::cout << "Landmark building is consuming resources." << std::endl;
    }
    else
    {
        return false;
        //std::cout << "Need more Resources." << std::endl;

        //call upon other functions to produce more resources or buy more?
    }
}

/**
 * @brief determines amount of employees in building
 * @return the amount of employees in the building
 */
int Landmark::getNumEmployees()
{
    int count=0;
    for (std::vector<Citizen*>::iterator i = employees.begin(); i != employees.end(); i++)
    {
        count++;
    }
    return count;
}

 /**
 * @brief determines if building is at full capacity
 * 
 * @return true if no more citizens can be added, false if more citizens can be added
 */
bool Landmark::isFull()
{
    if (getCapacity()==getNumEmployees())
    {
        return true;
    }

    return false;
}
