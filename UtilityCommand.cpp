#include "UtilityCommand.h"

void SupplyWater::execute()
{
	UtilitiesDepart->supplyWater();
}

bool SupplyWater::getStatus()
{
	return water>0;
}

void SupplyPower::execute()
{
	UtilitiesDepart->supplyEnergy();
}

bool SupplyPower::getStatus()
{
	return energy>0;
}

void ManageWaste::execute()
{
	UtilitiesDepart->manageWaste();
}

bool ManageWaste::getStatus()
{
	return open;
}

void ManageSewage::execute()
{
	UtilitiesDepart->manageSewage();
}

bool ManageSewage::getStatus()
{
	return open;
}