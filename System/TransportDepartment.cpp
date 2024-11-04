#include <iostream>
#include "TransportDepartment.h"

TransportDepartment* TransportDepartment::uniqueInstance;

/**
 * @brief Cleans up any dynamically allocated memory. Cleans up the allocated commands per the transport businesses. Deletes the unique instance, effectively cleaning up the memeory
 */ 
TransportDepartment::~TransportDepartment()
{
	std::vector<std::pair<Transportation*, std::pair<TransportCommand*, TransportCommand*>>>::iterator it = this->transports.begin();

	for(; it != this->transports.end(); ++it)
	{
		delete it->second.first;
		delete it->second.second;
	}

	delete uniqueInstance;
}

/**
 * @brief Default constructor. Only needed for instance creation
 */
TransportDepartment::TransportDepartment()
{

};

/** 
* @brief Sets the Transport department singleton instance to ensure that only one instance is created
* @return Returns the instance. Now we can use the Transport Department functionality through this instance
*/
TransportDepartment* TransportDepartment::instance()
{
    if(uniqueInstance == nullptr)
	{
		uniqueInstance = new TransportDepartment();
	}

	return uniqueInstance;
}


/**
 * @brief Adds a new transport business to the vector of transports, if it meets resource and budget requirements
 * 
 * This checks if the transport facility does not already exists in the system and if the necessary resource and budget are availible based on the type of transport(Airport, Road, Railway). It handles the resource deductions, budget checks(to see if it is feasible), and rollbacks if the transport cannot be added. If successful, the commands for openTransport and closeTransport are assigned. After all checks have passed, add the transport to the list.
 * 
 * @param newTransport Pointer to a Transportation object which represents the transport to be added.
 * 
 * 	-If the `newTransport` is an Airport:
 *		-Checks we're not exceeding the maximum number of airports allowed for this city. 
		-Attempts to deduct the needed resources and budget specs needed for adding a transport. Rolls back if the addition was unsuccessful.
 *	-If the `newTransport` is an Road or a Railway:
		-Attempts to deduct the needed resources and budget specs needed for adding a transport. Rolls back if the addition was unsuccessful.

 *If we had a successful addition, `newTransport` is paired with open and close business commands and is now stored in the list

 @note If we have any fails, `newTransport` is deleted to prevent memeory leaks.
*/
void TransportDepartment::addTransport(Transportation* newTransport)
{
	if (newTransport->getType()=="Airport")
		{
			if (getTotalAirports()>7)
			{
				std::cout << "Cannot add more airports to city" << std::endl;
				return;
			}
		}
	std::vector<std::pair<Transportation*, std::pair<TransportCommand*, TransportCommand*>>>::iterator it = this->transports.begin();
	for(; it != this->transports.end(); ++it)
	{
		if(it->first == newTransport)
		{
			std::cout << "Transport already exists" << std::endl;
			return;
		}
	}

	if (newTransport->getType()=="Airport")
	{
			ResourceManager* rm =ResourceManager::instance();
			if (rm->decreaseResourceLevels(10,50,500,500,500)==true)
			{
				if (rm->decreaseBudget(500)==false)
				{
					rm->increaseResourceLevels(10,50,500,500,500);
					delete newTransport;
					return;
				}
			}else{
			delete newTransport;
			return;
		}
	}
	if (newTransport->getType()=="Road")
		{
			ResourceManager* rm =ResourceManager::instance();
			if (rm->decreaseResourceLevels(10,10,100,100,100)==true)
			{
				if (rm->decreaseBudget(100)==false)
				{
					rm->increaseResourceLevels(10,10,100,100,100);
					delete newTransport;
					return;
				}
			}else{
				delete newTransport;
				return;
			}
		}
	if (newTransport->getType()=="Railway")
		{
			ResourceManager* rm =ResourceManager::instance();
			if (rm->decreaseResourceLevels(10,20,200,200,200)==true)
			{
				if (rm->decreaseBudget(200)==false)
				{
					rm->increaseResourceLevels(10,20,200,200,200);
					delete newTransport;
					return;
				}
			}else {
				delete newTransport;
				return;
			}
		}
	TransportCommand* openCom = new OpenBusiness();
	TransportCommand* closeCom = new CloseBusiness();

	this->transports.push_back(std::make_pair(newTransport, std::make_pair(openCom, closeCom)));
	std::cout << newTransport->getType() << " successfully bulit." <<std::endl;
}

/**
* @brief Removes a law from the list of transports.
*
* First we must see if the transport exists before removing it.
* If it does not exist, display a message to the user indicating that the transport does not exist
* Otherwise, remove the transport
* We first delete the commands(open and close business), ensuring we will not have memeory leaks. 
* Thereafter, we remove the transport
*
* @param l The transport that the user sends in
*/
void TransportDepartment::removeTransport(Transportation* newTransport) 
{
	std::vector<std::pair<Transportation*, std::pair<TransportCommand*, TransportCommand*>>>::iterator it = this->transports.begin();
	for(; it != this->transports.end(); ++it)
	{
		if(it->first == newTransport)
		{
			delete it->second.first;
			delete it->second.second;
			this->transports.erase(it);
			break;
		}
	}
}

/** 
 * @brief Calls the command(openTransport) for every transport inside the list of transports
 * 
 * Iterates through the vector and calls the execute function stored in the command
*/ 
void TransportDepartment::openTransport() 
{
	std::vector<std::pair<Transportation*, std::pair<TransportCommand*, TransportCommand*>>>::iterator it = this->transports.begin();

	for(; it != this->transports.end(); ++it)
	{
		it->second.first->execute(it->first);
	}
}

/** 
 * @brief Calls the command(closeTransport) for every transport inside the list of transports
 * 
 * Iterates through the vector and calls the execute function that calls the command
*/ 
void TransportDepartment::closeTransport() 
{
	std::vector<std::pair<Transportation*, std::pair<TransportCommand*, TransportCommand*>>>::iterator it = this->transports.begin();

	for(; it != this->transports.end(); ++it)
	{
		it->second.second->execute(it->first);
	}
}

/** 
 * @brief Gets the amount of airports currently set within the city
 * 
 * @return The amount of airports currently in this city
*/
int TransportDepartment::getTotalAirports()
{
	int counter=0;
	std::vector<std::pair<Transportation*, std::pair<TransportCommand*, TransportCommand*>>>::iterator it = this->transports.begin();
	for(; it != this->transports.end(); ++it)
	{
		if (it->first->getType()=="Airport")
		{
			counter++;
		}
	}
	return counter;
}

/** 
 * @brief Gets the amount of roads currently set within the city
 * 
 * @return The amount of raods currently in this city
*/
int TransportDepartment::getTotalRoads()
{
	int counter=0;
	std::vector<std::pair<Transportation*, std::pair<TransportCommand*, TransportCommand*>>>::iterator it = this->transports.begin();
	for(; it != this->transports.end(); ++it)
	{
		if (it->first->getType()=="Road")
		{
			counter++;
		}
	}
	return counter;
}

/** 
 * @brief Gets the amount of railways currently set within the city
 * 
 * @return The amount of railways currently in this city
*/
int TransportDepartment::getTotalRailways()
{
	int counter=0;
	std::vector<std::pair<Transportation*, std::pair<TransportCommand*, TransportCommand*>>>::iterator it = this->transports.begin();
	for(; it != this->transports.end(); ++it)
	{
		if (it->first->getType()=="Railway")
		{
			counter++;
		}
	}
	return counter;
}
