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
		}
	}
}

void TransportDepartment::openTransport() 
{
	std::vector<std::pair<Transportation*, std::pair<TransportCommand*, TransportCommand*>>>::iterator it = this->transports.begin();

	for(; it != this->transports.end(); ++it)
	{
		it->second.first->execute();
	}
}

void TransportDepartment::closeTransport() 
{
	std::vector<std::pair<Transportation*, std::pair<TransportCommand*, TransportCommand*>>>::iterator it = this->transports.begin();

	for(; it != this->transports.end(); ++it)
	{
		it->second.second->execute();
	}
}
