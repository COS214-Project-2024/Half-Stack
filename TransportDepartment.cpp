#include <iostream>
#include "TransportDepartment.h"

TransportDepartment* TransportDepartment::uniqueInstance;

TransportDepartment::~TransportDepartment()
{
	std::vector<std::pair<Transportation*, std::pair<TransportCommand*, TransportCommand*>>>::iterator it = this->transports.begin();

	for(; it != this->transports.end(); ++it)
	{
		delete it->second.first;
		delete it->second.second;
	}
}

TransportDepartment::TransportDepartment()
{

};

TransportDepartment* TransportDepartment::instance()
{
    if(uniqueInstance == nullptr)
	{
		uniqueInstance = new TransportDepartment();
	}

	return uniqueInstance;
}

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
}

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

void TransportDepartment::openTransport() 
{
	std::vector<std::pair<Transportation*, std::pair<TransportCommand*, TransportCommand*>>>::iterator it = this->transports.begin();

	for(; it != this->transports.end(); ++it)
	{
		it->second.first->execute(it->first);
	}
}

void TransportDepartment::closeTransport() 
{
	std::vector<std::pair<Transportation*, std::pair<TransportCommand*, TransportCommand*>>>::iterator it = this->transports.begin();

	for(; it != this->transports.end(); ++it)
	{
		it->second.second->execute(it->first);
	}
}

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
