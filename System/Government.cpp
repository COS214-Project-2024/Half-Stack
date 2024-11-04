#include "Government.h"
//#include "CityGrowthDepartment.h"
#include <cmath>

Government* Government::uniqueInstance;

/** @brief Constructs the Government object. 
 * 
 * @param name
 * This param is the users name, they own their city so the government should be theirs
 * Sets the different Departments needed in this city with the singleton instances that each class provides. 
 * A message is outputted stating that the user runs this city.
 * The departments can now observe changes, accompany for resources, budgets and more
*/ 
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

/**
 * @brief Gets the Residential Department instance
 * 
 * @return ResidentialDepartment*
 * The Residential Department instance that the class holds
 */
ResidentialDepartment* Government::getResidentialDepartment()
{
	return resDep;
}

/**
 * @brief Gets the Transport Department instance
 * 
 * @return TransportDepartment* 
 * The Transport Department instance that the class holds
 */
TransportDepartment* Government::getTransportDepartment()
{
	return transportDep;
}

/**
 * @brief Gets the Utilities Department instance
 * 
 * @return UtilitiesDepartment*
 * The Utilities Department instance that the class holds
 */
UtilitiesDepartment* Government::getUtilitiesDepartment()
{
	return utilityDep;
}

/**
 * @brief Gets the Public Services Department instance
 * 
 * @return PublicServicesDepartment*
 * The Public Services Department instance that the class holds
 */
PublicServicesDepartment* Government::getPublicServicesDepartment()
{
	return psDep;
}

/**
 * @brief Gets the Law Department instance
 * 
 * @return LawDepartment*
 * The Law Department instance that the class holds
 */
LawDepartment* Government::getLawDepartment()
{
	return lawDep;
}

/**
 * @brief Gets the City Growth Department instance
 * 
 * @return CityGrowthDepartment*
 * The City Growth Department instance that the class holds
 */
CityGrowthDepartment* Government::getCityGrowthDepartment()
{
	return cgDep;
}

/**
 * @brief Gets the Resource Manager instance
 * 
 * @return ResourceManager*
 * The Resource Manager instance that the class holds
 */
ResourceManager* Government::getResourceManager()
{
	return resourceManager;
}

/**
 * @brief Sets the Government singleton instance to ensure that only one instance is created
 * 
 * @return Government**
 * Returns the instance. Now we can use the Government functionality through this instance
 */
Government* Government::instance(std::string name) 
{
	if(uniqueInstance == nullptr)
	{
		uniqueInstance = new Government(name);
	}

	return uniqueInstance;
}

/**
 * @brief Destructs and deallocates any dynamic memory created by the Government class
 * 
 * Clears and deletes all citizens in the Citizen vector. Deletes the instance, effectively cleaning up memory
 */
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

/**
 * @brief This function adds a new ctitizen to the Government accoriding to certain conditions
 * 
 * We first check is the number of homeless citizens exceeds a limit of 20. 
 * If there are too many homless citizens, the new citizen will not be added and the object will be deleted
 * Checks if the citizen does not already exist within the Government
 * If the homeless count is not 20 and its a new citizen, the citizen is added and additional updates are then triggered to the Residential and City Growth departments
 * 
 * @param c Pointer to the object that holds the new citizen to be added
 * 
 * If the number of homeless people exceed 20:
 * - an error message is displayed, c is deleted and we exit
 * If the citizen is already registered:
 * - message is displayed to the user, exits
 * If the citizen is successfully added:
 * - Citizen is added to the list
 * - Resource Department is called to accompany this citizen
 * - City Growth department is called to update the numbers
 * 
 * @note The functions accompanies for memory leaks by deleting the Citizen object if unsuccessful addition occured 
 */
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


/** 
 * @brief Checks whether or not the citizen already exists within the list of citizens
 * 
 * iterates through the vector and checks whether the citizen already exists
 * 
 * @param c Pointer to the citizen object we want to test existance
 * 
 * @return Boolean value of either true or false
 * True if the citizen does exist
 * False if the citizen does not exist
 * 
*/ 
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

/**  
 * @brief Calculates the total number of citizens currently in the list
 * 
 * @return int
 * The cumulative number of citizens within the list
*/ 
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

/**  
 * @brief Calculates the total number of citizens that are unemployed that are currently in the list
 * 
 * @return int
 * The cumulative number of unemployed citizens within the list
*/ 
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

/**  
 * @brief Calculates the total number of employed citizens currently in the list
 * 
 * @return int
 * The cumulative number of employed citizens within the list
*/ 
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

/**
 * @brief Gets the list of citizens currently registered in the system
 * 
 * @return vector<Citizen*> 
 * The vector that holds the citizens registered
 */
std::vector<Citizen*> Government::getCitizens() const 
{
    return citizens;
}

/**  
 * @brief Calculates the total number of homeless citizens currently in the list
 * 
 * @return int
 * The cumulative number of homeless citizens within the list
*/ 
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

/**  
 * @brief Calculates the total number of citizens who's satisfactions are neutral that arecurrently in the list
 * 
 * @return int
 * The cumulative number of neutral citizens within the list
*/ 
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

/**
 * @brief Calculates the total number of citizens who's satisfactions are satisfied that arecurrently in the list
 * 
 * @return int
 * The cumulative number of satisfied citizens within the list
*/ 
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

/**  
 * @brief Calculates the total number of citizens who's satisfactions are unsatisfied that arecurrently in the list
 * 
 * @return int
 * The cumulative number of unsatisfied citizens within the list
*/ 
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

/**
 * @brief Displays the current numbers of the various types of citizens, resource numbers and building types that currently exists within the system
 * 
 * A general overview of the numbers and statistics of your city
 */
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