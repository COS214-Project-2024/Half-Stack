#include "Government.h"
//#include "CityGrowthDepartment.h"

Government* Government::uniqueInstance;

Government::Government(std::string name) 
{
	this->name = name;
	resDep = ResidentialDepartment::instance();
	departments.push_back(resDep);
	transportDep = TransportDepartment::instance();
	departments.push_back(transportDep);
	utilityDep = UtilitiesDepartment::instance();
	departments.push_back(utilityDep);
	psDep = PublicServicesDepartment::instance();
	departments.push_back(psDep);
	lawDep = LawDepartment::instance();
	departments.push_back(lawDep);
	cgDep = CityGrowthDepartment::instance(this);
	departments.push_back(cgDep);
	resourceManager = ResourceManager::instance();
}

ResidentialDepartment* Government::getResidentialDepartment()
{
	return resDep;
}
TransportDepartment* Government::getTransportDepartment()
{
	return transportDep;
}
UtilitiesDepartment* Government::getUtilitiesDepartment()
{
	return utilityDep;
}
PublicServicesDepartment* Government::getPublicServicesDepartment()
{
	return psDep;
}
LawDepartment* Government::getLawDepartment()
{
	return lawDep;
}
CityGrowthDepartment* Government::getCityGrowthDepartment()
{
	return cgDep;
}
ResourceManager* Government::getResourceManager()
{
	return resourceManager;
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
	delete uniqueInstance;
}


void Government::addCitizen(Citizen* c)
{
	if (hasCitizen(c)==true)
	{
		return;
	}
	citizens.push_back(c);
}

bool Government::hasCitizen(Citizen* c)
{
	std::vector<Citizen*>::iterator it = citizens.begin();
    for(; it != citizens.end(); ++it)
    {
        if((*it) == c)
        {
            return true;
        }
    }

	return false;
}

int Government::getTotalCitizens()
{
	int total=0;
	std::vector<Citizen*>::iterator it = citizens.begin();
    for(; it != citizens.end(); ++it)
    {
            total++;
    }

	return total;
}

int Government::getTotalUnemployed()
{
	int total=0;
	std::vector<Citizen*>::iterator it = citizens.begin();
    for(; it != citizens.end(); ++it)
    {
        if((*it)->getEmployment()->getStatus() == "Unemployed" && (*it)->getAge()>=18)
        {
            total++;
        }
    }

	return total;
}
