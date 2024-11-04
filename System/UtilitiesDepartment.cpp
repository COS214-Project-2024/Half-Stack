#include "UtilitiesDepartment.h"
#include "Government.h"

UtilitiesDepartment* UtilitiesDepartment::uniqueInstance;

/**
 * @brief Constructor for the UtilitiesDepartment class.
 * (Initialises the necessary commands.)
 */
UtilitiesDepartment::UtilitiesDepartment()
{
	//if (commands==NULL)
	commands[0] = new SupplyWater();
	commands[1] = new SupplyPower();
	commands[2] = new ManageWaste();
	commands[3] = new ManageSewage();
}

/** 
 * @brief Singleton instance of UtilitiesDepartment.
 * @return Pointer to the instance of UtilitiesDepartment.
 */
UtilitiesDepartment* UtilitiesDepartment::instance()
{
	if (uniqueInstance == NULL)
    {
        uniqueInstance = new UtilitiesDepartment();
    }
    return uniqueInstance;
}

/**
 * @brief Destructor for the UtilitiesDepartment class.
 * (Deletes the array of commands.)
 */
UtilitiesDepartment::~UtilitiesDepartment()
{
	for (int i = 0; i < 4; i++)
	{
		delete commands[i];
	}

	for (std::vector<Plant*>::iterator i = plants.begin(); i != plants.end(); i++)
    {
		if ((*i)!=NULL)
		{
			delete *i;
		}
	}
}

/** 
 * @brief Executes all of the commands for the above utility services.
 */
void UtilitiesDepartment::performRoutine()
{
	for (int i = 0; i < 4; i++)
	{
		commands[i]->execute();
	}
}

/** 
 * @brief Responsible for supply water to the city.
 */
void UtilitiesDepartment::supplyWater()
{
	for (std::vector<Plant*>::iterator i = plants.begin(); i != plants.end(); i++)
    {
		if ((*i)->getType()=="Water")
		{
			(*i)->generate();
		}
	}
	std::cout << "The utilities department is supplying water." << std::endl;
}

/** 
 * @brief Responsible for supply energy to the city.
 */
void UtilitiesDepartment::supplyEnergy()
{
	for (std::vector<Plant*>::iterator i = plants.begin(); i != plants.end(); i++)
    {
		if ((*i)->getType()=="Power")
		{
			(*i)->generate();
		}
	}
	std::cout << "The utilities department is supplying power." << std::endl;
}

/** 
 * @brief Responsible for managing waste of the city.
 */
void UtilitiesDepartment::manageWaste()
{
	std::vector<Citizen*> citizens = Government::instance(" ")->getCitizens();
    std::vector<Citizen*>::iterator it = citizens.begin();
    for(; it != citizens.end(); ++it)
    {
    	(*it)->setSatisfaction((*it)->getSatisfaction()->raiseStatus());
    }
	std::cout << "The utilities department is managing waste." << std::endl;
}

/** 
 * @brief Responsible for managing sewage of the city.
 */
void UtilitiesDepartment::manageSewage()
{
	std::cout << "The utilities department is managing sewage." << std::endl;
}

/**
 * @brief Adds a plant to the vector of residential buildings.
 * @param b Pointer to the plant building.
 */
void UtilitiesDepartment::addBuilding(Plant* p)
{
	//int num = b->getCapacity();
    ResourceManager* rm = ResourceManager::instance();
    if (rm->decreaseResourceLevels(0, 0, 50, 50, 30) == true)
	{
		if (rm->decreaseBudget(200)==true)
        {
            plants.push_back(p);
			std::cout << "Plants successfully bulit." <<std::endl;
        }else {
            rm->increaseResourceLevels(0, 0, 50, 50, 30);
			delete p;
        }
	}else {
		delete p;
	}
}

/**
 * @brief loop through plant vector and determine amount of water plants
 * @return amount of water plants
 */
int UtilitiesDepartment::getTotalWaterPlants()
{
	int counter=0;
	for (std::vector<Plant*>::iterator i = plants.begin(); i != plants.end(); i++)
    {
		if ((*i)->getType()=="Water")
		{
			counter++;
		}
	}
	return counter;
}

/**
 * @brief loop through plant vector and determine amount of power plants
 * @return amount of power plants
 */
int UtilitiesDepartment::getTotalPowerPlants()
{
	int counter=0;
	for (std::vector<Plant*>::iterator i = plants.begin(); i != plants.end(); i++)
    {
		if ((*i)->getType()=="Power")
		{
			counter++;
		}
	}
	return counter;
}