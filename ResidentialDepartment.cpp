#include "ResidentialDepartment.h"
#include "Government.h"
#include "ResourceManager.h"

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
bool ResidentialDepartment::addBuilding(Residential* b)
{
    int num = b->getCapacity();
    ResourceManager* rm = ResourceManager::instance();
    if (rm->decreaseResourceLevels(10, 10, 50*num, 50*num, 25*num) == true)
	{
        if (rm->decreaseBudget(50*num)==true)
        {
            residents.push_back(b);
            notifyNewHousing();
            std::cout << "Residential building successfully built." <<std::endl;
            return true;
        }else {
            rm->increaseResourceLevels(10, 10, 50*num, 50*num, 25*num);
            delete b;
        }
	}else{
        delete b;
    }
    return false;
}

/**
 * @brief Removes a building from the vector of residential buildings.
 * @param b Pointer to the building.
 */
void ResidentialDepartment::removeBuilding(Residential* b)
{
	for (std::vector<Residential*>::iterator i = residents.begin(); i != residents.end(); i++)
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
	for (std::vector<Residential*>::iterator i = residents.begin(); i != residents.end(); i++)
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
	for (std::vector<Residential*>::iterator i = residents.begin(); i != residents.end(); i++)
    {
        total = total + (*i)->capacity;
    }
    return total;
}

/**
 * @brief Attaches a Citizen to the list of observers for notifications.
 * @param c Pointer to the Citizen to be attached.
 */
void ResidentialDepartment::attachCitizen(Citizen* c) 
{
    Observingcitizens.push_back(c);
}

/**
 * @brief Detaches a Citizen from the list of observers for notifications.
 * @param c Pointer to the Citizen to be detached.
 */
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

/**
 * @brief Sets the load-shedding status and notifies citizens if there is a change.
 * @param status Boolean indicating if load-shedding is active.
 * @param startTime Start time of load-shedding, if active.
 * @param endTime End time of load-shedding, if active.
 */
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

/**
 * @brief Sends a notification message to all observing citizens.
 * @param message The notification message to be sent.
 */
void ResidentialDepartment::notifyCitizens(const std::string& message) 
{
    for (auto* citizen : Observingcitizens) 
    {
        citizen->receiveNotification(message);    
    }
}

/**
 * @brief goes through the government's citizens vector and the buildings vector to find citizens without homes
 * and assigns them a home if the building is not at max capacity if a new building was added
 */
void ResidentialDepartment::notifyNewHousing()
{
    std::vector<Citizen*> citizens = Government::instance(" ")->getCitizens();
    std::vector<Citizen*>::iterator it = citizens.begin();
    for (std::vector<Residential*>::iterator i = residents.begin(); i != residents.end(); i++)
    {

        if ((*i)->isFull()==false)
        {
            for(; it != citizens.end(); ++it)
            {
                if((*it)->getHome()==NULL && (*i)->isFull()==false)
                {
                    (*it)->moveIn(*i);
                    (*i)->addCitizen(*it);
                    attachCitizen(*it);
                }
            }
        }
    }
}

/**
 * @brief goes through the government's citizens vector and the buildings vector to find citizens without homes
 * and assigns them a home if the building is not at max capacity if a new citizen was added
 */
void ResidentialDepartment::houseNewCitizens()
{
    std::vector<Citizen*> citizens = Government::instance(" ")->getCitizens();
    std::vector<Citizen*>::iterator it = citizens.begin();
    for (std::vector<Residential*>::iterator i = residents.begin(); i != residents.end(); i++)
    {

        if ((*i)->isFull()==false)
        {
            for(; it != citizens.end(); ++it)
            {
                if((*it)->getHome()==NULL && (*i)->isFull()==false)
                {
                    (*it)->moveIn(*i);
                    (*i)->addCitizen(*it);
                    attachCitizen(*it);
                }
            }
        }
    }
}


/**
 * @brief goes through the buildings vector and determines the amount of available rooms for new citizens
 * @return Number of rooms not used.
 */
int ResidentialDepartment::emptyRooms()
{
    int counter=0;
    for (std::vector<Residential*>::iterator i = residents.begin(); i != residents.end(); i++)
            {
                if ((*i)->isFull()==false)
                {
                    int empty = (*i)->getCapacity()-(*i)->getNumResidents();
                    counter += empty;
                }
            }
    return counter;
}

/**
 * @brief destructor
 */
ResidentialDepartment::~ResidentialDepartment()
{
     for (std::vector<Residential*>::iterator i = residents.begin(); i != residents.end(); i++)
    {
        if ((*i)!=NULL)
        {
            delete *i;    
        }
    }
}

/**
 * @brief goes through the buildings vector and calls the consumeResources function on each
 */
void ResidentialDepartment::consumeDailyResources()
{
    bool consumed = true;

    for (std::vector<Residential*>::iterator i = residents.begin(); i != residents.end(); i++)
    {
        if ((*i)->consumeResources()==false)
        {
            consumed=false;
        }
    }
    if (consumed==false)
    {
        notifyCitizens("No power and water");
        std::cout << "Some residential buildings have no water and power. Please replenish power and water." <<std::endl;
    }
}

