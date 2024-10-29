#include "UtilitiesDepartment.h"

UtilitiesDepartment::UtilitiesDepartment()
{
	commands[0] = new SupplyWater();
	commands[1] = new SupplyPower();
	commands[2] = new ManageWaste();
	commands[3] = new ManageSewage();
}

UtilitiesDepartment::~UtilitiesDepartment()
{
	for (int i = 0; i < 4; i++)
	{
		delete commands[i];
	}
}

void UtilitiesDepartment::performRoutine()
{
	for (int i = 0; i < 4; i++)
	{
		commands[i]->execute();
	}
}

void UtilitiesDepartment::supplyWater()
{
	std::cout << "The utilities department is supplying water." << std::endl;
}

void UtilitiesDepartment::supplyEnergy()
{
	std::cout << "The utilities department is supplying power." << std::endl;
}

void UtilitiesDepartment::manageWaste()
{
	std::cout << "The utilities department is managing waste." << std::endl;
}

void UtilitiesDepartment::manageSewage()
{
	std::cout << "The utilities department is managing sewage." << std::endl;
}
