#include "LawDepartment.h"

void LawDepartment::addLaw(std::string l) 
{
	this->laws.push_back(l);
}

void LawDepartment::removeLaw(std::string l) 
{
	std::vector<std::string>::iterator it = this->laws.begin();
	bool found = false;

	for(; it != this->laws.end(); ++it)
	{
		if(*it == l)
		{
			found = true;
			this->laws.erase(it);
		}
	}

	if(found == false)
	{
		std::cout << "Law was not found" << std::endl;
	}
}

void LawDepartment::changeLaw(std::string previous, std::string current)
{
	std::vector<std::string>::iterator it = this->laws.begin();
	bool found = false;

	for(; it != this->laws.end(); ++it)
	{
		if(*it == previous)
		{
			found = true;
			*it = current;
		}
	}

	if(found == false)
	{
		std::cout << "Law was not found" << std::endl;
	}
}
