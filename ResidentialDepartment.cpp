#include "ResidentialDepartment.h"

ResidentialDepartment* ResidentialDepartment::uniqueInstance;

/**
 * @brief Constructor for the ResidentialDepartment class.
 */
ResidentialDepartment::ResidentialDepartment()
{
	
}

/** 
 * @brief Singleton instance of ResidentialDepartment.
 * @return Pointer to the instance of ResidentialDepartment.
 */
ResidentialDepartment* ResidentialDepartment::instance()
{
	if (uniqueInstance == NULL)
    {
        uniqueInstance = new ResidentialDepartment();
    }
    return uniqueInstance;
}

/**
 * @brief Adds a building to the vector of residential buildings.
 * @param b Pointer to the building.
 */
void ResidentialDepartment::addBuilding(Building* b)
{
    residents.push_back(b);
}

/**
 * @brief Removes a building from the vector of residential buildings.
 * @param b Pointer to the building.
 */
void ResidentialDepartment::removeBuilding(Building* b)
{
	for (std::vector<Building*>::iterator i = residents.begin(); i != residents.end(); i++)
    {
        if (*i == b)
        {
            i = residents.erase(i);
            return;
        }
    }	
}

/**
 * @brief Calculates the number of residential buildings.
 * @return Number of residential buildings.
 */
int ResidentialDepartment::getTotalBuildings()
{
    int counter = 0;
	for (std::vector<Building*>::iterator i = residents.begin(); i != residents.end(); i++)
    {
        counter++;
    }
    return counter;
}

/**
 * @brief Calculates the number of possible citizens in the residential buildings.
 * @return Number of possible citizens.
 */
int ResidentialDepartment::getTotalCapacity()
{
    int total = 0;
	for (std::vector<Building*>::iterator i = residents.begin(); i != residents.end(); i++)
    {
        total = total + (*i)->capacity;
    }
    return total;
}

void ResidentialDepartment::attachCitizen(Citizen* c) 
{
    Observingcitizens.push_back(c);
}
void ResidentialDepartment::detachCitizen(Citizen* c)
{
    for (auto it = Observingcitizens.begin(); it != Observingcitizens.end(); ++it) 
	{
        if (*it == c) 
		{
            Observingcitizens.erase(it);
            return;
        }
    }
}
void ResidentialDepartment::setLoadShedding(bool status, const std::string& startTime, const std::string& endTime) 
{
    if (isLoadShedding != status) 
    {
        isLoadShedding = status;
        std::string message;
        if (status) 
        {
            message = "Load-shedding started from " + startTime + " to " + endTime + ".";
        } 
        else 
        {
            message = "Load-shedding has ended.";
        }
        notifyCitizens(message);
    } 
    else 
    {
      
        std::cout << "Load-shedding status is already set to " 
                  << (status ? "ON" : "OFF") 
                  << ". No change made." << std::endl;
    }
}
void ResidentialDepartment::notifyCitizens(const std::string& message) 
{
    for (auto* citizen : Observingcitizens) 
	{
        citizen->receiveNotification(message);	
    }
}