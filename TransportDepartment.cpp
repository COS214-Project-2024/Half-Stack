#include "TransportDepartment.h"

TransportDepartment &TransportDepartment::instance()
{
    static TransportDepartment instance;
	instance.commands[0] = new OpenBusiness();
	instance.commands[1] = new CloseBusiness();
	return instance;
}

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
