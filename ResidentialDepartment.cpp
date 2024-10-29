#include "ResidentialDepartment.h"

ResidentialDepartment::ResidentialDepartment()
{
	
}

void ResidentialDepartment::addBuilding(Building* b)
{
    residents.push_back(b);
}

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

int ResidentialDepartment::getTotalBuildings()
{
    int counter = 0;
	for (std::vector<Building*>::iterator i = residents.begin(); i != residents.end(); i++)
    {
        counter++;
    }
    return counter;
}

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
