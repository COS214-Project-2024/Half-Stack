#include "Government.h"
//#include "CityGrowthDepartment.h"
#include <cmath>

Government* Government::uniqueInstance;

Government::Government(std::string name) 
{
	this->name = name;
	resDep = ResidentialDepartment::instance();
	//departments.push_back(resDep);
	transportDep = TransportDepartment::instance();
	//departments.push_back(transportDep);
	utilityDep = UtilitiesDepartment::instance();
	//departments.push_back(utilityDep);
	psDep = PublicServicesDepartment::instance();
	//departments.push_back(psDep);
	lawDep = LawDepartment::instance();
	//departments.push_back(lawDep);
	cgDep = CityGrowthDepartment::instance(this);
	//departments.push_back(cgDep);
	resourceManager = ResourceManager::instance();
	std::cout << name << " runs this city." <<std::endl;
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
	std::vector<Citizen*>::iterator it = citizens.begin();
    for(; it != citizens.end(); ++it)
    {
        if((*it)!=NULL)
        {
            delete (*it);
        }
    }
	delete uniqueInstance;
}


void Government::addCitizen(Citizen* c)
{
	int homeless= getHomeless();
	if (homeless> 20)
	{
		std::cout << "Too many homeless citizens. Cannot increase population. " << std::endl;
		delete c;
		return;
	}
	if (hasCitizen(c)==true)
	{
		std::cout << "Citizen already registered." <<std::endl;
		return;
	}
	citizens.push_back(c);
	resDep->houseNewCitizens();
	cgDep->updatePopulation();
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

int Government::getTotalEmployed()
{
	int total=0;
	std::vector<Citizen*>::iterator it = citizens.begin();
    for(; it != citizens.end(); ++it)
    {
        if((*it)->getEmployment()->getStatus() == "Employed")
        {
            total++;
        }
    }

	return total;
}

std::vector<Citizen*> Government::getCitizens() const 
{
    return citizens;
}

int Government::getHomeless()
{
	int total=0;
	std::vector<Citizen*>::iterator it = citizens.begin();
    for(; it != citizens.end(); ++it)
    {
        if((*it)->getHome()==NULL)
        {
            total++;
        }
    }
	return total;
}

int Government::getTotalNeutral()
{
	int total=0;
	std::vector<Citizen*>::iterator it = citizens.begin();
    for(; it != citizens.end(); ++it)
    {
        if((*it)->getSatisfaction()->getStatus() == "Neutral")
        {
            total++;
        }
    }

	return total;
}
int Government::getTotalSatisfied()
{
	int total=0;
	std::vector<Citizen*>::iterator it = citizens.begin();
    for(; it != citizens.end(); ++it)
    {
        if((*it)->getSatisfaction()->getStatus() == "Satisfied")
        {
            total++;
        }
    }

	return total;
}

int Government::getTotalUnsatisfied()
{
	int total=0;
	std::vector<Citizen*>::iterator it = citizens.begin();
    for(; it != citizens.end(); ++it)
    {
        if((*it)->getSatisfaction()->getStatus() == "Unsatisfied")
        {
            total++;
        }
    }

	return total;
}


void Government::getCityStats()
{
	std::cout << "<<---------------------------- CITY STATS ---------------------------->>" <<std::endl;
	std::cout << "Population: " << cgDep->getPopulation() <<std::endl;
	std::cout << "Homeless: " <<this->getHomeless() <<std::endl;
	std::cout << "Employed: " <<this->getTotalEmployed();
	std::cout << ", Unemployed: " <<this->getTotalUnemployed() <<std::endl;
	std::cout << "Satisfied: " <<getTotalSatisfied() <<", Neutral: " <<getTotalNeutral() << ", Unsatisfied: " <<getTotalUnsatisfied() <<std::endl;
	std::cout << "Budget: " << resourceManager->getBudget() <<std::endl;
	std::cout << "Water: " << resourceManager->getWaterLevel()
              << ", Energy: " << resourceManager->getEnergyLevel() 
              << ", Wood: " << resourceManager->getWood()
              << ", Steel: " << resourceManager->getSteel()
              << ", General Materials: " <<  resourceManager->getGeneralMaterials() << std::endl;
	std::cout << "Residential Buildings: " <<resDep->getTotalBuildings() << " [capacity: " << resDep->getTotalCapacity() << "]" <<std::endl;
	std::cout << "Job Buildings: " <<psDep->getTotalBuildings() << " [capacity: " << psDep->getTotalCapacity() << "]" <<std::endl;
	std::cout << "Airports: " <<transportDep->getTotalAirports() <<", Roads: " <<transportDep->getTotalRoads() <<", Railways: "<<transportDep->getTotalRailways() <<std::endl;
	std::cout << "WaterPlants: " <<utilityDep->getTotalWaterPlants() <<", PowerPlants: " <<utilityDep->getTotalPowerPlants() <<std::endl;
	std::cout << "------------------------------------------------------------------------" <<std::endl;
}