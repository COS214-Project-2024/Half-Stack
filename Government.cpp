#include "Government.h"

Government* Government::uniqueInstance;

Government::Government(std::string name) 
{
	this->name = name;
}

Government *Government::instance(std::string name) 
{
	if(uniqueInstance == nullptr)
	{
		uniqueInstance = new Government(name);
	}

	return uniqueInstance;
}

Government::~Government()
{
	delete uniqueInstance;
}

Government::Government(Government& g) 
{
	this->name = g.name;
	this->uniqueInstance = g.uniqueInstance;
	std::vector<Department*>::iterator it = g.departmentList.begin();

	for(; it != g.departmentList.end(); ++it)
	{
		this->departmentList.push_back(*it);
	}
}
