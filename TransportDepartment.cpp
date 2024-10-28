#include "TransportDepartment.h"

void TransportDepartment::addTransport(Transportation newTransport) 
{
	this->transports.push_back(&newTransport);
}

void TransportDepartment::removeTransport(Transportation newTransport) 
{
	std::vector<Transportation*>::iterator it = this->transports.begin();
	for(; it != this->transports.end(); ++it)
	{
		if(*it == &newTransport)
		{
			this->transports.erase(it);
		}
	}
}

void TransportDepartment::openTransport() 
{
	for(int j = 0; j < this->transports.size(); j++)
	{
		this->transports[j]->open();
	}
}

void TransportDepartment::closeTransport() 
{
	for(int j = 0; j < this->transports.size(); j++)
	{
		this->transports[j]->close();
	}
}
