#include "UtilitiesDepartment.h"

UtilitiesDepartment* UtilitiesDepartment::uniqueInstance;

/**
 * @brief Constructor for the UtilitiesDepartment class.
 * (Initialises the necessary commands.)
 */
UtilitiesDepartment::UtilitiesDepartment()
{
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
	std::cout << "The utilities department is supplying water." << std::endl;
}

/** 
 * @brief Responsible for supply energy to the city.
 */
void UtilitiesDepartment::supplyEnergy()
{
	std::cout << "The utilities department is supplying power." << std::endl;
}

/** 
 * @brief Responsible for managing waste of the city.
 */
void UtilitiesDepartment::manageWaste()
{
	std::cout << "The utilities department is managing waste." << std::endl;
}

/** 
 * @brief Responsible for managing sewage of the city.
 */
void UtilitiesDepartment::manageSewage()
{
	std::cout << "The utilities department is managing sewage." << std::endl;
}
