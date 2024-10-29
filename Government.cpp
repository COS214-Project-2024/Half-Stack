#include "Government.h"

Government* Government::uniqueInstance;

Government::Government(std::string name) 
{
	this->name = name;
	departments.push_back(ResidentialDepartment::instance());
	departments.push_back(UtilitiesDepartment::instance());
	departments.push_back(TransportDepartment::instance());
	departments.push_back(LawDepartment::instance());
	departments.push_back(TaxDepartment::instance());
	departments.push_back(CityGrowthDepartment::instance());
}

Government* Government::instance(std::string name) 
{
	if(uniqueInstance == nullptr)
	{
		uniqueInstance = new Government(name);
	}

	return uniqueInstance;
}

Government::~Government()
{
	
}
